#include "radio_controller.h"

RadioController::RadioController(QObject *parent, RadioPlayer* _radio_player) : QObject(parent), radio_player(_radio_player) {}
RadioController::~RadioController(){}

void RadioController::playReceive() {radio_player->play();}
void RadioController::pauseReceive() {}
void RadioController::stopReceive() {}
void RadioController::nextReceive() {}
void RadioController::previousReceive() {}
const MediaPlayer* RadioController::getPlayer() const {}
void RadioController::setCurrentItemByIndex(const int) {}

void RadioController::loadSavedItemsReceive(const QString&) {}
void RadioController::changeVolumeReceive(const int) {}

void RadioController::addRadiostationReceive(const QString&) {}
void RadioController::removeRadiostationReceive(const int) {}
