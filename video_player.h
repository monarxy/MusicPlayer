#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H
#include "multimedia.h"
#include <QtMultimediaWidgets/QVideoWidget>

class VideoPlayer : public MediaPlayer
{
    Q_OBJECT
public:
    VideoPlayer(QObject* parent = nullptr, MediaLoader* serializer = nullptr);
    ~VideoPlayer() override;

    void setTracksToPlaylistByName(const QString&, const QStringList&) override;
    void setTracksToCurrentPlaylist(const QStringList&) override;
    void setVideoOutput(QVideoWidget*);
};

#endif // VIDEO_PLAYER_H
