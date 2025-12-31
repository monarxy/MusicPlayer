#include "playlist.h"

Playlist::Playlist(QString _name){
    playlist_name = _name;
    q_playlist = new QMediaPlaylist();
}

Playlist::Playlist(){
    playlist_name = "";
}

QVector<MediaData*> Playlist::getListOfItems(){
    return playlist_items;
}

void Playlist::setListOfItems(MediaData* item){
    playlist_items.push_back(item);
    q_playlist->addMedia(QUrl(item->getPath()));
}

QString Playlist::getName(){
    return playlist_name;
}

void Playlist::setName(QString _playlist_name){
    playlist_name = _playlist_name;
}

QMediaPlaylist* Playlist::getQPlaylist(){
    return q_playlist;
}

QDataStream &operator<<(QDataStream &out, Playlist* const &playlist){
    out << playlist->getName() << playlist->getListOfItems();
    return out;
}

QDataStream &operator>>(QDataStream &in, Playlist* &playlist){
    QString playlist_name;
    QVector<MediaData*> playlist_items;
    in >> playlist_name >> playlist_items;
    playlist->setName(playlist_name);
    foreach (MediaData* item, playlist_items)
        playlist->setListOfItems(item);
    return in;
}

QDataStream &operator<<(QDataStream &out, const QVector<MediaData*> &items) {
    out << items.size();
    for (MediaData* item : items) {
        out << item;
    }
    return out;
}

QDataStream &operator>>(QDataStream &in, QVector<MediaData*> &items) {
    int size;
    in >> size;

    items.clear();
    items.reserve(size);

    for (int i = 0; i < size; ++i) {
        MediaData* item;
        in >> item;
        items.append(item);
    }

    return in;
}

QDataStream &operator<<(QDataStream &out, MediaData* const &item) {
    if (dynamic_cast<SongData*>(item) != nullptr)
        out << "song";
    else if(dynamic_cast<VideoData*>(item) != nullptr)
        out << "video";
    out << item->getPath() << item->getLikeInfo();
    return out;
}

QDataStream &operator>>(QDataStream &in, MediaData* &item) {
    QString type;
    in >> type;
    QString name;
    bool isLiked;
    in >> name >> isLiked;

    if (type == "song")
        item = new SongData(name, isLiked);
    else if (type == "video")
        item = new VideoData(name, isLiked);
    return in;
}

