#include "media_connections_controller.h"

MediaConnectionsController::MediaConnectionsController(DataController* _data_controller, NavigationController* _navigation_controller) :
    data_controller(_data_controller), navigation_controller(_navigation_controller){}


void MediaConnectionsController::setConnections(){
    QObject::connect(data_controller, &DataController::LoadItemsToMainWidget, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setPlaylist);
    QObject::connect(data_controller, &DataController::LoadPlaylistsFromMemory, static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::setListOfPlaylists);
    QObject::connect(data_controller, &DataController::LikeStatusSignal, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setLikeButton);
    QObject::connect(data_controller, &DataController::SetNameOfCurrentItemToMainWidget, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setItemName);
    QObject::connect(data_controller, &DataController::SetIndexOfCurrentItemToMainWidget, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setCurrentItem);
    QObject::connect(data_controller, &DataController::EnableAddAndDeleteButtons, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::showAddButtons);
    QObject::connect(data_controller, &DataController::DisableAddAndDeleteButtons, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::hideAddButtons);
    QObject::connect(data_controller, &DataController::SetListOfPlaylistsItems, static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::setItems);
    QObject::connect(data_controller, &DataController::SetDurationToMainWidget, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setSliderRangeAfterSwitchingPlayers);
    QObject::connect(data_controller, &DataController::UpdateCurrentItemInMainWidget, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::increaseCurrentItem);
    QObject::connect(data_controller, &DataController::SetPictureToMainWidget, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setPicture);

    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlaylistViewClicked, data_controller, &DataController::setCurrentItemByIndex);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlaylistViewClicked, data_controller, &DataController::likeReceive);

    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlayClicked, data_controller, &DataController::playReceive);
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
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::SliderUpdated, data_controller, &DataController::automaticallyNextReceive);

    for (const MediaPlayer* item : data_controller->getListOfPlayers()) {
        QObject::connect(item->getPlayer(), &QMediaPlayer::positionChanged, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::updateSlider);
        QObject::connect(item->getPlayer(), &QMediaPlayer::durationChanged, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setSliderRange);
    }

    QObject::connect(static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::NewAlbumAddedClicked, data_controller, &DataController::addNewPlaylist);
    QObject::connect(static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::ListOfPlaylistsTracksClicked, data_controller, &DataController::setListOfPlaylistsItemsReceive);
    QObject::connect(static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::FavouritePlaylistClicked, data_controller, &DataController::setListOfFavouritePlaylistItemsReceive);
    QObject::connect(static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::ShowDeleteButtonOnItemsForm, static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::showDeleteButton);
    QObject::connect(static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::HideDeleteButtonOnItemsForm, static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::hideDeleteButton);

    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::ItemsAddedToPlaylist, data_controller, &DataController::addItemsToPlaylist);
    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::ItemsListClicked, data_controller, &DataController::setPlaylistAndCurrentItemReceive);
    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::DeletePlaylistClicked, data_controller, &DataController::deletePlaylistReceive);
    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::UpdateListOfPlaylists, data_controller, &DataController::getPlaylistNamesReceive);
}
