#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H
//#include "widget.h"
//#include "ui_widget.h"
#include "multimedia.h"

class MusicPlayer : public MediaPlayer{
public:
    MusicPlayer(QStringList);
    ~MusicPlayer();

    QMediaPlayer* getPlayer();
    QMediaPlaylist* getQPlaylist();
    Playlist* getPlaylist(QString);
    MediaData* getCurrentItem();

    void play();
    void pause();
    void stop();
    void changeVolume(int);
    void changeDuration(int);
    void deleteQPlaylist();

    void setLike();
    void setCurrent(int);
    void setPlaylist(Playlist*);
    void addPlaylist(QString);
};

#endif // MUSIC_PLAYER_H
