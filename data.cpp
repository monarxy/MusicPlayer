#include "data.h"

Data::Data(const QString& _path) : path(_path), isLiked(false) {}

Data::Data(const QString& _path, bool _isLiked) : path(_path), isLiked(_isLiked){}

void Data::putLike(){
    isLiked = true;
}

void Data::deletelike(){
    isLiked = false;
}

bool Data::getLikeInfo() const{
    return isLiked;
}

QString Data::getPath() const{
    return path;
}

