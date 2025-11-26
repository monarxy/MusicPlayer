#include "navigation_controller.h"
#include "playlistform.h"

NavigationController::NavigationController(DataController *_data_controller){
    data_controller = _data_controller;
}

void NavigationController::openPlaylistForm(){
    current_widget->close();
    current_widget = new PlaylistForm(this, data_controller);
    current_widget->show();
}

void NavigationController::openMainForm(){
    current_widget = new Widget(nullptr, this, data_controller);
    current_widget->show();
}

void NavigationController::openEditForm(){
    current_widget->close();
    current_widget = new EditorForm(nullptr, this);
    current_widget->show();
}

void NavigationController::openListOfPlaylistsForm(){
    current_widget->close();
    current_widget = new ListOfPlaylistTracks(nullptr, this, data_controller);
    current_widget->show();
}



