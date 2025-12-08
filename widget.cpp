#include "widget.h"
#include "multimedia.h"
#include "music_player.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDir>
#include "bass.h"
#include <iostream>


extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
}

Widget::Widget() : ui(new Ui::Widget){
    ui->setupUi(this);
    m_playListModel = new QStandardItemModel(this);
    ui->playlistView->setModel(m_playListModel);
    m_playListModel->setHorizontalHeaderLabels(QStringList()  << tr("Audio Track") << tr("File Path"));
    ui->playlistView->hideColumn(1);
    ui->playlistView->verticalHeader()->setVisible(false);
    ui->playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->playlistView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->playlistView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->playlistView->horizontalHeader()->setStretchLastSection(true);
}

Widget::~Widget()
{
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    QStringList pathes_of_tracks;
    // foreach (MediaData* item , *(data_controller->getPlayer()->getPlaylist()->getListOfItems()))
    //     pathes_of_tracks.push_back(item->getPath());
    // settings.setValue("List_of_pathes", pathes_of_tracks);
    delete ui;
}

void Widget::on_btn__clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this, tr("Open files"), QString(), tr("Audio Files (*.mp3)"));
    foreach (QString filePath, files) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(QDir(filePath).dirName()));
        items.append(new QStandardItem(filePath));
        m_playListModel->appendRow(items);
    }
}

void Widget::position_changed(qint64 index){
    ui->horizontalSlider->setValue(index/1000);
}

void Widget::duration_changed(qint64 duration){
    ui->horizontalSlider->setMaximum(duration/1000);
}


void Widget::on_btn_play_clicked()
{
    emit PlayClicked();
}


void Widget::on_tabWidget_currentChanged(int index)
{

}


void Widget::on_toolButton_2_clicked()
{

}



void Widget::on_playlistView_clicked(const QModelIndex &index)
{
    //QString s = QString::number(index.row());
    emit PlaylistViewClicked(index.row());
    //ui->label->setText(m_playListModel->item(index.row(), 1)->data(Qt::DisplayRole).toString());
    //player->getPlaylist()->setCurrentIndex(index.row());

    // data_controller->getPlayer()->setCurrent(index.row());
    // if (data_controller->getPlayer()->getCurrentItem()->getLikeInfo()) ui->label->setText("1");
    // else ui->label->setText("0");
}


void Widget::on_horizontalSlider_valueChanged(int value)
{

}


void Widget::on_verticalSlider_actionTriggered(int action)
{
     //data_controller->getPlayer()->changeVolume(action);
}


void Widget::on_horizontalSlider_sliderMoved(int position)
{

}


void Widget::on_likeButton_clicked()
{

}


void Widget::on_pushButton_clicked()
{
    emit PlaylistFormClicked();
}

void Widget::setPlaylist(QStringList list_of_tracks, QString album_name){
    ui->album_name_label->setText(album_name);
    m_playListModel->clear();
    foreach (QString item, list_of_tracks){
         QList<QStandardItem *> items;
         items.append(new QStandardItem(item));
         m_playListModel->appendRow(items);
         //data_controller->getPlayer()->getQPlaylist()->addMedia(QUrl(item->getPath()));
    }
}

bool trimAudio(const std::string& inputFile,
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


void Widget::on_pushButton_2_clicked()
{
    // BASS_Init(-1, 44100, BASS_DEVICE_3D, 0, NULL);
    // HSTREAM str = BASS_StreamCreateURL("http://dorognoe.hostingradio.ru:8000/radio", 0, 0, NULL, 0);
    // BASS_ChannelPlay(str, false);
    // BASS_ChannelStop(str);
    // SimpleAudioTrimmer *trimmer = new SimpleAudioTrimmer();
    trimAudio("C:/Users/Rom/Documents/untitled1/huun_huurtu.mp3", "C:/Users/Rom/Documents/untitled1/huun_huurt.mp3", 10, 40);
}






void Widget::on_editorButton_clicked()
{
    emit EditorFormClicked();
}

