#include <QDir>
#include "data_controller.h"

DataController::DataController(QObject *parent, MediaPlayer* _music_player) :QObject(parent) {
    music_player =_music_player;
}


void DataController::setMusicPlayer(const QStringList& list_of_tracks){
    foreach (QString filePath, list_of_tracks)
    {
        music_player->getCurrentPlaylist()->setListOfItems(new SongData(filePath, false));
        music_player->test();
    }
}

MediaPlayer* DataController::getPlayer(){
    return music_player;
}

void DataController::loadSavedTracks(const QString& album_name){

    const QStringList& list_of_tracks = getPlaylistItems(album_name);
    emit LoadTracksFromMemory(list_of_tracks, album_name);
}

void DataController::setListOfPlaylistsItems(const QString& album_name){

    const QStringList& list_of_tracks = getPlaylistItems(album_name);
    emit SetListOfPlaylistsItems(list_of_tracks, album_name);
}

void DataController::getPlaylistNames(){
    QVector<QString> vector_of_items = music_player->getListOfPlaylists();
    QStringList list_of_names;
    foreach (QString item, vector_of_items)
        list_of_names.append(item);
    emit LoadPlaylistsFromMemory(list_of_names);
}

QStringList DataController::getPlaylistItems(const QString &playlist_name){
    QVector<MediaData*> vector_of_items = music_player->getPlaylist(playlist_name)->getListOfItems();
    QStringList list_of_names;
    foreach (MediaData* item, vector_of_items)
        list_of_names.append(QDir(item->getPath()).dirName());
    return list_of_names;
}

void DataController::setCurrentTrack(const int& index){
    music_player->setCurrent(index);
}

void DataController::addNewPlaylist(const QString& album_name){
    music_player->addPlaylist(album_name);
    music_player->test();
}

void DataController::play(){
    music_player->play();
}

DataController::~DataController(){
}
