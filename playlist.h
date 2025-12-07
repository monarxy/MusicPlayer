#ifndef PLAYLIST_H
#define PLAYLIST_H


#include "media_data.h"
#include <vector>

class Playlist{
public:
    Playlist();
    Playlist(QString);

    std::vector<MediaData*> getListOfItems();
    QString getName();
    void setListOfItems(MediaData*);
protected:
    QString playlist_name;
    std::vector<MediaData*> playlist_items;
};

#endif // PLAYLIST_H
