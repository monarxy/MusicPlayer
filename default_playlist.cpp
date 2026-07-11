#include "default_playlist.h"

DefaultPlaylist::DefaultPlaylist() : Playlist() {}

DefaultPlaylist::DefaultPlaylist(const QString& name) : Playlist(name) {}

void DefaultPlaylist::deleteItem(MediaData* item){
    int counter = 0;
    for (auto it = playlist_items.begin(); it != playlist_items.end();){
        if (*it == item){
            MediaData* tmp_ptr = *it;
            playlist_items.erase(it);
            delete tmp_ptr;
            q_playlist->removeMedia(counter);
            return;
        }
        ++counter;
        ++it;
    }
}
