#ifndef IGETRADIOPLAYERCONTROLLER_H
#define IGETRADIOPLAYERCONTROLLER_H

#include "radio.h"

class IGetRadioPlayerController {
public:
    virtual const RadioPlayer* getPlayer() const = 0;
};

#endif // IGETRADIOPLAYERCONTROLLER_H
