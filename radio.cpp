#include "radio.h"

RadioPlayer::RadioPlayer(RadioLoader* _serializer) : serializer(_serializer),
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
            RadioData* next_current_item = playlist->getNextItem(current_item);
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
            RadioData* prev_current_item = playlist->getPreviousItem(current_item);
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
    if (!playlist->getListOfItems().isEmpty())
        for (RadioData* radiostation : playlist->getListOfItems())
            _list_of_radiostations.append(radiostation->getPath());
    return _list_of_radiostations;
}

void RadioPlayer::addRadiostation(const QString& name_of_radiostation){
    RadioData* new_radiostation = new RadioData(name_of_radiostation);
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
    int clamped_index = std::clamp(index, 0, 100);
    float bass_volume = clamped_index / 100.0f;
    BASS_ChannelSetAttribute(str, BASS_ATTRIB_VOL, bass_volume);
}

void RadioPlayer::load(){
    QVector<RadioData*> loaded_items = serializer->loadSavedRadioItems();
    default_playlist = new RadioDefaultPlaylist();
    playlist = default_playlist;
    if (loaded_items.size() != 0){
        for (RadioData* item : serializer->loadSavedRadioItems())
            playlist->setListOfItems(item);
        current_item = playlist->getListOfItems()[0];
        for (RadioData* item : playlist->getListOfItems())
            if (item->getLikeInfo())
                favourite_playlist->setListOfItems(item);
        str = BASS_StreamCreateURL(current_item->getPath().toUtf8().constData(), 0, 0, NULL, 0);
    }
}

void RadioPlayer::save(){
    serializer->saveRadioItems(default_playlist->getListOfItems());
}

const RadioData* RadioPlayer::getCurrentItem() const{
    return current_item;
}

void RadioPlayer::setFavouritePlaylistAsMain(){
    playlist = favourite_playlist;
}
const RadioPlaylist* RadioPlayer::getFavouritePlaylist() const {
    return favourite_playlist;
}

void RadioPlayer::setDefaultPlaylistAsMain(){
    playlist = default_playlist;
}

const RadioPlaylist* RadioPlayer::getDefaultPlaylist() const{
    return default_playlist;
}

RadioPlayer::~RadioPlayer()
{
    save();
    delete favourite_playlist;
    delete default_playlist;
}
