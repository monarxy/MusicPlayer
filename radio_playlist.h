#ifndef RADIO_PLAYLIST_H
#define RADIO_PLAYLIST_H
#include "IDeleteItemsInPlaylistManagement.h"
#include "IMovementPlaylistManagement.h"
#include "IPlaylistItemsManagement.h"

class RadioPlaylist : IDeleteItemsInPlaylistManagement, IMovementPlaylistManagement, IPlaylistItemsManagement
{
public:
    RadioPlaylist();
    QVector<MediaData*> getListOfItems() const override;
    void setListOfItems(MediaData*) override;
    MediaData* getNextItem(MediaData*) const override;
    MediaData* getPreviousItem(MediaData*) const override;
    void deleteItem(MediaData*) override = 0;
protected:
    QVector<MediaData*> playlist_items;
};

#endif // RADIO_PLAYLIST_H
