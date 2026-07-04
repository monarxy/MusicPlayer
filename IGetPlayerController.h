#ifndef IGETPLAYERCONTROLLER_H
#define IGETPLAYERCONTROLLER_H

#include "multimedia.h"

class IGetPlayerController {
public:
    virtual const MediaPlayer* getPlayer() const = 0;};

#endif // IGETPLAYERCONTROLLER_H
