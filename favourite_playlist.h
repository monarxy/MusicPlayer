#ifndef FAVOURITE_PLAYLIST_H
#define FAVOURITE_PLAYLIST_H
#include "playlist.h"

class FavouritePlaylist : public Playlist
{
public:
    FavouritePlaylist();
    void deleteItem(MediaData*) override final;
};

#endif // FAVOURITE_PLAYLIST_H
