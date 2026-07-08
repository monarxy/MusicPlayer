#ifndef IPLAYLISTMANAGEMENT_H
#define IPLAYLISTMANAGEMENT_H
#include "playlist.h"

class IPlaylistManagement {
public:
    virtual const Playlist* getPlaylist(const QString&) const = 0;
    virtual const Playlist* getCurrentPlaylist() const = 0;
    virtual const QVector<QString> getListOfPlaylists() const = 0;
    virtual void setPlaylist(Playlist*) = 0;
    virtual void setTracksToPlaylistByName(const QString&, const QStringList&) = 0;
    virtual void setTracksToCurrentPlaylist(const QStringList&) = 0;
    virtual void setCurrentPlaylistByName(const QString&) = 0;
    virtual void addPlaylist(const QString&) = 0;
    virtual void deletePlaylist(const QString&) = 0;
    virtual ~IPlaylistManagement() = default;
};

#endif // IPLAYLISTMANAGEMENT_H
