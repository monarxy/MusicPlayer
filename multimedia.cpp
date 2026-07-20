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
    favourite_playlist = new FavouritePlaylist();
}

void MediaPlayer::play(){
    if (list_of_playlists.size() != 0)
        if (current_item != nullptr)
            m_player->play();
}

void MediaPlayer::pause(){
    if (list_of_playlists.size() != 0)
        if (current_item != nullptr)
            m_player->pause();
}

void MediaPlayer::stop(){
    if (list_of_playlists.size() != 0)
        if (current_item != nullptr)
            m_player->stop();
}

void MediaPlayer::next(){
    if (list_of_playlists.size() != 0)
        if (current_item != nullptr){
            m_player->pause();
            MediaData* next_current_item = playlist->getNextItem(current_item);
            if (next_current_item != nullptr){
                playlist->getQPlaylist()->next();
                current_item = next_current_item;
            }
            m_player->play();
        }
}

void MediaPlayer::previous(){
    if (list_of_playlists.size() != 0)
        if (current_item != nullptr){
            m_player->pause();
            MediaData* prev_current_item = playlist->getPreviousItem(current_item);
            if (prev_current_item != nullptr){
                playlist->getQPlaylist()->previous();
                current_item = prev_current_item;
            }
            m_player->play();
        }
}

void MediaPlayer::changeVolume(const int index){
    m_player->setVolume(index);
}

void MediaPlayer::changeDuration(const int index){
    m_player->setPosition(index * 1000);
}

void MediaPlayer::setLike(){
    if (list_of_playlists.size() != 0 || current_item != nullptr)
        if (current_item->getLikeInfo()){
            current_item->deletelike();
            favourite_playlist->deleteItem(current_item);
        }
        else{
            current_item->putLike();
            favourite_playlist->setListOfItems(current_item);
        }
}

void MediaPlayer::setCurrent(const int index){
    current_item = (playlist->getListOfItems())[index];
    playlist->getQPlaylist()->setCurrentIndex(index);
}

void MediaPlayer::deleteCurrent(){
    m_player->stop();
    if (playlist->getListOfItems().size() != 0)
        if (playlist->getListOfItems().size() != 1){
            auto current_item_copy = current_item;
            if (playlist->getListOfItems()[0] != current_item){
                int index = playlist->getListOfItems().indexOf(current_item);
                current_item = playlist->getPreviousItem(current_item);
                playlist->getQPlaylist()->setCurrentIndex(index-1);
            }
            else
                current_item = playlist->getNextItem(current_item);
            if (current_item_copy->getLikeInfo())
                favourite_playlist->deleteItem(current_item_copy);
            playlist->deleteItem(current_item_copy);
        }
        else{
            if (current_item->getLikeInfo())
                favourite_playlist->deleteItem(current_item);
            playlist->deleteItem(current_item);
            current_item = nullptr;
        }
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

const Playlist* MediaPlayer::getFavouritePlaylist() const{
    return favourite_playlist;
}

const QVector<QString> MediaPlayer::getListOfPlaylists() const{
    QVector<QString> vector_of_playlists;
    for (const auto& playlist : list_of_playlists)
        vector_of_playlists.append(playlist.first);

    return vector_of_playlists;
}

void MediaPlayer::addPlaylist(const QString& name){
    if (list_of_playlists.find(name) == list_of_playlists.end())
        list_of_playlists[name] = new DefaultPlaylist(name);
    if (list_of_playlists.size() == 1){
        playlist = list_of_playlists[name];
        if ((playlist->getListOfItems()).size() != 0)
            current_item = (playlist->getListOfItems())[0];
        if (!playlist->getQPlaylist()->isEmpty())
            m_player->setPlaylist(playlist->getQPlaylist());
    }
}

void MediaPlayer::deletePlaylist(const QString& name){
    if (playlist->getName() == name){
        m_player->stop();
        for (MediaData* item : playlist->getListOfItems())
            for (MediaData* favourite_item : favourite_playlist->getListOfItems())
                if (item == favourite_item)
                    favourite_playlist->deleteItem(item);

        if (list_of_playlists.size() != 1){
            if (list_of_playlists.find(name) == list_of_playlists.begin())
                playlist = (++list_of_playlists.find(name))->second;
            else
                playlist = (--list_of_playlists.find(name))->second;

            current_item = (playlist->getListOfItems())[0];
            m_player->setPlaylist(playlist->getQPlaylist());
        }
        else{
            m_player->setPlaylist(nullptr);
            delete playlist;
            playlist = nullptr;
            current_item = nullptr;
        }
        list_of_playlists.erase(name);
    }
    else{
        auto found_playlist = list_of_playlists.find(name);
        Playlist* tmp_playlist = found_playlist->second;
        if (found_playlist != list_of_playlists.end()){
            for (MediaData* item : tmp_playlist->getListOfItems())
                for (MediaData* favourite_item : favourite_playlist->getListOfItems())
                    if (item == favourite_item)
                        favourite_playlist->deleteItem(item);
            list_of_playlists.erase(name);
            delete tmp_playlist;
        }
        if (list_of_playlists.size() == 0){
            playlist = nullptr;
            delete current_item;
            current_item = nullptr;
            m_player->setPlaylist(nullptr);
        }
    }

}

const MediaData* MediaPlayer::getCurrentItem() const{
    return current_item;
}

void MediaPlayer::setPlaylist(Playlist* new_playlist){
    playlist = new_playlist;
    m_player->setPlaylist(playlist->getQPlaylist());
}

void MediaPlayer::setTracksToPlaylistByName(const QString& album_name, const QStringList& list_of_tracks){
    auto it = list_of_playlists.find(album_name);
    Playlist* playlist = (it != list_of_playlists.end()) ? it->second : nullptr;
    CoverExtractor cover_extractor;
    for (const QString& item : list_of_tracks)
        playlist->setListOfItems(new MediaData(item, false, cover_extractor.extractCoverUniversal(item)));

}

void MediaPlayer::setTracksToCurrentPlaylist(const QStringList& list_of_tracks){
    CoverExtractor cover_extractor;
    for (const QString& item : list_of_tracks)
        playlist->setListOfItems(new MediaData(item, false, cover_extractor.extractCoverUniversal(item)));

}

void MediaPlayer::setCurrentPlaylistByName(const QString& album_name){
    auto it = list_of_playlists.find(album_name);

    if (it != list_of_playlists.end()){
        playlist = it->second;
        m_player->setPlaylist(playlist->getQPlaylist());
        if (!playlist->getListOfItems().isEmpty())
            current_item = (playlist->getListOfItems())[0];
    }
}

void MediaPlayer::setFavouritePlaylistAsMain(){
    playlist = favourite_playlist;
    m_player->setPlaylist(playlist->getQPlaylist());
}

MediaPlayer::~MediaPlayer()
{
    for (const auto& pair : list_of_playlists)
        delete pair.second;
    delete m_player;
}
