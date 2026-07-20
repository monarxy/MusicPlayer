#ifndef RADIO_FAVOURITE_PLAYLIST_H
#define RADIO_FAVOURITE_PLAYLIST_H
#include "radio_playlist.h"


class RadioFavouritePlaylist : public RadioPlaylist
{
public:
    RadioFavouritePlaylist();
    void deleteItem(RadioData*) override;
};

#endif // RADIO_FAVOURITE_PLAYLIST_H
