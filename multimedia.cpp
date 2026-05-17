#include "multimedia.h"
#include <QDebug>

MediaPlayer::MediaPlayer(QObject* parent, MediaLoader* _serializer)
    : QObject(parent)
    , m_player(nullptr)
    , playlist(nullptr)
    , current_item(nullptr)
    , serializer(_serializer)
{
    m_player = new QMediaPlayer();
    m_player->setVolume(50);
}

void MediaPlayer::play(){
    m_player->play();
}

void MediaPlayer::pause(){
    m_player->pause();
}

void MediaPlayer::stop(){
    m_player->stop();
}

void MediaPlayer::next(){
    m_player->pause();
    playlist->getQPlaylist()->next();
    m_player->play();
}

void MediaPlayer::previous(){
    m_player->pause();
    playlist->getQPlaylist()->previous();
    m_player->play();
}

void MediaPlayer::changeVolume(const int index){
    m_player->setVolume(index);
}

void MediaPlayer::changeDuration(const int index){
    m_player->setPosition(index * 1000);
}

void MediaPlayer::setLike(){
    if (current_item->getLikeInfo())
        current_item->deletelike();
    else current_item->putLike();
}

void MediaPlayer::setCurrent(const int index){
    current_item = (playlist->getListOfItems())[index];
    playlist->getQPlaylist()->setCurrentIndex(index);
}

const QMediaPlayer*  MediaPlayer::getPlayer() const{
    return m_player;
}

const Playlist* MediaPlayer::getPlaylist(const QString& name) const{

    auto it = list_of_playlists.find(name);
    return (it != list_of_playlists.end()) ? it->second : nullptr;
}

const Playlist* MediaPlayer::getCurrentPlaylist() const{
    return playlist;
}

const QVector<QString> MediaPlayer::getListOfPlaylists() const{
    QVector<QString> vector_of_playlists;
    for (const auto& playlist : list_of_playlists)
        vector_of_playlists.append(playlist.first);

    return vector_of_playlists;
}

void MediaPlayer::addPlaylist(const QString& name){
    if (list_of_playlists[name] == nullptr)
        list_of_playlists[name] = new Playlist(name);
}

const MediaData* MediaPlayer::getCurrentItem() const{
    return current_item;
}

void MediaPlayer::setPlaylist(Playlist* new_playlist){
    playlist = new_playlist;
    m_player->setPlaylist(playlist->getQPlaylist());
}

void MediaPlayer::setCurrentPlaylistByName(const QString& album_name){
    auto it = list_of_playlists.find(album_name);
    playlist = (it != list_of_playlists.end()) ? it->second : nullptr;
    m_player->setPlaylist(playlist->getQPlaylist());
}

void MediaPlayer::load(){
    QVector<Playlist*> loaded_playlists = serializer->loadSavedItems();
    if (loaded_playlists.size() != 0){
        for (Playlist* playlist : loaded_playlists)
            list_of_playlists[playlist->getName()] = playlist;
        auto it = std::next(list_of_playlists.begin(), 0);
        if (it != list_of_playlists.end())
            playlist = it->second;
        m_player->setPlaylist(playlist->getQPlaylist());
    }
}

void MediaPlayer::save(){
    serializer->saveItems(list_of_playlists);
}

MediaPlayer::~MediaPlayer()
{
    save();
    for (const auto& pair : list_of_playlists)
        delete pair.second;
    delete m_player;
    qDebug() << "a";
}
