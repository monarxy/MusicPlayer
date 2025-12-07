#ifndef MEDIA_DATA_H
#define MEDIA_DATA_H
#include <QString>

class MediaData{
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
