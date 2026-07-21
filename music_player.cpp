#include "music_player.h"

MusicPlayer::MusicPlayer(MediaLoader* _serializer) : MediaPlayer(_serializer){}

MusicPlayer::~MusicPlayer()
{
    save();
    delete favourite_playlist;
    for (const auto& pair : list_of_playlists)
        delete pair.second;
}

void MusicPlayer::load(){
    QVector<Playlist*> loaded_playlists = serializer->loadSavedItems("player");
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

void MusicPlayer::save(){
    serializer->saveItems(list_of_playlists, "player");
}

