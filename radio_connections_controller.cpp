#include "radio_connections_controller.h"

RadioConnectionsController::RadioConnectionsController(RadioController* _radio_controller, NavigationController* _navigation_controller) :
    radio_controller(_radio_controller) , navigation_controller(_navigation_controller){}

void RadioConnectionsController::setConnections(){

    QObject::connect(radio_controller, &RadioController::LoadItemsToRadioWidgetReceive, static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::setPlaylist);
    QObject::connect(radio_controller, &RadioController::SetListOfPlaylistsItems, static_cast<ListOfRadioPlaylistItems*>(navigation_controller->getForm("list_of_radioplaylist_items_form")), &ListOfRadioPlaylistItems::setPlaylist);
    QObject::connect(radio_controller, &RadioController::LikeStatusSignal, static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::setLikeButton);
    QObject::connect(radio_controller, &RadioController::SetIndexOfCurrentItemToMainWidget, static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::setCurrentIndex);
    QObject::connect(radio_controller, &RadioController::SetNameOfCurrentItemToMainWidget, static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::setCurrentName);
    QObject::connect(radio_controller, &RadioController::DisableRadioFormButtons, static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::disableButtonsForFavouritePlaylist);
    QObject::connect(radio_controller, &RadioController::EnableRadioFormButtons, static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::enableButtonsForFavouritePlaylist);

    QObject::connect(static_cast<ListOfRadioPlaylistItems*>(navigation_controller->getForm("list_of_radioplaylist_items_form")), &ListOfRadioPlaylistItems::ItemsListClicked, radio_controller, &RadioController::setPlaylistAndCurrentItemReceive);
    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::MuteRadioPlayer, radio_controller, &RadioController::pauseReceive);

            QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlayClicked, radio_controller, &RadioController::pauseReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::PlayClicked, radio_controller, &RadioController::playReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::PauseClicked, radio_controller, &RadioController::pauseReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::StopClicked, radio_controller, &RadioController::stopReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::NextClicked, radio_controller, &RadioController::nextReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::PreviousClicked, radio_controller, &RadioController::previousReceive);
    //QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::PlayClicked, data_controller, &DataController::pauseReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::RadioPlaylistViewClicked, radio_controller, &RadioController::setCurrentItemByIndex);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::RadioPlaylistViewClicked, radio_controller, &RadioController::likeReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::NewRadiostationAddedClicked, radio_controller, &RadioController::addRadiostationReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::DeleteRadiostationClicked, radio_controller, &RadioController::deleteItemReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::FavouritePlaylistClicked, radio_controller, &RadioController::setListOfFavouritePlaylistItemsReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::LikeButtonClicked, radio_controller, &RadioController::setLikeReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::ItemsListClicked, radio_controller, &RadioController::setPlaylistAndCurrentItemReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::ChangeVolumeClicked, radio_controller, &RadioController::changeVolumeReceive);
}
