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
    if (it != players.end())
        player = it->second;

    auto list_of_playlists = player->getListOfPlaylists();
    if (list_of_playlists.size()!=0){
        player->setCurrentPlaylistByName(list_of_playlists[0]);

        if ((player->getCurrentPlaylist()->getListOfItems()).size() != 0){
            player->setCurrent(0);
            emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
            emit LoadItemsToMainWidget(getListOfPlaylistItems(list_of_playlists[0]), list_of_playlists[0]);
        }
        else{
            QStringList empty_list;
            emit LikeStatusSignal(false);
            emit LoadItemsToMainWidget(empty_list, list_of_playlists[0]);
        }
    }
    else{
        QStringList empty_list;
        emit LikeStatusSignal(false);
        emit LoadItemsToMainWidget(empty_list, "");
    }
}

const QVector<MediaPlayer*> DataController::getListOfPlayers() const{
    QVector<MediaPlayer*> vector_of_players;
    for (const auto& pair: players)
        vector_of_players.append(pair.second);
    return vector_of_players;
}
void DataController::setVideoOutput(QVideoWidget* video_widget){
    (static_cast<VideoPlayer*>(player))->setVideoOutput(video_widget);
}

void DataController::addItemsToPlaylist(const QString& album_name, const QStringList& list_of_tracks){
    player->setTracksToPlaylistByName(album_name, list_of_tracks);
    emit LoadItemsToMainWidget(getListOfPlaylistItems(player->getCurrentPlaylist()->getName()), album_name);

}

void DataController::deletePlaylistReceive(const QString& name){
    player->deletePlaylist(name);
    if (player->getCurrentPlaylist() != nullptr){
        emit LoadItemsToMainWidget(getListOfPlaylistItems(player->getCurrentPlaylist()->getName()), player->getCurrentPlaylist()->getName());
        emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
    }
    else{
        QStringList empty_list;
        emit LoadItemsToMainWidget(empty_list, "");
        emit LikeStatusSignal(false);
    }

}

void DataController::deleteItemReceive(){
    player->deleteCurrent();
    if (player->getCurrentItem()!= nullptr){
        emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
        emit SetNameOfCurrentItemToMainWidget(QDir(player->getCurrentItem()->getPath()).dirName());
    }
    else{
        emit LikeStatusSignal(false);
        emit SetNameOfCurrentItemToMainWidget("");
    }
}

QStringList DataController::getListOfPlaylistItems(const QString &playlist_name) const{
    QStringList list_of_names;
    player->getPlaylist(playlist_name);
    for (const MediaData* item : player->getPlaylist(playlist_name)->getListOfItems()){
        list_of_names.append(QDir(item->getPath()).dirName());
        qDebug() << item->getPath();
    }
    return list_of_names;
}

QStringList DataController::getListOfFavouritePlaylistItems() const{
    QStringList list_of_names;
    for (const MediaData* item : player->getFavouritePlaylist()->getListOfItems())
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
    if (player->getCurrentItem() !=nullptr){
        player->next();
        emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
        emit SetNameOfCurrentItemToMainWidget(QDir(player->getCurrentItem()->getPath()).dirName());
    }
}

void DataController::previousReceive(){
    if (player->getCurrentItem() !=nullptr){
        player->previous();
        emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
        emit SetNameOfCurrentItemToMainWidget(QDir(player->getCurrentItem()->getPath()).dirName());
    }
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
    emit SetListOfPlaylistsItems(getListOfPlaylistItems(album_name), album_name, 0);
}

void DataController::setListOfFavouritePlaylistItemsReceive() {
    emit SetListOfPlaylistsItems(getListOfFavouritePlaylistItems(), "Favourite", 1);
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

void DataController::setPlaylistAndCurrentItemReceive(const int index, const QString& album_name, const int is_favourite_playlist) {
    player->stop();

    if (is_favourite_playlist == 0){
        player->setCurrentPlaylistByName(album_name);
        emit LoadItemsToMainWidget(getListOfPlaylistItems(album_name), album_name);
        emit EnableAddAndDeleteButtons();
    }
    else if (is_favourite_playlist == 1){
        player->setFavouritePlaylistAsMain();
        emit LoadItemsToMainWidget(getListOfFavouritePlaylistItems(), album_name);
        emit DisableAddAndDeleteButtons();
    }
    player->setCurrent(index);
    emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
    player->play();
    emit SetNameOfCurrentItemToMainWidget(QDir(player->getCurrentItem()->getPath()).dirName());
    emit SetIndexOfCurrentItemToMainWidget(index);
}


DataController::~DataController(){}
