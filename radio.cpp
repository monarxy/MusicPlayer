#include "radio.h"

RadioPlayer::RadioPlayer(QObject* parent, RadioLoader* _serializer) : QObject(parent), serializer(_serializer),
    current_item(nullptr), playlist(nullptr){
    BASS_Init(-1, 44100, BASS_DEVICE_3D, 0, NULL);
    favourite_playlist = new RadioFavouritePlaylist();
}

void RadioPlayer::play(){
    if (!playlist->getListOfItems().isEmpty())
        if (current_item != nullptr)
            BASS_ChannelPlay(str, false);
}

void RadioPlayer::pause(){
    if (!playlist->getListOfItems().isEmpty())
        if (current_item != nullptr)
            BASS_ChannelPause(str);
}

void RadioPlayer::stop(){
    if (!playlist->getListOfItems().isEmpty())
        if (current_item != nullptr)
            BASS_ChannelStop(str);
}

void RadioPlayer::next(){
    if (playlist->getListOfItems().size() != 0)
        if (current_item != nullptr){
            BASS_ChannelStop(str);
            MediaData* next_current_item = playlist->getNextItem(current_item);
            if (next_current_item != nullptr){
                current_item = next_current_item;
                str = BASS_StreamCreateURL(current_item->getPath().toUtf8().constData(), 0, 0, NULL, 0);
            }
            BASS_ChannelPlay(str, false);
        }
}

void RadioPlayer::previous(){
    if (playlist->getListOfItems().size() != 0)
        if (current_item != nullptr){
            BASS_ChannelStop(str);
            MediaData* prev_current_item = playlist->getPreviousItem(current_item);
            if (prev_current_item != nullptr){
                current_item = prev_current_item;
                str = BASS_StreamCreateURL(current_item->getPath().toUtf8().constData(), 0, 0, NULL, 0);
            }
            BASS_ChannelPlay(str, false);
        }
}

void RadioPlayer::setCurrent(const int index){
    BASS_ChannelStop(str);
    current_item = (playlist->getListOfItems())[index];
    str = BASS_StreamCreateURL(current_item->getPath().toUtf8().constData(), 0, 0, NULL, 0);
    BASS_ChannelPlay(str, false);
}

const QStringList RadioPlayer::getListOfRadiostations() const {
    QStringList _list_of_radiostations;
    for (MediaData* radiostation : playlist->getListOfItems())
        _list_of_radiostations.append(radiostation->getPath());
    return _list_of_radiostations;
}

void RadioPlayer::addRadiostation(const QString& name_of_radiostation){
    MediaData* new_radiostation = new RadioData(name_of_radiostation);
    playlist->setListOfItems(new_radiostation);
    if (playlist->getListOfItems().size() == 1){
        current_item = playlist->getListOfItems()[0];
        str = BASS_StreamCreateURL(current_item->getPath().toUtf8().constData(), 0, 0, NULL, 0);
    }
}

void RadioPlayer::deleteCurrent(){//меняем на этот
    BASS_ChannelStop(str);
    if (playlist->getListOfItems().size() != 0)
        if (playlist->getListOfItems().size() != 1){
            auto current_item_copy = current_item;
            if (playlist->getListOfItems()[0] != current_item)
                current_item = playlist->getPreviousItem(current_item);
            else
                current_item = playlist->getNextItem(current_item);
            str = BASS_StreamCreateURL(current_item->getPath().toUtf8().constData(), 0, 0, NULL, 0);
            if (current_item_copy->getLikeInfo())
                favourite_playlist->deleteItem(current_item_copy);
            playlist->deleteItem(current_item_copy);
        }
        else{
            if (current_item->getLikeInfo())
                favourite_playlist->deleteItem(current_item);
            playlist->deleteItem(current_item);
            current_item = nullptr;
        }
}

void RadioPlayer::setLike(){
    if (current_item != nullptr)
        if (current_item->getLikeInfo()){
            current_item->deletelike();
            favourite_playlist->deleteItem(current_item);
        }
        else{
            current_item->putLike();
            favourite_playlist->setListOfItems(current_item);
        }
}

void RadioPlayer::changeVolume(const int index){

}

void RadioPlayer::load(){
    QVector<MediaData*> loaded_items = serializer->loadSavedRadioItems();
    if (loaded_items.size() != 0){
        qDebug() << "sss";
        playlist = new RadioDefaultPlaylist();
        for (MediaData* item : serializer->loadSavedRadioItems())
            playlist->setListOfItems(item);
        current_item = playlist->getListOfItems()[0];
        for (MediaData* item : playlist->getListOfItems())
            if (item->getLikeInfo())
                favourite_playlist->setListOfItems(item);
        str = BASS_StreamCreateURL(current_item->getPath().toUtf8().constData(), 0, 0, NULL, 0);
    }
}

void RadioPlayer::save(){
    serializer->saveRadioItems(playlist->getListOfItems());
}

void RadioPlayer::setFavouritePlaylistAsMain(){
    playlist = favourite_playlist;
}
const Playlist* RadioPlayer::getFavouritePlaylist() const {
    return favourite_playlist;
}

RadioPlayer::~RadioPlayer()
{
    save();
    for (auto radiostation : playlist->getListOfItems())
        delete radiostation;
}
