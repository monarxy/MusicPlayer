#include "navigation_controller.h"

NavigationController::NavigationController(QObject *parent) : QObject(parent){
    current_widget = new Widget();
    QObject::connect(static_cast<Widget*>(current_widget), &Widget::FormClicked, this, &NavigationController::openForm);
    active_widgets["main_form"] = current_widget;

    QWidget* new_form = new PlaylistForm();
    active_widgets["playlist_form"] = new_form;
    QObject::connect(static_cast<PlaylistForm*>(active_widgets["playlist_form"]), &PlaylistForm::FormClicked, this, &NavigationController::openForm);


    new_form = new ListOfPlaylistTracks();
    active_widgets["list_of_playlist_tracks_form"] = new_form;
    QObject::connect(static_cast<ListOfPlaylistTracks*>(active_widgets["list_of_playlist_tracks_form"]), &ListOfPlaylistTracks::FormClicked, this, &NavigationController::openForm);

    new_form = new RadioForm();
    active_widgets["radio_form"] = new_form;
    QObject::connect(static_cast<RadioForm*>(active_widgets["radio_form"]), &RadioForm::FormClicked, this, &NavigationController::openForm);

    new_form = new ListOfRadioPlaylistItems();
    active_widgets["list_of_radioplaylist_items_form"] = new_form;
    QObject::connect(static_cast<ListOfRadioPlaylistItems*>(active_widgets["list_of_radioplaylist_items_form"]), &ListOfRadioPlaylistItems::FormClicked, this, &NavigationController::openForm);
}

void NavigationController::openForm(const QString& form_name){
    current_widget->close();
    if (active_widgets[form_name] != nullptr){
        current_widget = active_widgets[form_name];
        current_widget->show();
    }
}

QWidget* NavigationController::getForm(const QString& form_name){
    if (active_widgets[form_name] != nullptr){
        return active_widgets[form_name];
    }

}


NavigationController::~NavigationController()
{
    for (const auto& pair : active_widgets){
        delete pair.second;
    }
}




