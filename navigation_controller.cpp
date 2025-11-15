#include "navigation_controller.h"
#include "playlistform.h"

NavigationController::NavigationController(){}

void NavigationController::openPlaylistFrom(){
    current_widget->close();
    current_widget = new PlaylistForm();
    current_widget->show();
}

void NavigationController::openMainForm(){
    current_widget = new Widget(nullptr, this);
    current_widget->show();
}


