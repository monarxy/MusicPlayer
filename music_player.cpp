#include "music_player.h"

MusicPlayer::MusicPlayer(QObject *parent, MediaLoader* _serializer) : MediaPlayer(parent, _serializer){
    m_player = new QMediaPlayer();
    m_player->setVolume(50);
    //q_playlist = new QMediaPlaylist(m_player);
    //m_player->setPlaylist(q_playlist);
    //q_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    if (_serializer != nullptr)
        serializer = _serializer;



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

void MusicPlayer::next(){
    m_player->pause();
    playlist->getQPlaylist()->next();
    m_player->play();
}

void MusicPlayer::previous(){
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

const QMediaPlayer*  MusicPlayer::getPlayer() const{
    return m_player;
}

const Playlist* MusicPlayer::getPlaylist(const QString& name) const{

    auto it = list_of_playlists.find(name);
    return (it != list_of_playlists.end()) ? it->second : nullptr;
}

const Playlist* MusicPlayer::getCurrentPlaylist() const{
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

const MediaData* MusicPlayer::getCurrentItem() const{
    return current_item;
}

void MusicPlayer::setPlaylist(Playlist* new_playlist){
    playlist = new_playlist;
    m_player->setPlaylist(playlist->getQPlaylist());
}

void MusicPlayer::setCurrentPlaylistByName(const QString& album_name){
    auto it = list_of_playlists.find(album_name);
    playlist = (it != list_of_playlists.end()) ? it->second : nullptr;
    m_player->setPlaylist(playlist->getQPlaylist());
}

void MusicPlayer::setTracksToPlaylistByName(const QString& album_name, const QStringList& list_of_tracks){
    auto it = list_of_playlists.find(album_name);
    Playlist* playlist = (it != list_of_playlists.end()) ? it->second : nullptr;
    for (const QString& item : list_of_tracks)
        playlist->setListOfItems(new SongData(item, false));

}

void MusicPlayer::setTracksToCurrentPlaylist(const QStringList& list_of_tracks){
    for (const QString& item : list_of_tracks)
        playlist->setListOfItems(new SongData(item, false));

}

void MusicPlayer::load(){
    for (Playlist* playlist : serializer->loadSavedItems())
        list_of_playlists[playlist->getName()] = playlist;
    playlist = list_of_playlists[""];
    m_player->setPlaylist(playlist->getQPlaylist());
}

void MusicPlayer::save(){
    serializer->saveItems(list_of_playlists);
}

MusicPlayer::~MusicPlayer()
{
    save();
    for (const auto& pair : list_of_playlists)
        delete pair.second;
    delete m_player;

}

