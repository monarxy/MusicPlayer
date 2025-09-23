#include "songs_data.h"

//class MediaData;

SongData::SongData(QString _path){
    isLiked = false;
    path = _path;
}

void SongData::putLike(){
    isLiked = true;
}

void SongData::deletelike(){
    isLiked = false;
}

bool SongData::getLikeInfo(){
    return isLiked;
}
bool SongData::operator==(const SongData& another_data) const{
    return path == another_data.path;
}

QString SongData::getPath(){
    return path;
}


