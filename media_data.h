#ifndef MEDIA_DATA_H
#define MEDIA_DATA_H
#include <QString>
#include <QSettings>
#include <QDataStream>
#include <QVector>

class MediaData{
public:
    virtual bool getLikeInfo() const {}
    virtual void putLike(){}
    virtual void deletelike(){}
    virtual QString getPath() const {}
protected:
    bool isLiked;
    QString path;
};


#endif // MEDIA_DATA_H
