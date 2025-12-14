#ifndef TRACKS_LOADER_H
#define TRACKS_LOADER_H
#include "media_loader.h"

class TracksLoader : public MediaLoader{
public:
    TracksLoader();
    QVector<Playlist*> loadSavedTracks();
    void saveTracks(std::map<QString, Playlist*>);
};


#endif // TRACKS_LOADER_H
