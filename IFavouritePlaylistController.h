#ifndef IFAVOURITEPLAYLISTCONTROLLER_H
#define IFAVOURITEPLAYLISTCONTROLLER_H
#include <QStringList>;

class IFavouritePlaylistController{
public:
    virtual void setListOfFavouritePlaylistItemsReceive() = 0;
    virtual const QStringList getListOfFavouritePlaylistItems() const = 0;
};

#endif // IFAVOURITEPLAYLISTCONTROLLER_H
