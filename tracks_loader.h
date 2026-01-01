#ifndef TRACKS_LOADER_H
#define TRACKS_LOADER_H
#include "media_loader.h"

class TracksLoader : public MediaLoader{
public:
    TracksLoader();
    QVector<Playlist*> loadSavedTracks() const;
    void saveTracks(const std::map<QString, Playlist*>&) const;
};


#endif // TRACKS_LOADER_H
