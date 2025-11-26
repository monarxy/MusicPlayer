#ifndef DATA_CONTROLLER_H
#define DATA_CONTROLLER_H
#include "music_player.h"


class DataController{
    MediaPlayer *music_player;
public:
    DataController();
    void setMusicPlayer(QStringList list_of_tracks);
    MediaPlayer* getPlayer();
};
#endif // DATA_CONTROLLER_H
