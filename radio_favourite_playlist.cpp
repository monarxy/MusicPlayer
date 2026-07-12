#include "radio_favourite_playlist.h"

RadioFavouritePlaylist::RadioFavouritePlaylist() : RadioPlaylist() {}

void RadioFavouritePlaylist::deleteItem(MediaData* item){
    item->deletelike();
    int counter = 0;
    for (auto it = playlist_items.begin(); it != playlist_items.end();){
        if (*it == item){
            playlist_items.erase(it);
            return;
        }
        ++counter;
        ++it;
    }
}
