#ifndef IPLAYERCONTROLLER_H
#define IPLAYERCONTROLLER_H
#include "multimedia.h"


class IPlayerController {
public:
    virtual void playReceive() = 0;
    virtual void pauseReceive() = 0;
    virtual void stopReceive() = 0;
    virtual void nextReceive() = 0;
    virtual void previousReceive()=0;
    virtual void setCurrentItemByIndex(const int) = 0;
    virtual void loadSavedItemsReceive(const QString&) = 0;
    virtual ~IPlayerController() = default;
};

#endif // IPLAYERCONTROLLER_H
