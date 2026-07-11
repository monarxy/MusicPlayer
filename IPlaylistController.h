#ifndef IPLAYLISTCONTROLLER_H
#define IPLAYLISTCONTROLLER_H
#include <QStringList>;

class IPlaylistController{
public:
    virtual void setItemsToPlayer(const QStringList&) = 0;
    virtual void setListOfPlaylistsItemsReceive(const QString&) = 0;
    virtual void setListOfFavouritePlaylistItemsReceive() = 0;
    virtual void setPlaylistAndCurrentItemReceive(const int, const QString&, const int) = 0;
    virtual QStringList getListOfPlaylistItems(const QString&) const = 0;
    virtual void getPlaylistNamesReceive() = 0;
    virtual QStringList getListOfFavouritePlaylistItems() const = 0;
    virtual void addNewPlaylist(const QString&) = 0;
    virtual void addItemsToPlaylist(const QString&, const QStringList&) = 0;
    virtual void deletePlaylistReceive(const QString&) = 0;
};

#endif // IPLAYLISTCONTROLLER_H
