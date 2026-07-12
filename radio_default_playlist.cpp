#include "radio_default_playlist.h"

RadioDefaultPlaylist::RadioDefaultPlaylist() : RadioPlaylist() {}

void RadioDefaultPlaylist::deleteItem(MediaData* item){
    int counter = 0;
    for (auto it = playlist_items.begin(); it != playlist_items.end();){
        if (*it == item){
            MediaData* tmp_ptr = *it;
            playlist_items.erase(it);
            delete tmp_ptr;
            return;
        }
        ++counter;
        ++it;
    }
}
