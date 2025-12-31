#include "appcontroller.h"

AppController::AppController(DataController* _data_controller, NavigationController* _navigation_controller) {
    data_controller = _data_controller;
    navigation_controller = _navigation_controller;
}

void AppController::setConnections(){
    QObject::connect(data_controller, &DataController::LoadTracksFromMemory, static_cast<Widget*>(navigation_controller->getMainForm()), &Widget::setPlaylist);
    QObject::connect(data_controller, &DataController::LoadPlaylistsFromMemory, static_cast<PlaylistForm*>(navigation_controller->getPlaylistForm()), &PlaylistForm::setListOfPlaylists);
    QObject::connect(static_cast<Widget*>(navigation_controller->getMainForm()), &Widget::PlaylistViewClicked, data_controller, &DataController::setCurrentTrack);
    QObject::connect(static_cast<Widget*>(navigation_controller->getMainForm()), &Widget::PlayClicked, data_controller, &DataController::play);
    QObject::connect(static_cast<Widget*>(navigation_controller->getMainForm()), &Widget::UpdateTracksInAlbum, data_controller, &DataController::setMusicPlayer);
    QObject::connect(static_cast<PlaylistForm*>(navigation_controller->getPlaylistForm()), &PlaylistForm::NewAlbumAddedClicked, data_controller, &DataController::addNewPlaylist);
}

