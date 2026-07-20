#ifndef DATA_H
#define DATA_H
#include <QString>
#include <QPixmap>
#include <QVector>

class Data{
public:
    Data(const QString&);
    Data(const QString&, bool);
    bool getLikeInfo() const;
    void putLike();
    void deletelike();
    QString getPath() const;
protected:
    bool isLiked;
    QString path;
};


#endif // DATA_H
