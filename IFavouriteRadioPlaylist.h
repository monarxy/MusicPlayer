#ifndef IFAVOURITERADIOPLAYLIST_H
#define IFAVOURITERADIOPLAYLIST_H
#include "radio_playlist.h"

class IFavouriteRadioPlaylist {
public:
    virtual void setDefaultPlaylistAsMain() = 0;
    virtual void setFavouritePlaylistAsMain() = 0;
    virtual const RadioPlaylist* getFavouritePlaylist() const = 0;
    virtual const RadioPlaylist* getDefaultPlaylist() const = 0;
};
#endif // IFAVOURITERADIOPLAYLIST_H
