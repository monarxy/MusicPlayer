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
    Playlist(QString);

    QVector<MediaData*> getListOfItems();
    QMediaPlaylist* getQPlaylist();
    QString getName();

    void setName(QString);
    void setListOfItems(MediaData*);

protected:
    QString playlist_name;
    QVector<MediaData*> playlist_items;
    QMediaPlaylist* q_playlist;
};

Q_DECLARE_METATYPE(Playlist*)
Q_DECLARE_METATYPE(MediaData*)
Q_DECLARE_METATYPE(QVector<MediaData*>)

QDataStream &operator<<(QDataStream &out, Playlist* const &playlist);

QDataStream &operator>>(QDataStream &in, Playlist* &playlist);

QDataStream &operator<<(QDataStream &out, const QVector<MediaData*> &items);

QDataStream &operator>>(QDataStream &in, QVector<MediaData*> &items);

QDataStream &operator<<(QDataStream &out, MediaData* const &item);

QDataStream &operator>>(QDataStream &in, MediaData* &item);


#endif // PLAYLIST_H
