#include "video_data.h"

VideoData::VideoData(const QString& _path) : MediaData(_path){}

VideoData::VideoData(const QString& _path, bool _isLiked)  : MediaData(_path, _isLiked){}

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
