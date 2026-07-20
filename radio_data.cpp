#include "radio_data.h"

RadioData::RadioData(const QString& _path) : Data(_path){}

RadioData::RadioData(const QString& _path, bool _isLiked) : Data(_path, _isLiked){}

RadioData::~RadioData(){}
