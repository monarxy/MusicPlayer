#ifndef MEDIA_CUTTER_H
#define MEDIA_CUTTER_H
#include <iostream>

extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
}

class MediaCutter
{
public:
    MediaCutter();
    bool trimAudio(const std::string&, const std::string&, int, int);
};

#endif // MEDIA_CUTTER_H
