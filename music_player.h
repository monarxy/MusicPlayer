#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "multimedia.h"


class MusicPlayer : public MediaPlayer {
    Q_OBJECT
public:

    MusicPlayer(QObject* parent = nullptr, MediaLoader* serializer = nullptr);
    ~MusicPlayer() override;

    void setTracksToPlaylistByName(const QString&, const QStringList&) override;
    void setTracksToCurrentPlaylist(const QStringList&) override;
};


#endif // MUSIC_PLAYER_H
