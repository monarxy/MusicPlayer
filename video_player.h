#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H
#include "multimedia.h"
#include <QtMultimediaWidgets/QVideoWidget>

class VideoPlayer : public MediaPlayer
{
public:
    VideoPlayer(MediaLoader* serializer);
    ~VideoPlayer() override;

    void load() override final;
    void save() override final;
    void setVideoOutput(QVideoWidget*);
};

#endif // VIDEO_PLAYER_H
