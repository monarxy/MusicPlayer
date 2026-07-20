#ifndef RADIO_PLAYLIST_H
#define RADIO_PLAYLIST_H
#include "IDeleteItemsInPlaylistManagement.h"
#include "IMovementPlaylistManagement.h"
#include "IPlaylistItemsManagement.h"
#include "radio_data.h"


class RadioPlaylist : public IDeleteItemsInPlaylistManagement<RadioData>, public IMovementPlaylistManagement<RadioData>, public IPlaylistItemsManagement<RadioData>
{
public:
    RadioPlaylist();
    QVector<RadioData*> getListOfItems() const override;
    void setListOfItems(RadioData*) override;
    RadioData* getNextItem(RadioData*) const override;
    RadioData* getPreviousItem(RadioData*) const override;
    void deleteItem(RadioData*) override = 0;
protected:
    QVector<RadioData*> playlist_items;
};

#endif // RADIO_PLAYLIST_H
