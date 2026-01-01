#include "songs_data.h"

SongData::SongData(const QString& _path){
    isLiked = false;
    path = _path;
}

SongData::SongData(const QString& _path, bool _isLiked){
    isLiked = _isLiked;
    path = _path;
}

void SongData::putLike(){
    isLiked = true;
}

void SongData::deletelike(){
    isLiked = false;
}

bool SongData::getLikeInfo() const{
    return isLiked;
}

QString SongData::getPath() const{
    return path;
}




