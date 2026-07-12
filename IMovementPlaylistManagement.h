#ifndef IMOVEMENTPLAYLISTMANAGEMENT_H
#define IMOVEMENTPLAYLISTMANAGEMENT_H
#include "media_data.h"

class IMovementPlaylistManagement{
public:
    virtual MediaData* getNextItem(MediaData*) const = 0;
    virtual MediaData* getPreviousItem(MediaData*) const = 0;
};

#endif // IMOVEMENTPLAYLISTMANAGEMENT_H
