#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <vector>
#include <QSettings>
#include <QDataStream>
#include <QVector>
#include <QMediaPlayer>
#include "IPlaylistNameManagement.h"
#include "IQPlaylistManagement.h"
#include "IDeleteItemsInPlaylistManagement.h"
#include "IMovementPlaylistManagement.h"
#include "IPlaylistItemsManagement.h"

class Playlist : IPlaylistNameManagement, IQPlaylistManagement, IDeleteItemsInPlaylistManagement, IMovementPlaylistManagement,
IPlaylistItemsManagement {
public:
    Playlist();
    Playlist(const QString&);
    ~Playlist();

    QVector<MediaData*> getListOfItems() const override;
    QMediaPlaylist* getQPlaylist() const override;
    QString getName() const override;
    MediaData* getNextItem(MediaData*) const override;
    MediaData* getPreviousItem(MediaData*) const override;

    void setName(const QString&) override;
    void setListOfItems(MediaData*) override;

    void deleteItem(MediaData*) override = 0;

protected:
    QString playlist_name;
    QVector<MediaData*> playlist_items;
    QMediaPlaylist* q_playlist;
};

#endif // PLAYLIST_H
