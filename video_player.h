#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H
#include "multimedia.h"

class VideoPlayer : public MediaPlayer
{
    Q_OBJECT
public:
    VideoPlayer(QObject* parent = nullptr, MediaLoader* serializer = nullptr);
    ~VideoPlayer() override;

    const QMediaPlayer* getPlayer() const override;
    const Playlist* getPlaylist(const QString&) const override;
    const Playlist* getCurrentPlaylist() const override;
    const MediaData* getCurrentItem() const override;
    QVector<QString> getListOfPlaylists() const override;

    void play() override;
    void pause() override;
    void stop() override;
    void next() override;
    void previous() override;

    void changeVolume(int) override;
    void changeDuration(int) override;

    void setLike() override;
    void setCurrent(const int) override;
    void setPlaylist(Playlist*) override;
    void addPlaylist(const QString&) override;
    void setTracksToPlaylistByName(const QString&, const QStringList&) override;
    void setTracksToCurrentPlaylist(const QStringList&) override;
    void setCurrentPlaylistByName(const QString&) override;
};

#endif // VIDEO_PLAYER_H
