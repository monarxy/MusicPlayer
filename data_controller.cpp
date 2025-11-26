#include "data_controller.h"

DataController::DataController(){
    music_player = new MusicPlayer();
}


void DataController::setMusicPlayer(QStringList list_of_tracks){
    foreach (QString filePath, list_of_tracks)
    {
        music_player->getQPlaylist()->addMedia(QUrl(filePath));
        music_player->getPlaylist()->setListOfItems(new SongData(filePath));
    }
}

MediaPlayer* DataController::getPlayer(){
    return music_player;
}
