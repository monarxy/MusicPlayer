#include "radio_data.h"

RadioData::RadioData(const QString& _path) : MediaData(_path){}

RadioData::RadioData(const QString& _path, bool _isLiked) : MediaData(_path, _isLiked){}

RadioData::~RadioData(){}
