#include <QDir>
#include "data_controller.h"
#include <QDebug>


DataController::DataController(QObject *parent) :QObject(parent) {}


void DataController::setItemsToPlayer(const QStringList& list_of_tracks){
    player->setTracksToCurrentPlaylist(list_of_tracks);
}

void DataController::setMainPlayerByName(const QString& player_name){
    player = players[player_name];
}

const MediaPlayer* DataController::getPlayer() const{
    return player;
}

void DataController::setCurrentPlayerByIndex(const int index){
    player->stop();

    auto it = std::next(players.begin(), index);
    if (it != players.end()) {
        player = it->second;
    }

    auto list_of_playlists = player->getListOfPlaylists();
    if (list_of_playlists.size()!=0){
        player->setCurrentPlaylistByName(list_of_playlists[0]);
        if ((player->getCurrentPlaylist()->getListOfItems()).size() != 0){
            player->setCurrent(0);
            emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
            emit LoadItemsToMainWidget(getListOfPlaylistItems(list_of_playlists[0]), list_of_playlists[0]);}}
}

void DataController::setVideoOutput(QVideoWidget* video_widget){
    (static_cast<VideoPlayer*>(player))->setVideoOutput(video_widget);
}

void DataController::addItemsToPlaylist(const QString& album_name, const QStringList& list_of_tracks){
    player->setTracksToPlaylistByName(album_name, list_of_tracks);

}

QStringList DataController::getListOfPlaylistItems(const QString &playlist_name) const{
    QStringList list_of_names;
    for (const MediaData* item : player->getPlaylist(playlist_name)->getListOfItems())
        list_of_names.append(QDir(item->getPath()).dirName());
    return list_of_names;
}


void DataController::setCurrentItemByIndex(const int index){
    player->setCurrent(index);
}

void DataController::addNewPlaylist(const QString& album_name){
    player->addPlaylist(album_name);
}

void DataController::setMapOfPlayers(const QString& player_name, MediaPlayer* player_item){
    players[player_name] = player_item;
}

void DataController::playReceive(){
    player->play();
}

void DataController::pauseReceive(){
    player->pause();
}

void DataController::nextReceive(){
    player->next();
}

void DataController::previousReceive(){
    player->previous();
}

void DataController::stopReceive(){
    player->stop();
}

void DataController::changeVolumeReceive(const int index){
    player->changeVolume(index);
}

void DataController::changeDurationReceive(const int index){
    player->changeDuration(index);
}

void DataController::setLikeReceive(){
    player->setLike();
}

void DataController::loadSavedItemsReceive(const QString& album_name){

    emit LoadItemsToMainWidget(getListOfPlaylistItems(album_name), album_name);
}

void DataController::setListOfPlaylistsItemsReceive(const QString& album_name) {
    emit SetListOfPlaylistsItems(getListOfPlaylistItems(album_name), album_name);
}

void DataController::likeReceive() {
    emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
}

void DataController::getPlaylistNamesReceive() {
    QStringList list_of_names;
    for (const QString& item : player->getListOfPlaylists())
        list_of_names.append(item);
    emit LoadPlaylistsFromMemory(list_of_names);
}

void DataController::setPlaylistAndCurrentItemReceive(const int index, const QString& album_name) {
    player->stop();
    player->setCurrentPlaylistByName(album_name);
    player->setCurrent(index);
    emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
    player->play();
    emit LoadItemsToMainWidget(getListOfPlaylistItems(album_name), album_name);
}


DataController::~DataController(){}
