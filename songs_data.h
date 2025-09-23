#ifndef SONGS_DATA_H
#define SONGS_DATA_H
//#include "widget.h"
//#include "ui_widget.h"
#include "media_data.h"

class SongData: public MediaData{
    friend class Widget;
public:
    SongData(QString);
    bool getLikeInfo();
    void putLike();
    void deletelike();
    QString getPath();
private:
    bool operator==(const SongData&) const;
};

//bool operator==(const SongData&);

#endif // SONGS_DATA_H
