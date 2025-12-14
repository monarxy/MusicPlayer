#ifndef VIDEO_DATA_H
#define VIDEO_DATA_H
#include "media_data.h"

class VideoData: public MediaData{
public:
    VideoData(QString);
    VideoData(QString, bool);
private:
    void putLike();
    void deletelike();
    bool getLikeInfo() const;
    QString getPath() const;
};

#endif // VIDEO_DATA_H
