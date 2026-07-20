#include "radio_playlist.h"

RadioPlaylist::RadioPlaylist() {}

void RadioPlaylist::setListOfItems(RadioData* item){
    playlist_items.push_back(item);
}

QVector<RadioData*> RadioPlaylist::getListOfItems() const{
    return playlist_items;
}

RadioData* RadioPlaylist::getPreviousItem(RadioData* item) const{
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

RadioData* RadioPlaylist::getNextItem(RadioData* item) const{
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
