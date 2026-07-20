#ifndef IFEWPLAYERSCONTROLLER_H
#define IFEWPLAYERSCONTROLLER_H
#include <QVector>
#include "multimedia.h"

class IFewPlayersController{
public:
    virtual void setCurrentPlayerByIndex(const int) = 0;
    virtual const QVector<MediaPlayer*> getListOfPlayers() const = 0;
};
#endif // IFEWPLAYERSCONTROLLER_H
