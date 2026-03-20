#include "appcontroller.h"

AppController::AppController(DataController* _data_controller, NavigationController* _navigation_controller) {
    data_controller = _data_controller;
    navigation_controller = _navigation_controller;
}

void AppController::setConnections(){
    QObject::connect(data_controller, &DataController::LoadTracksToMainWidget, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setPlaylist);
    QObject::connect(data_controller, &DataController::LoadPlaylistsFromMemory, static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::setListOfPlaylists);
    QObject::connect(data_controller, &DataController::LikeStatusSignal, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setLikeButton);

    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlaylistViewClicked, data_controller, &DataController::setCurrentTrack);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlaylistViewClicked, data_controller, &DataController::likeReceiver);

    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PlayClicked, data_controller, &DataController::play);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PauseClicked, data_controller, &DataController::pause);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::UpdateTracksInAlbum, data_controller, &DataController::setMusicPlayer);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::NextClicked, data_controller, &DataController::next);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::PreviousClicked, data_controller, &DataController::previous);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::ChangeVolumeClicked, data_controller, &DataController::changeVolume);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::ChangeDurationPositionClicked, data_controller, &DataController::changeDuration);
    QObject::connect(static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::LikeButtonClicked, data_controller, &DataController::setLike);

    QObject::connect(data_controller->getPlayer()->getPlayer(), &QMediaPlayer::positionChanged, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::updateSlider);
    QObject::connect(data_controller->getPlayer()->getPlayer(), &QMediaPlayer::durationChanged, static_cast<Widget*>(navigation_controller->getForm("main_form")), &Widget::setSliderRange);

    QObject::connect(static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::NewAlbumAddedClicked, data_controller, &DataController::addNewPlaylist);
    QObject::connect(static_cast<PlaylistForm*>(navigation_controller->getForm("playlist_form")), &PlaylistForm::ListOfPlaylistsTracksClicked, data_controller, &DataController::setListOfPlaylistsItemsReceiver);

    QObject::connect(data_controller, &DataController::SetListOfPlaylistsItems, static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::setTracks);
    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::TracksAddedToPlaylist, data_controller, &DataController::addTracksToPlaylist);
    QObject::connect(static_cast<ListOfPlaylistTracks*>(navigation_controller->getForm("list_of_playlist_tracks_form")), &ListOfPlaylistTracks::SongsListClicked, data_controller, &DataController::setPlaylistAndCurrentTrackReceiver);
}
