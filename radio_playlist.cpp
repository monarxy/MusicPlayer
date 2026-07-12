#include "radio_playlist.h"

RadioPlaylist::RadioPlaylist() {}

void RadioPlaylist::setListOfItems(MediaData* item){
    playlist_items.push_back(item);
}

QVector<MediaData*> RadioPlaylist::getListOfItems() const{
    return playlist_items;
}

MediaData* RadioPlaylist::getPreviousItem(MediaData* item) const{
    for (auto it = playlist_items.begin(); it != playlist_items.end();){
        if (*it == item)
            if (it != playlist_items.begin()){
                --it;
                return *it;
            }
            else return nullptr;
        ++it;
    }
    return nullptr;
}

MediaData* RadioPlaylist::getNextItem(MediaData* item) const{
    for (auto it = playlist_items.begin(); it != playlist_items.end();){
        if (*it == item){
            if (++it != playlist_items.end())
                return *it;
            else return nullptr;
        }
        ++it;
    }
    return nullptr;
}
