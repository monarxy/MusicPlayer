#ifndef DEFAULT_PLAYLIST_H
#define DEFAULT_PLAYLIST_H
#include "playlist.h"

class DefaultPlaylist : public Playlist
{
public:
    DefaultPlaylist();
    DefaultPlaylist(const QString&);
    void deleteItem(MediaData*) override final;
};

#endif // DEFAULT_PLAYLIST_H
