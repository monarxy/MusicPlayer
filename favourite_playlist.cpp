#include "favourite_playlist.h"

FavouritePlaylist::FavouritePlaylist() : Playlist() {}

void FavouritePlaylist::deleteItem(MediaData* item){
    item->deletelike();
    int counter = 0;
    for (auto it = playlist_items.begin(); it != playlist_items.end();){
        if (*it == item){
            playlist_items.erase(it);
            q_playlist->removeMedia(counter);

            return;
        }
        ++counter;
        ++it;
    }
}


