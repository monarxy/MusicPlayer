#ifndef IFAVOURITEPLAYLIST_H
#define IFAVOURITEPLAYLIST_H
#include "playlist.h"

class IFavouritePlaylist {
public:

    virtual void setFavouritePlaylistAsMain() = 0;
    virtual const Playlist* getFavouritePlaylist() const = 0;
};

#endif // IFAVOURITEPLAYLIST_H
