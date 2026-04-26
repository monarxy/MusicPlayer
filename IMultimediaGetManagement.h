#ifndef IMULTIMEDIAGETMANAGEMENT_H
#define IMULTIMEDIAGETMANAGEMENT_H
#include "media_data.h"
#include "playlist.h"

class IMultimediaGetManagement {
public:

    virtual const QMediaPlayer* getPlayer() const = 0;
    virtual const MediaData* getCurrentItem() const = 0;
    virtual ~IMultimediaGetManagement() = default;
};

#endif // IMULTIMEDIAGETMANAGEMENT_H
