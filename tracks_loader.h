#ifndef TRACKS_LOADER_H
#define TRACKS_LOADER_H
#include "media_loader.h"

class TracksLoader : MediaLoader{
public:
    TracksLoader();
    QStringList loadSavedTracks();
};


#endif // TRACKS_LOADER_H
