#include "video_data.h"

VideoData::VideoData(const QString& _path) : Data(_path){}

VideoData::VideoData(const QString& _path, bool _isLiked)  : Data(_path, _isLiked){}

void VideoData::putLike(){
    isLiked = true;
}

void VideoData::deletelike(){
    isLiked = false;
}

bool VideoData::getLikeInfo() const{
    return isLiked;
}

QString VideoData::getPath() const{
    return path;
}
