#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "tracks_loader.h"
#include "multimedia.h"

class MusicPlayer : public MediaPlayer{
public:
    MusicPlayer();
    MusicPlayer(MediaLoader*);
    ~MusicPlayer();

    QMediaPlayer* getPlayer();
    QMediaPlaylist* getQPlaylist();
    Playlist* getPlaylist(QString);
    Playlist* getCurrentPlaylist() const;
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



    void test();
};


#endif // MUSIC_PLAYER_H
