#ifndef IRADIOPLAYLISTCONTROLLER_H
#define IRADIOPLAYLISTCONTROLLER_H
#include <QString>

class IRadioPlaylistController{
public:
    virtual void setPlaylistAndCurrentItemReceive(const int, const int) = 0;
    virtual const QStringList getListOfDefaultPlaylistItems() const = 0;
};

#endif // IRADIOPLAYLISTCONTROLLER_H
