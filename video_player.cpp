#include "video_player.h"

VideoPlayer::VideoPlayer(QObject *parent, MediaLoader* _serializer) : MediaPlayer(parent, _serializer){
    m_player = new QMediaPlayer();
    m_player->setVolume(50);
    if (_serializer != nullptr)
        serializer = _serializer;

    for (Playlist* playlist : serializer->loadSavedItems())
        list_of_playlists[playlist->getName()] = playlist;


    playlist = list_of_playlists[""];
    m_player->setPlaylist(playlist->getQPlaylist());
}


void VideoPlayer::play(){
    m_player->play();
}

void VideoPlayer::pause(){
    m_player->pause();
}

void VideoPlayer::stop(){
    m_player->stop();
}

void VideoPlayer::next(){
    m_player->pause();
    playlist->getQPlaylist()->next();
    m_player->play();
}

void VideoPlayer::previous(){
    m_player->pause();
    playlist->getQPlaylist()->previous();
    m_player->play();
}

void VideoPlayer::changeVolume(const int index){
    m_player->setVolume(index);
}

void VideoPlayer::changeDuration(const int index){
    m_player->setPosition(index * 1000);
}

void VideoPlayer::setLike(){
    if (current_item->getLikeInfo())
        current_item->deletelike();
    else current_item->putLike();
}

void VideoPlayer::setCurrent(const int index){
    current_item = (playlist->getListOfItems())[index];
    playlist->getQPlaylist()->setCurrentIndex(index);
}

void VideoPlayer::setCurrentPlaylistByName(const QString& album_name){
    auto it = list_of_playlists.find(album_name);
    playlist = (it != list_of_playlists.end()) ? it->second : nullptr;
}


const QMediaPlayer*  VideoPlayer::getPlayer() const{
    return m_player;
}

const Playlist* VideoPlayer::getPlaylist(const QString& name) const{

    auto it = list_of_playlists.find(name);
    return (it != list_of_playlists.end()) ? it->second : nullptr;
}

const Playlist* VideoPlayer::getCurrentPlaylist() const{
    return playlist;
}

QVector<QString> VideoPlayer::getListOfPlaylists() const{
    QVector<QString> vector_of_playlists;
    for (const auto& playlist : list_of_playlists)
        vector_of_playlists.append(playlist.first);

    return vector_of_playlists;
}

void VideoPlayer::addPlaylist(const QString& name){
    if (list_of_playlists[name] == nullptr)
        list_of_playlists[name] = new Playlist(name);
}

const MediaData* VideoPlayer::getCurrentItem() const{
    return current_item;
}

void VideoPlayer::setPlaylist(Playlist* new_playlist){
    playlist = new_playlist;
    m_player->setPlaylist(playlist->getQPlaylist());
}

void VideoPlayer::setTracksToPlaylistByName(const QString& album_name, const QStringList& list_of_tracks){
    // auto it = list_of_playlists.find(album_name);
    // Playlist* playlist = (it != list_of_playlists.end()) ? it->second : nullptr;
    // for (const QString& item : list_of_tracks)
    //     playlist->setListOfItems(new SongData(item, false));

}

void VideoPlayer::setTracksToCurrentPlaylist(const QStringList& list_of_tracks){
    // for (const QString& item : list_of_tracks)
    //     playlist->setListOfItems(new SongData(item, false));

}

VideoPlayer::~VideoPlayer()
{

    serializer->saveItems(list_of_playlists);

    for (const auto& pair : list_of_playlists)
        delete pair.second;
    delete m_player;

}
