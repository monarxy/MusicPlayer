#ifndef IQPLAYLISTMANAGEMENT_H
#define IQPLAYLISTMANAGEMENT_H

#include <QMediaPlaylist>

class IQPlaylistManagement{
public:
    virtual QMediaPlaylist* getQPlaylist() const = 0;
};

#endif // IQPLAYLISTMANAGEMENT_H
