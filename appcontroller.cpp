#include "appcontroller.h"

AppController::AppController(DataController* _data_controller, NavigationController* _navigation_controller) {
    data_controller = _data_controller;
    navigation_controller = _navigation_controller;
}

void AppController::setConnections(){
    QWidget* main_form = navigation_controller->getMainForm();
    QObject::connect(data_controller, &DataController::LoadTracksFromMemory, static_cast<Widget*>(main_form), &Widget::setPlaylist);
    QObject::connect(static_cast<Widget*>(main_form), &Widget::PlaylistViewClicked, data_controller, &DataController::setCurrentTrack);
    QObject::connect(static_cast<Widget*>(main_form), &Widget::PlayClicked, data_controller, &DataController::play);
    QObject::connect(static_cast<Widget*>(main_form), &Widget::UpdateTracksInAlbum, data_controller, &DataController::setMusicPlayer);
}

