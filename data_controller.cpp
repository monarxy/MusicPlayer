#include <QDir>
#include "data_controller.h"

DataController::DataController(QObject *parent, MediaPlayer* _music_player) :QObject(parent) {
    music_player =_music_player;
}


void DataController::setMusicPlayer(QStringList list_of_tracks){
    foreach (QString filePath, list_of_tracks)
    {
        //music_player->getPlaylist()->
        music_player->getQPlaylist()->addMedia(QUrl(filePath));
    }
}

MediaPlayer* DataController::getPlayer(){
    return music_player;
}

void DataController::loadSavedTracks(){
    std::vector<MediaData*> vector_of_items = music_player->getPlaylist("")->getListOfItems();
    QStringList list_of_names;
    foreach (MediaData* item, vector_of_items)
        list_of_names.append(QDir(item->getPath()).dirName());
    emit LoadTracksFromMemory(list_of_names, "");
}

void DataController::setCurrentTrack(int index){
    music_player->setCurrent(index);
}

void DataController::play(){
    music_player->play();
}

DataController::~DataController(){
}
