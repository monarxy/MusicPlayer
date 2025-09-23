#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H
#include "multimedia.h"

class VideoPlayer: public MediaPlayer{
public:
    VideoPlayer();
    void play();
    void pause();
    void stop();
}
#endif // VIDEO_PLAYER_H
