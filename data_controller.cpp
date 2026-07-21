#include <QDir>
#include "data_controller.h"


DataController::DataController(QObject *parent, MusicPlayer* _music_player, VideoPlayer* _video_player) :QObject(parent),
    music_player(_music_player), video_player(_video_player), player_type(0) {
    player = music_player;
}


void DataController::setItemsToPlayer(const QStringList& list_of_tracks){
    player->setTracksToCurrentPlaylist(list_of_tracks);
}

const MediaPlayer* DataController::getPlayer() const{
    return player;
}

void DataController::setCurrentPlayerByIndex(const int index){
    player_type = index;
    player->stop();
    if (index == 0)
        player = music_player;
    else if (index == 1)
        player = video_player;

    auto list_of_playlists = player->getListOfPlaylists();
    if (list_of_playlists.size()!=0){
        player->setCurrentPlaylistByName(list_of_playlists[0]);

        if ((player->getCurrentPlaylist()->getListOfItems()).size() != 0){
            player->setCurrent(0);
            emit SetDurationToMainWidget(player->getPlayer()->duration());
            emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
            emit LoadItemsToMainWidget(getListOfPlaylistItems(list_of_playlists[0]), list_of_playlists[0]);
            if (player_type == 0)
                emit SetPictureToMainWidget(player->getCurrentItem()->getPicture());
        }
        else{
            QStringList empty_list;
            emit SetDurationToMainWidget(0);
            emit LikeStatusSignal(false);
            emit LoadItemsToMainWidget(empty_list, list_of_playlists[0]);
        }
    }
    else{
        QStringList empty_list;
        emit LikeStatusSignal(false);
        emit LoadItemsToMainWidget(empty_list, "");
    }

    emit EnableAddAndDeleteButtons();
}

const QVector<MediaPlayer*> DataController::getListOfPlayers() const{
    QVector<MediaPlayer*> vector_of_players;
    vector_of_players.append(music_player);
    vector_of_players.append(video_player);
    return vector_of_players;
}
void DataController::setVideoOutput(QVideoWidget* video_widget){
    video_player->setVideoOutput(video_widget);
}

void DataController::addItemsToPlaylist(const QString& album_name, const QStringList& list_of_tracks){
    player->setTracksToPlaylistByName(album_name, list_of_tracks);
    emit LoadItemsToMainWidget(getListOfPlaylistItems(player->getCurrentPlaylist()->getName()), album_name);

}

void DataController::deletePlaylistReceive(const QString& name){
    int current_item_in_deleting_playlist = 0;
    for (MediaData* item : player->getPlaylist(name)->getListOfItems())
        if (item == player->getCurrentItem())
            current_item_in_deleting_playlist = 1;

    if (player->getCurrentPlaylist() == player->getFavouritePlaylist() && current_item_in_deleting_playlist == 1)
        player->setCurrent(0);

    player->deletePlaylist(name);
    if (player->getCurrentPlaylist() != nullptr){
        if (player->getCurrentPlaylist() == player->getFavouritePlaylist()){
            emit LoadItemsToMainWidget(getListOfFavouritePlaylistItems(), "Favourite");
            if (player->getCurrentPlaylist()->getListOfItems().size()!=0)
                if (player->getCurrentItem()!=nullptr)
                    emit SetNameOfCurrentItemToMainWidget(player->getCurrentItem()->getPath());
        }
        else
            emit LoadItemsToMainWidget(getListOfPlaylistItems(player->getCurrentPlaylist()->getName()), player->getCurrentPlaylist()->getName());
        if (player->getCurrentItem()!=nullptr)
            emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
        if (player_type == 0 && player->getCurrentItem()!=nullptr)
            emit SetPictureToMainWidget(player->getCurrentItem()->getPicture());
    }
    else{
        QStringList empty_list;
        emit LoadItemsToMainWidget(empty_list, "");
        emit LikeStatusSignal(false);
        if (player_type == 0)
            emit SetPictureToMainWidget(QPixmap());
    }


}

void DataController::deleteItemReceive(){
    player->deleteCurrent();
    if (player->getCurrentItem()!= nullptr){
        emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
        emit SetNameOfCurrentItemToMainWidget(QDir(player->getCurrentItem()->getPath()).dirName());
        if (player_type == 0)
            emit SetPictureToMainWidget(player->getCurrentItem()->getPicture());
    }
    else{
        emit LikeStatusSignal(false);
        emit SetNameOfCurrentItemToMainWidget("");
        if (player_type == 0)
            emit SetPictureToMainWidget(QPixmap());
    }
}

QStringList DataController::getListOfPlaylistItems(const QString &playlist_name) const{
    QStringList list_of_names;
    player->getPlaylist(playlist_name);
    for (const Data* item : player->getPlaylist(playlist_name)->getListOfItems())
        list_of_names.append(QDir(item->getPath()).dirName());
    return list_of_names;
}

const QStringList DataController::getListOfFavouritePlaylistItems() const{
    QStringList list_of_names;
    for (const Data* item : player->getFavouritePlaylist()->getListOfItems())
        list_of_names.append(QDir(item->getPath()).dirName());
    return list_of_names;
}


void DataController::setCurrentItemByIndex(const int index){
    player->setCurrent(index);
    if (player_type == 0)
        emit SetPictureToMainWidget(player->getCurrentItem()->getPicture());
}

void DataController::addNewPlaylist(const QString& album_name){
    player->addPlaylist(album_name);
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
        if (player_type == 0)
            emit SetPictureToMainWidget(player->getCurrentItem()->getPicture());
    }
}

void DataController::automaticallyNextReceive(const qint64 position, const int is_last_item){
    if (player == nullptr || player->getPlayer() == nullptr) {
        return;
    }
    qint64 duration = player->getPlayer()->duration();
    if (duration - position <= 1000 && duration != 0){
        if (is_last_item == 0){
            if (player->getCurrentItem() != nullptr){
                player->next();
                emit UpdateCurrentItemInMainWidget();
            }
        }
        else if (is_last_item == 1)
            player->setCurrent((player->getCurrentPlaylist()->getListOfItems().size())-1);
        emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
        emit SetNameOfCurrentItemToMainWidget(QDir(player->getCurrentItem()->getPath()).dirName());
        if (player_type == 0)
            emit SetPictureToMainWidget(player->getCurrentItem()->getPicture());
    }
}

void DataController::previousReceive(){
    if (player->getCurrentItem() !=nullptr){
        player->previous();
        emit LikeStatusSignal(player->getCurrentItem()->getLikeInfo());
        emit SetNameOfCurrentItemToMainWidget(QDir(player->getCurrentItem()->getPath()).dirName());
        if (player_type == 0)
            emit SetPictureToMainWidget(player->getCurrentItem()->getPicture());
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

void DataController::setListOfPlaylistsItemsReceive(const QString& album_name) {
    if (album_name == "") emit SetListOfPlaylistsItems(getListOfPlaylistItems(album_name), "Default Album", 0);
    else emit SetListOfPlaylistsItems(getListOfPlaylistItems(album_name), album_name, 0);
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
    if (player_type == 0)
        emit SetPictureToMainWidget(player->getCurrentItem()->getPicture());
}


DataController::~DataController(){}
