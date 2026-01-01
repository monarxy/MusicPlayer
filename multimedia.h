#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "songs_data.h"
#include "playlist.h"
#include "media_loader.h"

class MediaPlayer{
public:

    virtual QMediaPlayer* getPlayer() const{}
    virtual Playlist* getPlaylist(const QString&) const{}
    virtual MediaData* getCurrentItem() const{}
    virtual Playlist* getCurrentPlaylist() const {}
    virtual QVector<QString> getListOfPlaylists() const{}

    virtual void play(){}
    virtual void pause(){}
    virtual void stop(){}
    virtual void changeVolume(const int&){}
    virtual void changeDuration(const int&){}

    virtual void setLike(){}
    virtual void setCurrent(const int&){}
    virtual void setPlaylist(Playlist*){}
    virtual void addPlaylist(const QString&){}


    virtual void test(){}

protected:
    QMediaPlayer        *m_player;          // Проигрыватель треков
    std::map<QString, Playlist*> list_of_playlists;
    Playlist *playlist;
    MediaData* current_item;
    MediaLoader* serializer;
};


#endif // MULTIMEDIA_H
