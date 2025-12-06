#include "navigation_controller.h"
#include "playlistform.h"

NavigationController::NavigationController(QObject *parent) : QObject(parent){
}

void NavigationController::openPlaylistForm(){
    if (active_widgets["playlist_form"] == nullptr){
        current_widget->close();
        current_widget = new PlaylistForm();
        QObject::connect(static_cast<PlaylistForm*>(current_widget), &PlaylistForm::HomeClicked, this, &NavigationController::openMainForm);
        QObject::connect(static_cast<PlaylistForm*>(current_widget), &PlaylistForm::ListOfPlaylistsTracksClicked, this, &NavigationController::openListOfPlaylistsForm);
        active_widgets["playlist_form"] = current_widget;
        current_widget->show();
    }
    else{
        current_widget->close();
        current_widget = active_widgets["playlist_form"];
        current_widget->show();
    }
}

void NavigationController::openMainForm(){
    if (active_widgets["main_form"] == nullptr){
        current_widget = new Widget();
        QObject::connect(static_cast<Widget*>(current_widget), &Widget::PlaylistFormClicked, this, &NavigationController::openPlaylistForm);
        QObject::connect(static_cast<Widget*>(current_widget), &Widget::EditorFormClicked, this, &NavigationController::openEditForm);
        active_widgets["main_form"] = current_widget;
        current_widget->show();
    }
    else{

        current_widget->close();
        current_widget = active_widgets["main_form"];
        current_widget->show();
    }
}

void NavigationController::openEditForm(){
    if (active_widgets["editor_form"] == nullptr){
        current_widget->close();
        current_widget = new EditorForm(nullptr);
        QObject::connect(static_cast<EditorForm*>(current_widget), &EditorForm::HomeClicked, this, &NavigationController::openMainForm);
        active_widgets["editor_form"] = current_widget;
        current_widget->show();
    }
    else{
        current_widget->close();
        current_widget = active_widgets["editor_form"];
        current_widget->show();
    }
}

void NavigationController::openListOfPlaylistsForm(QString album_name){
    if (active_widgets["list_of_playlists_form"] == nullptr){
        current_widget->close();
        current_widget = new ListOfPlaylistTracks(nullptr);
        active_widgets["list_of_playlists_form"] = current_widget;
        static_cast<ListOfPlaylistTracks*>(current_widget)->setLabelText(album_name);
        current_widget->show();
    }
    else{
        current_widget->close();
        current_widget = active_widgets["list_of_playlists_form"];
        static_cast<ListOfPlaylistTracks*>(current_widget)->setLabelText(album_name);
        current_widget->show();
    }

}

NavigationController::~NavigationController()
{
}




