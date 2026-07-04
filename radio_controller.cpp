#include "radio_controller.h"

RadioController::RadioController(QObject *parent, RadioPlayer* _radio_player) : QObject(parent), radio_player(_radio_player) {}
RadioController::~RadioController(){}

void RadioController::playReceive() {radio_player->play();}
void RadioController::pauseReceive() {radio_player->pause();}
void RadioController::stopReceive() {radio_player->stop();}
void RadioController::nextReceive() {radio_player->next();}
void RadioController::previousReceive() {radio_player->previous();}
const RadioPlayer* RadioController::getPlayer() const { return radio_player;}

void RadioController::getRadiostationsReceive(){
    QStringList list_of_items = radio_player->getListOfRadiostations();
    if (!list_of_items.isEmpty())
        emit LoadItemsToRadioWidgetReceive(list_of_items);
}

void RadioController::setCurrentItemByIndex(const int) {}

void RadioController::loadSavedItemsReceive(const QString&) {

}
void RadioController::changeVolumeReceive(const int) {}

void RadioController::addRadiostationReceive(const QString&) {}
void RadioController::removeRadiostationReceive(const int) {}
