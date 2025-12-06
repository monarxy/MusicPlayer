#include "data_controller.h"

DataController::DataController(QObject *parent) :QObject(parent) {
    music_player = new MusicPlayer();
}


void DataController::setMusicPlayer(QStringList list_of_tracks){
    foreach (QString filePath, list_of_tracks)
    {
        music_player->getQPlaylist()->addMedia(QUrl(filePath));
    }
}

MediaPlayer* DataController::getPlayer(){
    return music_player;
}
