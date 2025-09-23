#ifndef MEDIA_DATA_H
#define MEDIA_DATA_H
//#include "widget.h"
#include <QString>

class MediaData{
    friend class Widget;
public:
    virtual bool getLikeInfo(){}
    virtual void putLike(){}
    virtual void deletelike(){}
    virtual QString getPath(){}
protected:
    bool isLiked;
    QString path;
};

#endif // MEDIA_DATA_H
