#ifndef SONGS_DATA_H
#define SONGS_DATA_H
#include "media_data.h"

class SongData: public MediaData{
public:
    SongData(QString);
    SongData(QString, bool);
    bool getLikeInfo() const;
    void putLike();
    void deletelike();
    QString getPath() const;
private:
    bool operator==(const SongData&) const;
};



#endif // SONGS_DATA_H
