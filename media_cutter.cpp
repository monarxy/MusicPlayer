#include "media_cutter.h"

MediaCutter::MediaCutter() {}

bool MediaCutter::trimAudio(const std::string& inputFile,
               const std::string& outputFile,
               int startSeconds,
               int endSeconds) {

    avformat_network_init();

    AVFormatContext* input_ctx = nullptr;
    AVFormatContext* output_ctx = nullptr;

    // Открываем входной файл
    if (avformat_open_input(&input_ctx, inputFile.c_str(), nullptr, nullptr) < 0) {
        std::cerr << "Cannot open input file" << std::endl;
        return false;
    }

    if (avformat_find_stream_info(input_ctx, nullptr) < 0) {
        std::cerr << "Cannot find stream info" << std::endl;
        avformat_close_input(&input_ctx);
        return false;
    }

    // Находим аудио поток
    int audio_stream_index = -1;
    for (unsigned int i = 0; i < input_ctx->nb_streams; i++) {
        if (input_ctx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
            audio_stream_index = i;
            break;
        }
    }

    if (audio_stream_index == -1) {
        std::cerr << "No audio stream found" << std::endl;
        avformat_close_input(&input_ctx);
        return false;
    }

    // Создаем выходной контекст
    if (avformat_alloc_output_context2(&output_ctx, nullptr, nullptr, outputFile.c_str()) < 0) {
        std::cerr << "Cannot create output context" << std::endl;
        avformat_close_input(&input_ctx);
        return false;
    }

    // Копируем поток
    AVStream* out_stream = avformat_new_stream(output_ctx, nullptr);
    AVStream* in_stream = input_ctx->streams[audio_stream_index];
    avcodec_parameters_copy(out_stream->codecpar, in_stream->codecpar);
    out_stream->time_base = in_stream->time_base;

    // Открываем выходной файл
    if (avio_open(&output_ctx->pb, outputFile.c_str(), AVIO_FLAG_WRITE) < 0) {
        std::cerr << "Cannot open output file" << std::endl;
        avformat_free_context(output_ctx);
        avformat_close_input(&input_ctx);
        return false;
    }

    // Пишем заголовок
    if (avformat_write_header(output_ctx, nullptr) < 0) {
        std::cerr << "Cannot write header" << std::endl;
        avio_closep(&output_ctx->pb);
        avformat_free_context(output_ctx);
        avformat_close_input(&input_ctx);
        return false;
    }

    // Вычисляем PTS для обрезки
    int64_t start_pts = av_rescale_q(startSeconds * AV_TIME_BASE,
                                     AV_TIME_BASE_Q,
                                     in_stream->time_base);
    int64_t end_pts = av_rescale_q(endSeconds * AV_TIME_BASE,
                                   AV_TIME_BASE_Q,
                                   in_stream->time_base);

    // Перематываем
    if (av_seek_frame(input_ctx, audio_stream_index, start_pts, AVSEEK_FLAG_BACKWARD) < 0) {
        std::cerr << "Cannot seek" << std::endl;
        avio_closep(&output_ctx->pb);
        avformat_free_context(output_ctx);
        avformat_close_input(&input_ctx);
        return false;
    }

    AVPacket packet;
    bool success = true;

    while (av_read_frame(input_ctx, &packet) >= 0) {
        if (packet.stream_index == audio_stream_index) {
            if (packet.pts > end_pts) {
                break;
            }

            packet.pts -= start_pts;
            packet.dts -= start_pts;
            packet.duration = av_rescale_q(packet.duration,
                                           in_stream->time_base,
                                           out_stream->time_base);
            packet.pos = -1;
            packet.stream_index = 0;

            if (av_interleaved_write_frame(output_ctx, &packet) < 0) {
                std::cerr << "Error writing frame" << std::endl;
                success = false;
                break;
            }
        }
        av_packet_unref(&packet);
    }

    av_write_trailer(output_ctx);

    // Очистка
    avio_closep(&output_ctx->pb);
    avformat_free_context(output_ctx);
    avformat_close_input(&input_ctx);
    avformat_network_deinit();

    if (success) {
        std::cout << "Audio trimmed successfully!" << std::endl;
    }

    return success;
}
