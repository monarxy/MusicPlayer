#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "multimedia.h"


class MusicPlayer : public MediaPlayer {
    Q_OBJECT
public:

    MusicPlayer(QObject* parent = nullptr, MediaLoader* serializer = nullptr);
    ~MusicPlayer() override;

    void load() override final;
    void save() override final;
};


#endif // MUSIC_PLAYER_H
