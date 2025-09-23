#ifndef VIDEO_DATA_H
#define VIDEO_DATA_H
#include "media_data.h"

class VideoData: public MediaData{
    friend class Widget;
public:
    VideoData(QString);
private:
    void putLike();
    void deletelike();

}

#endif // VIDEO_DATA_H
