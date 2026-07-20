#ifndef MEDIA_DATA_H
#define MEDIA_DATA_H
#include "data.h"

class MediaData : public Data
{
    QPixmap image;
public:
    MediaData(const QString&);
    MediaData(const QString&, bool, const QPixmap& );
    QPixmap getPicture() const;
};

#endif // MEDIA_DATA_H
