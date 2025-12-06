#include "playlist.h"

Playlist::Playlist(QString _name){
    playlist_name = _name;
}

Playlist::Playlist(){
    playlist_name = "";
}

std::vector<MediaData*>* Playlist::getListOfItems(){
    return &playlist_items;
}

void Playlist::setListOfItems(MediaData* item){
    playlist_items.push_back(item);
}

QString Playlist::getName(){
    return playlist_name;
}
