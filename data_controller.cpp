#include <QDir>
#include "data_controller.h"
#include <QDebug>


DataController::DataController(QObject *parent, MediaPlayer* _music_player) :QObject(parent) {
    music_player =_music_player;
}


void DataController::setMusicPlayer(const QStringList& list_of_tracks){
    music_player->setTracksToCurrentPlaylist(list_of_tracks);
}

MediaPlayer* DataController::getPlayer() const{
    return music_player;
}

void DataController::addTracksToPlaylist(const QString& album_name, const QStringList& list_of_tracks){
    music_player->setTracksToPlaylistByName(album_name, list_of_tracks);

}

QStringList DataController::getPlaylistItems(const QString &playlist_name) const{
    QStringList list_of_names;
    for (const MediaData* item : music_player->getPlaylist(playlist_name)->getListOfItems())
        list_of_names.append(QDir(item->getPath()).dirName());
    return list_of_names;
}


void DataController::setCurrentTrack(const int index){
    music_player->setCurrent(index);
}

void DataController::addNewPlaylist(const QString& album_name){
    music_player->addPlaylist(album_name);
}

void DataController::play(){
    music_player->play();
}

void DataController::pause(){
    music_player->pause();
}

void DataController::next(){
    music_player->next();
}

void DataController::previous(){
    music_player->previous();
}

void DataController::changeVolume(const int index){
    music_player->changeVolume(index);
}

void DataController::changeDuration(const int index){
    music_player->changeDuration(index);
}

void DataController::setLike(){
    music_player->setLike();
}

void DataController::loadSavedTracks(const QString& album_name){

    emit LoadTracksToMainWidget(getPlaylistItems(album_name), album_name);
}

void DataController::setListOfPlaylistsItemsReceiver(const QString& album_name) {
    emit SetListOfPlaylistsItems(getPlaylistItems(album_name), album_name);
}

void DataController::likeReceiver() {
    emit LikeStatusSignal(music_player->getCurrentItem()->getLikeInfo());
}

void DataController::getPlaylistNamesReceiver() {
    QStringList list_of_names;
    for (const QString& item : music_player->getListOfPlaylists())
        list_of_names.append(item);
    emit LoadPlaylistsFromMemory(list_of_names);
}

void DataController::setPlaylistAndCurrentTrackReceiver(const int index, const QString& album_name) {
    music_player->stop();
    music_player->setCurrentPlaylistByName(album_name);
    music_player->setCurrent(index);
    emit LikeStatusSignal(music_player->getCurrentItem()->getLikeInfo());
    music_player->play();
    emit LoadTracksToMainWidget(getPlaylistItems(album_name), album_name);
}


DataController::~DataController(){}
