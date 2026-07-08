#include "radio.h"

RadioPlayer::RadioPlayer(QObject* parent, RadioLoader* _serializer) : QObject(parent), serializer(_serializer),
    current_it(nullptr){
    BASS_Init(-1, 44100, BASS_DEVICE_3D, 0, NULL);
}

void RadioPlayer::play(){
    if (!vector_of_radiostations.isEmpty())
        BASS_ChannelPlay(str, false);
}

void RadioPlayer::pause(){
    if (!vector_of_radiostations.isEmpty())
        BASS_ChannelPause(str);
}

void RadioPlayer::stop(){
    if (!vector_of_radiostations.isEmpty())
        BASS_ChannelStop(str);
}

void RadioPlayer::next(){
    if (!vector_of_radiostations.isEmpty())
        if (current_it != vector_of_radiostations.end()-1){
            BASS_ChannelStop(str);
            ++current_it;
            current = *current_it;
            str = BASS_StreamCreateURL(current->getName().toUtf8().constData(), 0, 0, NULL, 0);
    }
    BASS_ChannelPlay(str, false);
}

void RadioPlayer::previous(){
    if (!vector_of_radiostations.isEmpty())
        if (current_it != vector_of_radiostations.begin()){
            BASS_ChannelStop(str);
            --current_it;
            current = *current_it;
            str = BASS_StreamCreateURL(current->getName().toUtf8().constData(), 0, 0, NULL, 0);
        }
    BASS_ChannelPlay(str, false);
}

void RadioPlayer::setCurrent(const int index){
    BASS_ChannelStop(str);
    current = vector_of_radiostations[index];
    current_it = vector_of_radiostations.begin();
    for (int i = 0; i < index; ++i)
        ++current_it;
    str = BASS_StreamCreateURL(current->getName().toUtf8().constData(), 0, 0, NULL, 0);
    BASS_ChannelPlay(str, false);
}

const QStringList RadioPlayer::getListOfRadiostations() const {
    QStringList _list_of_radiostations;
    for (RadioData* radiostation : vector_of_radiostations)
        _list_of_radiostations.append(radiostation->getName());
    return _list_of_radiostations;
}

void RadioPlayer::addRadiostation(const QString& name_of_radiostation){
    RadioData* new_radiostation = new RadioData(name_of_radiostation);
    vector_of_radiostations.append(new_radiostation);
    if (vector_of_radiostations.size() == 1){
        current_it = vector_of_radiostations.begin();
        current = *current_it;
        str = BASS_StreamCreateURL(current->getName().toUtf8().constData(), 0, 0, NULL, 0);
    }
}

void RadioPlayer::deleteRadiostation(){
    if (!vector_of_radiostations.isEmpty()){
        BASS_ChannelStop(str);
        vector_of_radiostations.erase(current_it);
        if (current_it == vector_of_radiostations.end())
            current_it = vector_of_radiostations.end()-1;
        current = *current_it;
        if (!vector_of_radiostations.isEmpty())
            str = BASS_StreamCreateURL(current->getName().toUtf8().constData(), 0, 0, NULL, 0);
    }
}

void RadioPlayer::deleteCurrent(){

}

void RadioPlayer::changeVolume(const int index){

}

void RadioPlayer::load(){
    vector_of_radiostations = serializer->loadSavedRadioItems();
    current_it = vector_of_radiostations.begin();
    if (!vector_of_radiostations.isEmpty()){
        current = *current_it;
        str = BASS_StreamCreateURL(current->getName().toUtf8().constData(), 0, 0, NULL, 0);}
}

void RadioPlayer::save(){
    serializer->saveRadioItems(vector_of_radiostations);
}

RadioPlayer::~RadioPlayer()
{
    save();
    for (auto radiostation : vector_of_radiostations)
        delete radiostation;
}
