#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "songs_data.h"
#include "playlist.h"
#include "media_loader.h"

class MediaPlayer: public QObject{
    Q_OBJECT
public:

    MediaPlayer(QObject* parent = nullptr, MediaLoader* loader = nullptr);
    ~MediaPlayer();
    virtual QMediaPlayer* getPlayer() const{}
    virtual Playlist* getPlaylist(const QString&) const{}
    virtual MediaData* getCurrentItem() const{}
    virtual Playlist* getCurrentPlaylist() const {}
    virtual QVector<QString> getListOfPlaylists() const{}

    virtual void play(){}
    virtual void pause(){}
    virtual void stop(){}
    virtual void changeVolume(int){}
    virtual void changeDuration(int){}

    virtual void setLike(){}
    virtual void setCurrent(int){}
    virtual void setPlaylist(Playlist*){}
    virtual void addPlaylist(const QString&){}


protected:
    QMediaPlayer        *m_player;          // Проигрыватель треков
    std::map<QString, Playlist*> list_of_playlists;
    Playlist *playlist;
    MediaData* current_item;
    MediaLoader* serializer;
};


#endif // MULTIMEDIA_H
