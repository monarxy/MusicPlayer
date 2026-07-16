#include "appcontroller.h"

AppController::AppController(DataController* _data_controller, RadioController* _radio_сontroller, NavigationController* _navigation_controller) {
    data_controller = _data_controller;
    radio_controller = _radio_сontroller;
    navigation_controller = _navigation_controller;
}

void AppController::setConnections(){
    QObject::connect(data_controller, &DataController::LoadItemsToMainWidget, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setPlaylist);
    QObject::connect(data_controller, &DataController::LoadPlaylistsFromMemory, static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::setListOfPlaylists);
    QObject::connect(data_controller, &DataController::LikeStatusSignal, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setLikeButton);
    QObject::connect(data_controller, &DataController::SetNameOfCurrentItemToMainWidget, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setItemName);
    QObject::connect(data_controller, &DataController::SetIndexOfCurrentItemToMainWidget, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setCurrentItem);
    QObject::connect(data_controller, &DataController::EnableAddAndDeleteButtons, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::showAddButtons);
    QObject::connect(data_controller, &DataController::DisableAddAndDeleteButtons, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::hideAddButtons);
    QObject::connect(data_controller, &DataController::SetListOfPlaylistsItems, static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::setItems);

    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlaylistViewClicked, data_controller, &DataController::setCurrentItemByIndex);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlaylistViewClicked, data_controller, &DataController::likeReceive);

    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlayClicked, data_controller, &DataController::playReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlayClicked, radio_controller, &RadioController::pauseReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PauseClicked, data_controller, &DataController::pauseReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::StopClicked, data_controller, &DataController::stopReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::UpdateTracksInAlbum, data_controller, &DataController::setItemsToPlayer);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::NextClicked, data_controller, &DataController::nextReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PreviousClicked, data_controller, &DataController::previousReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::ChangeVolumeClicked, data_controller, &DataController::changeVolumeReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::ChangeDurationPositionClicked, data_controller, &DataController::changeDurationReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::LikeButtonClicked, data_controller, &DataController::setLikeReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlayerChanged, data_controller, &DataController::setCurrentPlayerByIndex);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlayerChanged, static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::setPlayer);

    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::UpdateListOfPlaylists, data_controller, &DataController::getPlaylistNamesReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::SetVideoOutput, data_controller, &DataController::setVideoOutput);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::DeleteItemClicked, data_controller, &DataController::deleteItemReceive);

    for (const MediaPlayer* item : data_controller->getListOfPlayers()) {
        QObject::connect(item->getPlayer(), &QMediaPlayer::positionChanged, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::updateSlider);
        QObject::connect(item->getPlayer(), &QMediaPlayer::durationChanged, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setSliderRange);
    }

    QObject::connect(static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::NewAlbumAddedClicked, data_controller, &DataController::addNewPlaylist);
    QObject::connect(static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::ListOfPlaylistsTracksClicked, data_controller, &DataController::setListOfPlaylistsItemsReceive);
    QObject::connect(static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::FavouritePlaylistClicked, data_controller, &DataController::setListOfFavouritePlaylistItemsReceive);

    QObject::connect(radio_controller, &RadioController::LoadItemsToRadioWidgetReceive, static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::setPlaylist);
    QObject::connect(radio_controller, &RadioController::SetListOfPlaylistsItems, static_cast<ListOfRadioPlaylistItems*>(navigation_controller->getForm("list_of_radioplaylist_items_form")), &ListOfRadioPlaylistItems::setPlaylist);
    QObject::connect(radio_controller, &RadioController::LikeStatusSignal, static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::setLikeButton);
    QObject::connect(radio_controller, &RadioController::SetIndexOfCurrentItemToMainWidget, static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::setCurrentIndex);
    QObject::connect(radio_controller, &RadioController::SetNameOfCurrentItemToMainWidget, static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::setCurrentName);
    QObject::connect(radio_controller, &RadioController::DisableRadioFormButtons, static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::disableButtonsForFavouritePlaylist);
    QObject::connect(radio_controller, &RadioController::EnableRadioFormButtons, static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::enableButtonsForFavouritePlaylist);

    QObject::connect(static_cast<ListOfRadioPlaylistItems*>(navigation_controller->getForm("list_of_radioplaylist_items_form")), &ListOfRadioPlaylistItems::ItemsListClicked, radio_controller, &RadioController::setPlaylistAndCurrentItemReceive);

    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::PlayClicked, radio_controller, &RadioController::playReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::PauseClicked, radio_controller, &RadioController::pauseReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::StopClicked, radio_controller, &RadioController::stopReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::NextClicked, radio_controller, &RadioController::nextReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::PreviousClicked, radio_controller, &RadioController::previousReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::PlayClicked, data_controller, &DataController::pauseReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::RadioPlaylistViewClicked, radio_controller, &RadioController::setCurrentItemByIndex);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::RadioPlaylistViewClicked, radio_controller, &RadioController::likeReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::NewRadiostationAddedClicked, radio_controller, &RadioController::addRadiostationReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::DeleteRadiostationClicked, radio_controller, &RadioController::deleteItemReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::FavouritePlaylistClicked, radio_controller, &RadioController::setListOfFavouritePlaylistItemsReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::LikeButtonClicked, radio_controller, &RadioController::setLikeReceive);
    QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::ItemsListClicked, radio_controller, &RadioController::setPlaylistAndCurrentItemReceive);
     QObject::connect(static_cast<RadioForm*>(navigation_controller->getForm("radio_form")), &RadioForm::ChangeVolumeClicked, radio_controller, &RadioController::changeVolumeReceive);


    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::ItemsAddedToPlaylist, data_controller, &DataController::addItemsToPlaylist);
    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::ItemsListClicked, data_controller, &DataController::setPlaylistAndCurrentItemReceive);
    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::MuteRadioPlayer, radio_controller, &RadioController::pauseReceive);
    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::DeletePlaylistClicked, data_controller, &DataController::deletePlaylistReceive);
    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::UpdateListOfPlaylists, data_controller, &DataController::getPlaylistNamesReceive);
}
