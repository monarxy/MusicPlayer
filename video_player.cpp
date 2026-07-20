#include "video_player.h"

VideoPlayer::VideoPlayer(QObject *parent, MediaLoader* _serializer) : MediaPlayer(parent, _serializer){
}


void VideoPlayer::load(){
    QVector<Playlist*> loaded_playlists = serializer->loadSavedItems("video_player");
    if (loaded_playlists.size() != 0){
        for (Playlist* playlist : loaded_playlists)
            list_of_playlists[playlist->getName()] = playlist;
        auto it = std::next(list_of_playlists.begin(), 0);
        if (it != list_of_playlists.end())
            playlist = it->second;
        m_player->setPlaylist(playlist->getQPlaylist());
    }
    for (const auto& [key, value] : list_of_playlists)
        for (MediaData* item : value->getListOfItems())
            if (item->getLikeInfo())
                favourite_playlist->setListOfItems(item);

}

void VideoPlayer::save(){
    serializer->saveItems(list_of_playlists, "video_player");
}

void VideoPlayer::setVideoOutput(QVideoWidget* video_widget){
    m_player->setVideoOutput(video_widget);
}

VideoPlayer::~VideoPlayer()
{
    save();
    delete serializer;
}
