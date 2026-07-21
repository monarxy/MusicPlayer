#include "video_player.h"

VideoPlayer::VideoPlayer(MediaLoader* _serializer) : MediaPlayer(_serializer){
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
    else{
        list_of_playlists[""] = new DefaultPlaylist();
        playlist = list_of_playlists[""];
        m_player->setPlaylist(playlist->getQPlaylist());
        return;
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
    delete favourite_playlist;
    for (const auto& pair : list_of_playlists)
        delete pair.second;

}
