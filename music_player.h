#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "multimedia.h"


class MusicPlayer : public MediaPlayer {
public:

    MusicPlayer(MediaLoader* serializer);
    ~MusicPlayer() override;

    void load() override final;
    void save() override final;
};


#endif // MUSIC_PLAYER_H
