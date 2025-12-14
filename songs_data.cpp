#include "songs_data.h"

SongData::SongData(QString _path){
    isLiked = false;
    path = _path;
}

SongData::SongData(QString _path, bool _isLiked){
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
bool SongData::operator==(const SongData& another_data) const{
    return path == another_data.path;
}

QString SongData::getPath() const{
    return path;
}




