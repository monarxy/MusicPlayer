#ifndef RADIO_DEFAULT_PLAYLIST_H
#define RADIO_DEFAULT_PLAYLIST_H
#include "radio_playlist.h"

class RadioDefaultPlaylist : public RadioPlaylist
{
public:
    RadioDefaultPlaylist();
    void deleteItem(RadioData*) override;
};

#endif // RADIO_DEFAULT_PLAYLIST_H
