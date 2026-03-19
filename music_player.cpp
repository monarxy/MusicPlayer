#include "music_player.h"

MusicPlayer::MusicPlayer(QObject *parent, MediaLoader* _serializer) : MediaPlayer(parent, _serializer){
    m_player = new QMediaPlayer();
    //q_playlist = new QMediaPlaylist(m_player);
    //m_player->setPlaylist(q_playlist);
    m_player->setVolume(70);
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
}

MusicPlayer::~MusicPlayer()
{

    serializer->saveTracks(list_of_playlists);

    for (const auto& pair : list_of_playlists)
        delete pair.second;
    delete m_player;

}

