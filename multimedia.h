#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "songs_data.h"
#include "playlist.h"

class MediaPlayer{
public:

    virtual QMediaPlayer* getPlayer(){}
    virtual QMediaPlaylist* getQPlaylist(){}
    virtual Playlist* getPlaylist(QString){}
    virtual MediaData* getCurrentItem(){}

    virtual void play(){}
    virtual void pause(){}
    virtual void stop(){}
    virtual void changeVolume(int){}
    virtual void changeDuration(int){}
    virtual void deleteQPlaylist(){}

    virtual void setLike(){}
    virtual void setCurrent(int){}
    virtual void setPlaylist(Playlist*){}
    virtual void addPlaylist(QString){}
protected:
    QMediaPlayer        *m_player;          // Проигрыватель треков
    QMediaPlaylist      *q_playlist;
    std::map<QString, Playlist*> list_of_playlists;
    Playlist *playlist;
    MediaData* current_item;
};


#endif // MULTIMEDIA_H
