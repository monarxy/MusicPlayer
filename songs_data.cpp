#include "songs_data.h"
#include <iostream>

SongData::SongData(const QString& _path) : MediaData(_path){}

SongData::SongData(const QString& _path, bool _isLiked) : MediaData(_path, _isLiked){}

SongData::~SongData(){}



