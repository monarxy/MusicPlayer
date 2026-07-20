#include "media_data.h"

MediaData::MediaData(const QString& _path) : Data(_path), image() {}

MediaData::MediaData(const QString& _path, bool _isLiked, const QPixmap& _image) : Data(_path, _isLiked), image(_image){}

QPixmap MediaData::getPicture() const{
    return image;
}
