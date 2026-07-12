#ifndef MEDIA_DATA_H
#define MEDIA_DATA_H
#include <QString>
#include <QSettings>
#include <QDataStream>
#include <QVector>

class MediaData{
public:
    MediaData(const QString&);
    MediaData(const QString&, bool);
    bool getLikeInfo() const;
    void putLike();
    void deletelike();
    QString getPath() const;
protected:
    bool isLiked;
    QString path;
};


#endif // MEDIA_DATA_H
