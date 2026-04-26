#ifndef IFEWPLAYERSCONTROLLER_H
#define IFEWPLAYERSCONTROLLER_H

class IFewPlayersController{
public:
    virtual void setCurrentPlayerByIndex(const int) = 0;
    virtual void setMapOfPlayers(const QString&, MediaPlayer*) = 0;
    virtual void setMainPlayerByName(const QString&) = 0;
};
#endif // IFEWPLAYERSCONTROLLER_H
