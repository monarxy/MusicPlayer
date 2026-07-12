#ifndef IDELETEITEMSINPLAYLISTMANAGEMENT_H
#define IDELETEITEMSINPLAYLISTMANAGEMENT_H
#include "songs_data.h"

class IDeleteItemsInPlaylistManagement{
public:
    virtual void deleteItem(MediaData*) = 0;
};

#endif // IDELETEITEMSINPLAYLISTMANAGEMENT_H
