#include "playlist.h"

Playlist::Playlist(const QString& _name){
    playlist_name = _name;
    q_playlist = new QMediaPlaylist();
}

Playlist::Playlist(){
    playlist_name = "";
}

Playlist::~Playlist(){
    for (const auto item : playlist_items){
        delete item;
    }

    delete q_playlist;
}

QVector<MediaData*> Playlist::getListOfItems() const{
    return playlist_items;
}

void Playlist::setListOfItems(MediaData* item){
    playlist_items.push_back(item);
    q_playlist->addMedia(QUrl(item->getPath()));

}

QString Playlist::getName() const{
    return playlist_name;
}

void Playlist::setName(const QString& _playlist_name){
    playlist_name = _playlist_name;
}

QMediaPlaylist* Playlist::getQPlaylist() const{
    return q_playlist;
}


