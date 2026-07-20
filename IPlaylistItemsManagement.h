#ifndef IPLAYLISTITEMSMANAGEMENT_H
#define IPLAYLISTITEMSMANAGEMENT_H
#include <QVector>

template<typename T>
class IPlaylistItemsManagement{
    virtual void setListOfItems(T*) = 0;
    virtual QVector<T*> getListOfItems() const = 0;
};

#endif // IPLAYLISTITEMSMANAGEMENT_H
