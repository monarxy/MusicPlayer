#ifndef VIDEO_LOADER_H
#define VIDEO_LOADER_H
#include "media_loader.h"

class VideoLoader : public MediaLoader{
public:
    VideoLoader();
    QVector<Playlist*> loadSavedItems() const override;
    void saveItems(const std::map<QString, Playlist*>&) const override;
};


#endif // VIDEO_LOADER_H
