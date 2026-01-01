#include "video_data.h"

VideoData::VideoData(const QString& _path){
    isLiked = false;
    path = _path;
}

VideoData::VideoData(const QString& _path, bool _isLiked){
    isLiked = _isLiked;
    path = _path;
}

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
