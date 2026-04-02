#ifndef TRACKS_LOADER_H
#define TRACKS_LOADER_H
#include "media_loader.h"

class TracksLoader : public MediaLoader{
public:
    TracksLoader();
    QVector<Playlist*> loadSavedItems() const override;
    void saveItems(const std::map<QString, Playlist*>&) const override;
};


#endif // TRACKS_LOADER_H
