#include "video_player.h"
#include <QDebug>

VideoPlayer::VideoPlayer(QObject *parent, MediaLoader* _serializer) : MediaPlayer(parent, _serializer){
}


void VideoPlayer::setTracksToPlaylistByName(const QString& album_name, const QStringList& list_of_tracks){
    auto it = list_of_playlists.find(album_name);
    Playlist* playlist = (it != list_of_playlists.end()) ? it->second : nullptr;
    for (const QString& item : list_of_tracks)
        playlist->setListOfItems(new VideoData(item, false));

}

void VideoPlayer::setTracksToCurrentPlaylist(const QStringList& list_of_tracks){
    for (const QString& item : list_of_tracks)
        playlist->setListOfItems(new VideoData(item, false));

}

void VideoPlayer::setVideoOutput(QVideoWidget* video_widget){
    m_player->setVideoOutput(video_widget);
}

VideoPlayer::~VideoPlayer()
{

}
