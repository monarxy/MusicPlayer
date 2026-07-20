#ifndef VIDEO_DATA_H
#define VIDEO_DATA_H
#include "data.h"

class VideoData: public Data{
public:
    VideoData(const QString&);
    VideoData(const QString&, bool);
private:
    void putLike();
    void deletelike();
    bool getLikeInfo() const;
    QString getPath() const;
};

#endif // VIDEO_DATA_H
