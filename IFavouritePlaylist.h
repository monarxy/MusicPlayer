#ifndef IFAVOURITEPLAYLIST_H
#define IFAVOURITEPLAYLIST_H
#include "playlist.h"

template <typename T>
class IFavouritePlaylist {
public:

    virtual void setFavouritePlaylistAsMain() = 0;
    virtual const T* getFavouritePlaylist() const = 0;
};

#endif // IFAVOURITEPLAYLIST_H
