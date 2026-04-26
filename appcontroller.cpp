#include "appcontroller.h"

AppController::AppController(DataController* _data_controller, NavigationController* _navigation_controller) {
    data_controller = _data_controller;
    navigation_controller = _navigation_controller;
}

void AppController::setConnections(){
    QObject::connect(data_controller, &DataController::LoadItemsToMainWidget, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setPlaylist);
    QObject::connect(data_controller, &DataController::LoadPlaylistsFromMemory, static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::setListOfPlaylists);
    QObject::connect(data_controller, &DataController::LikeStatusSignal, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setLikeButton);

    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlaylistViewClicked, data_controller, &DataController::setCurrentItemByIndex);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlaylistViewClicked, data_controller, &DataController::likeReceive);

    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlayClicked, data_controller, &DataController::playReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PauseClicked, data_controller, &DataController::pauseReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::UpdateTracksInAlbum, data_controller, &DataController::setItemsToPlayer);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::NextClicked, data_controller, &DataController::nextReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PreviousClicked, data_controller, &DataController::previousReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::ChangeVolumeClicked, data_controller, &DataController::changeVolumeReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::ChangeDurationPositionClicked, data_controller, &DataController::changeDurationReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::LikeButtonClicked, data_controller, &DataController::setLikeReceive);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlayerChanged, data_controller, &DataController::setCurrentPlayerByIndex);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::UpdateListOfPlaylists, data_controller, &DataController::getPlaylistNamesReceive);
        QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::SetVideoOutput, data_controller, &DataController::setVideoOutput);

    QObject::connect(data_controller->getPlayer()->getPlayer(), &QMediaPlayer::positionChanged, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::updateSlider);
    QObject::connect(data_controller->getPlayer()->getPlayer(), &QMediaPlayer::durationChanged, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setSliderRange);

    QObject::connect(static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::NewAlbumAddedClicked, data_controller, &DataController::addNewPlaylist);
    QObject::connect(static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::ListOfPlaylistsTracksClicked, data_controller, &DataController::setListOfPlaylistsItemsReceive);

    QObject::connect(data_controller, &DataController::SetListOfPlaylistsItems, static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::setItems);
    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::ItemsAddedToPlaylist, data_controller, &DataController::addItemsToPlaylist);
    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::ItemsListClicked, data_controller, &DataController::setPlaylistAndCurrentItemReceive);
}
