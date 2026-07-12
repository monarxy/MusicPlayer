#include "media_data.h"

MediaData::MediaData(const QString& _path) { path = _path; isLiked = false;}

MediaData::MediaData(const QString& _path, bool _isLiked){path = _path; isLiked = _isLiked;}

void MediaData::putLike(){
    isLiked = true;
}

void MediaData::deletelike(){
    isLiked = false;
}

bool MediaData::getLikeInfo() const{
    return isLiked;
}

QString MediaData::getPath() const{
    return path;
}
