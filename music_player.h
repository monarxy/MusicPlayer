#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "tracks_loader.h"
#include "multimedia.h"

class MusicPlayer : public MediaPlayer{
    Q_OBJECT
public:

    MusicPlayer(QObject* parent = nullptr, MediaLoader* serializer = nullptr);
    ~MusicPlayer() override;

    QMediaPlayer* getPlayer() const;
    Playlist* getPlaylist(const QString&) const;
    Playlist* getCurrentPlaylist() const;
    MediaData* getCurrentItem() const;
    QVector<QString> getListOfPlaylists() const;

    void play();
    void pause();
    void stop();
    void nextTrack();
    void previousTrack();

    void changeVolume(const int);
    void changeDuration(const int);

    void setLike();
    void setCurrent(const int);
    void setPlaylist(Playlist*);
    void addPlaylist(const QString&);
};


#endif // MUSIC_PLAYER_H
