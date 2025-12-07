#include "music_player.h"

MusicPlayer::MusicPlayer(QStringList list_of_loaded){
    m_player = new QMediaPlayer();
    q_playlist = new QMediaPlaylist(m_player);
    m_player->setPlaylist(q_playlist);
    m_player->setVolume(70);
    q_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist = new Playlist();

    foreach (QString filePath, list_of_loaded){
        playlist->setListOfItems(new SongData(filePath));
        q_playlist->addMedia(QUrl(filePath));
    }
    list_of_playlists[""] = playlist;
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
    current_item = (playlist->getListOfItems())[index];
    q_playlist->setCurrentIndex(index);
}

QMediaPlayer*  MusicPlayer::getPlayer(){
    return m_player;
}

QMediaPlaylist* MusicPlayer::getQPlaylist(){
    return q_playlist;
}

Playlist* MusicPlayer::getPlaylist(QString name){
    if (list_of_playlists[name]!= nullptr)
        return list_of_playlists[name];
}

void MusicPlayer::addPlaylist(QString name){
    if (list_of_playlists[name] == nullptr)
        list_of_playlists[name] = new Playlist(name);
}

MediaData* MusicPlayer::getCurrentItem(){
    return current_item;
}

void MusicPlayer::setPlaylist(Playlist* new_playlist){
    playlist = new_playlist;
}

void MusicPlayer::deleteQPlaylist(){
    q_playlist->clear();
}

MusicPlayer::~MusicPlayer()
{
}
