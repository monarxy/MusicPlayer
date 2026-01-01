#ifndef SONGS_DATA_H
#define SONGS_DATA_H
#include "media_data.h"

class SongData: public MediaData{
public:
    SongData(const QString&);
    SongData(const QString&, bool);
    bool getLikeInfo() const;
    void putLike();
    void deletelike();
    QString getPath() const;
};



#endif // SONGS_DATA_H
