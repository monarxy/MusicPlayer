#include "music_player.h"

MusicPlayer::MusicPlayer(QObject *parent, MediaLoader* _serializer) : MediaPlayer(parent, _serializer){
    m_player = new QMediaPlayer();
    m_player->setVolume(50);
    //q_playlist = new QMediaPlaylist(m_player);
    //m_player->setPlaylist(q_playlist);
    //q_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    if (_serializer != nullptr)
        serializer = _serializer;

    for (Playlist* playlist : serializer->loadSavedTracks())
        list_of_playlists[playlist->getName()] = playlist;


    playlist = list_of_playlists[""];
    m_player->setPlaylist(playlist->getQPlaylist());
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

void MusicPlayer::nextTrack(){
    m_player->pause();
    playlist->getQPlaylist()->next();
    m_player->play();
}

void MusicPlayer::previousTrack(){
    m_player->pause();
    playlist->getQPlaylist()->previous();
    m_player->play();
}

void MusicPlayer::changeVolume(const int index){
    m_player->setVolume(index);
}

void MusicPlayer::changeDuration(const int index){
    m_player->setPosition(index * 1000);
}

void MusicPlayer::setLike(){
    if (current_item->getLikeInfo())
        current_item->deletelike();
    else current_item->putLike();
}

void MusicPlayer::setCurrent(const int index){
    current_item = (playlist->getListOfItems())[index];
    playlist->getQPlaylist()->setCurrentIndex(index);
}

QMediaPlayer*  MusicPlayer::getPlayer() const{
    return m_player;
}

Playlist* MusicPlayer::getPlaylist(const QString& name) const{

    auto it = list_of_playlists.find(name);
    return (it != list_of_playlists.end()) ? it->second : nullptr;
}

Playlist* MusicPlayer::getCurrentPlaylist() const{
    return playlist;
}

QVector<QString> MusicPlayer::getListOfPlaylists() const{
    QVector<QString> vector_of_playlists;
    for (const auto& playlist : list_of_playlists)
        vector_of_playlists.append(playlist.first);

    return vector_of_playlists;
}

void MusicPlayer::addPlaylist(const QString& name){
    if (list_of_playlists[name] == nullptr)
        list_of_playlists[name] = new Playlist(name);
}

MediaData* MusicPlayer::getCurrentItem() const{
    return current_item;
}

void MusicPlayer::setPlaylist(Playlist* new_playlist){
    playlist = new_playlist;
    m_player->setPlaylist(playlist->getQPlaylist());
}

MusicPlayer::~MusicPlayer()
{

    serializer->saveTracks(list_of_playlists);

    for (const auto& pair : list_of_playlists)
        delete pair.second;
    delete m_player;

}

