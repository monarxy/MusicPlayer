#ifndef IDEFAULTPLAYLIST_H
#define IDEFAULTPLAYLIST_H
#include "radio_playlist.h"

template <typename T>
class IDefaultPlaylist {
public:
    virtual void setDefaultPlaylistAsMain() = 0;
    virtual const T* getDefaultPlaylist() const = 0;
};
#endif // IDEFAULTPLAYLIST_H
