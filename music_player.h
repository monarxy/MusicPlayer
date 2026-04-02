#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "tracks_loader.h"
#include "multimedia.h"
#include "ISerializable.h"

class MusicPlayer : public MediaPlayer, public ISerializable {
    Q_OBJECT
public:

    MusicPlayer(QObject* parent = nullptr, MediaLoader* serializer = nullptr);
    ~MusicPlayer() override;

    const QMediaPlayer* getPlayer() const override;
    const Playlist* getPlaylist(const QString&) const override;
    const Playlist* getCurrentPlaylist() const override;
    const MediaData* getCurrentItem() const override;
    QVector<QString> getListOfPlaylists() const override;

    void play() override;
    void pause() override;
    void stop() override;
    void next() override;
    void previous()override ;

    void changeVolume(const int) override;
    void changeDuration(const int) override;

    void setLike() override;
    void setCurrent(const int) override;
    void setPlaylist(Playlist*) override;
    void addPlaylist(const QString&) override;
    void setTracksToPlaylistByName(const QString&, const QStringList&) override;
    void setTracksToCurrentPlaylist(const QStringList&) override;
    void setCurrentPlaylistByName(const QString&) override;

    void load() override;
    void save() override;
};


#endif // MUSIC_PLAYER_H
