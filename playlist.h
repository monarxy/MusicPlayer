#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <vector>
#include <QSettings>
#include <QDataStream>
#include <QVector>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "songs_data.h"
#include "video_data.h"

class Playlist{
public:
    Playlist();
    Playlist(const QString&);

    QVector<MediaData*> getListOfItems() const;
    QMediaPlaylist* getQPlaylist() const;
    QString getName() const;

    void setName(const QString&);
    void setListOfItems(MediaData*);

protected:
    QString playlist_name;
    QVector<MediaData*> playlist_items;
    QMediaPlaylist* q_playlist;
};

#endif // PLAYLIST_H
