#include "media_loader.h"

MediaLoader::MediaLoader(){
    settings = new QSettings(ORGANIZATION_NAME, APPLICATION_NAME);
}

MediaLoader::~MediaLoader(){
    delete settings;
}

QVector<Playlist*> MediaLoader::loadSavedItems(const QString& player_type) const{
    QVector<Playlist*> vector_of_loaded_playlists;
    QByteArray json_data = settings->value(player_type).toByteArray(); //player video_player
    QJsonDocument doc = QJsonDocument::fromJson(json_data);
    CoverExtractor cover_extractor;

    QJsonArray playlists = doc["list_of_playlists"].toArray();
    for (const QJsonValue& item : playlists){
        QJsonObject playlist_item = item.toObject();
        Playlist* playlist = new DefaultPlaylist(playlist_item["playlist_name"].toString());
        QJsonArray tracks = playlist_item["items"].toArray();

        for (const QJsonValue& t_item : tracks){
            QJsonObject track_item = t_item.toObject();
            MediaData* track = new MediaData(track_item["name"].toString(), track_item["like_info"].toBool(), cover_extractor.extractCoverUniversal(track_item["name"].toString()));
            playlist->setListOfItems(track);
        }
        vector_of_loaded_playlists.append(playlist);
    }
    return vector_of_loaded_playlists;
}

void MediaLoader::saveItems(const std::map<QString, Playlist*>& list_of_playlists, const QString& player_type) {
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
    settings->setValue(player_type, doc.toJson(QJsonDocument::Compact));
}
