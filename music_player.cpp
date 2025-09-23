#include "music_player.h"
//#include "widget.h"
//#include "ui_widget.h"

MusicPlayer::MusicPlayer(){
    m_player = new QMediaPlayer();          // Инициализируем плеер
    q_playlist = new QMediaPlaylist(m_player);  // Инициализируем плейлист
    m_player->setPlaylist(q_playlist);          // Устанавливаем плейлист в плеер
    m_player->setVolume(70);                    // Устанавливаем громкость воспроизведения треков
    q_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist = new Playlist();
}

void MusicPlayer::play(){
    m_player->play();
}

void MusicPlayer::pause(){
    m_player->pause();
}

void MusicPlayer::stop(){
    m_player->stop();
}

void MusicPlayer::changeVolume(int index){
    m_player->setVolume(index);
}

void MusicPlayer::changeDuration(int index){
    m_player->setPosition(index * 1000);
}

void MusicPlayer::setLike(){
    if (current_item->getLikeInfo())
        current_item->deletelike();
    else current_item->putLike();
}

void MusicPlayer::setCurrent(int index){
    current_item = (*(playlist->getListOfItems()))[index];
    q_playlist->setCurrentIndex(index);
}

QMediaPlayer*  MusicPlayer::getPlayer(){
    return m_player;
}

QMediaPlaylist* MusicPlayer::getQPlaylist(){
    return q_playlist;
}

Playlist* MusicPlayer::getPlaylist(){
    return playlist;
}

MediaData* MusicPlayer::getCurrentItem(){
    return current_item;
}

void MusicPlayer::setPlaylist(Playlist* new_playlist){
    //delete playlist;
    playlist = new_playlist;
}

void MusicPlayer::deleteQPlaylist(){
    q_playlist->clear();
}
