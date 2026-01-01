#include "tracks_loader.h"

TracksLoader::TracksLoader(){
    settings = new QSettings(ORGANIZATION_NAME, APPLICATION_NAME);
}

QVector<Playlist*> TracksLoader::loadSavedTracks() const{
    QVector<Playlist*> vector_of_loaded_playlists;
    QByteArray json_data = settings->value("player").toByteArray();
    QJsonDocument doc = QJsonDocument::fromJson(json_data);

    QJsonArray playlists = doc["list_of_playlists"].toArray();
    for (const QJsonValue& item : playlists){
        QJsonObject playlist_item = item.toObject();
        Playlist* playlist = new Playlist(playlist_item["playlist_name"].toString());
        QJsonArray tracks = playlist_item["items"].toArray();

        for (const QJsonValue& t_item : tracks){
            QJsonObject track_item = t_item.toObject();
            MediaData* track = new SongData(track_item["name"].toString(), track_item["like_info"].toBool());
            playlist->setListOfItems(track);
        }
        vector_of_loaded_playlists.append(playlist);
    }
    return vector_of_loaded_playlists;
}

void TracksLoader::saveTracks(const std::map<QString, Playlist*>& list_of_playlists) const{
    QJsonObject player;
    QJsonArray array_of_playlists;
    for (const auto& [key, value] : list_of_playlists ){
        QJsonObject playlist;
        playlist["playlist_name"] = value->getName();

        QJsonArray tracks_array;
        for (const MediaData* item : value->getListOfItems()){
            QJsonObject json_item;
            json_item["name"] = item->getPath();
            json_item["like_info"] = item->getLikeInfo();
            tracks_array.append(json_item);
        }
        playlist["items"] = tracks_array;
        array_of_playlists.append(playlist);
    }
    player["list_of_playlists"] = array_of_playlists;
    QJsonDocument doc(player);
    settings->setValue("player", doc.toJson(QJsonDocument::Compact));
}
