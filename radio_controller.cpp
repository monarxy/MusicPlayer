#include "radio_controller.h"

RadioController::RadioController(QObject *parent, RadioPlayer* _radio_player) : QObject(parent), radio_player(_radio_player) {}
RadioController::~RadioController(){}

void RadioController::playReceive() {radio_player->play();}
void RadioController::pauseReceive() {radio_player->pause();}
void RadioController::stopReceive() {radio_player->stop();}
void RadioController::nextReceive() {
    radio_player->next();
    emit LikeStatusSignal(radio_player->getCurrentItem()->getLikeInfo());
    emit SetNameOfCurrentItemToMainWidget(radio_player->getCurrentItem()->getPath());
    radio_player->play();
}
void RadioController::previousReceive() {
    radio_player->previous();
    emit LikeStatusSignal(radio_player->getCurrentItem()->getLikeInfo());
    emit SetNameOfCurrentItemToMainWidget(radio_player->getCurrentItem()->getPath());
    radio_player->play();
}
const RadioPlayer* RadioController::getPlayer() const { return radio_player;}

void RadioController::getRadiostationsReceive(){
    QStringList list_of_items = radio_player->getListOfRadiostations();
    if (!list_of_items.isEmpty()){
        emit LoadItemsToRadioWidgetReceive(list_of_items);
        radio_player->setCurrent(0);
        radio_player->pause();
        emit LikeStatusSignal(radio_player->getCurrentItem()->getLikeInfo());
        emit SetNameOfCurrentItemToMainWidget(radio_player->getCurrentItem()->getPath());
        emit SetIndexOfCurrentItemToMainWidget(0);
    }
}

void RadioController::setCurrentItemByIndex(const int index) {
    radio_player->setCurrent(index);
    emit SetNameOfCurrentItemToMainWidget(radio_player->getCurrentItem()->getPath());
}

void RadioController::changeVolumeReceive(const int index) {
    radio_player->changeVolume(index);
}

void RadioController::addRadiostationReceive(const QString& name_of_radiostation) {
    radio_player->addRadiostation(name_of_radiostation);
}

void RadioController::setListOfFavouritePlaylistItemsReceive() {
    emit SetListOfPlaylistsItems(getListOfFavouritePlaylistItems());
}

const QStringList RadioController::getListOfFavouritePlaylistItems() const{
    QStringList list_of_names;
    for (const MediaData* item : radio_player->getFavouritePlaylist()->getListOfItems())
        list_of_names.append(QDir(item->getPath()).dirName());
    return list_of_names;
}

const QStringList RadioController::getListOfDefaultPlaylistItems() const{
    QStringList list_of_names;
    for (const MediaData* item : radio_player->getDefaultPlaylist()->getListOfItems())
        list_of_names.append(QDir(item->getPath()).dirName());
    return list_of_names;
}

void RadioController::setPlaylistAndCurrentItemReceive(const int index, const int is_favourite_playlist) {
    radio_player->stop();

    if (is_favourite_playlist == 0){
        radio_player->setDefaultPlaylistAsMain();
        emit LoadItemsToRadioWidgetReceive(getListOfDefaultPlaylistItems());
        emit EnableRadioFormButtons();
    }
    else if (is_favourite_playlist == 1){
        radio_player->setFavouritePlaylistAsMain();
        emit LoadItemsToRadioWidgetReceive(getListOfFavouritePlaylistItems());
        emit DisableRadioFormButtons();
    }
    radio_player->setCurrent(index);
    emit LikeStatusSignal(radio_player->getCurrentItem()->getLikeInfo());
    radio_player->play();
    emit SetNameOfCurrentItemToMainWidget(radio_player->getCurrentItem()->getPath());
    emit SetIndexOfCurrentItemToMainWidget(index);
}

void RadioController::setLikeReceive(){
    radio_player->setLike();
}

void RadioController::likeReceive() {
    emit LikeStatusSignal(radio_player->getCurrentItem()->getLikeInfo());
}

void RadioController::deleteItemReceive(){
    radio_player->deleteCurrent();
    if (radio_player->getCurrentItem() != nullptr){
        emit LikeStatusSignal(radio_player->getCurrentItem()->getLikeInfo());
        emit SetNameOfCurrentItemToMainWidget(radio_player->getCurrentItem()->getPath());
    }
    else{
        emit LikeStatusSignal(false);
        emit SetNameOfCurrentItemToMainWidget("");
    }
}
