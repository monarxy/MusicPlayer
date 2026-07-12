#ifndef IPLAYLISTITEMSMANAGEMENT_H
#define IPLAYLISTITEMSMANAGEMENT_H
#include "media_data.h"


class IPlaylistItemsManagement{
    virtual void setListOfItems(MediaData*) = 0;
    virtual QVector<MediaData*> getListOfItems() const = 0;
};

#endif // IPLAYLISTITEMSMANAGEMENT_H
