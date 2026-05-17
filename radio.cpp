#include "radio.h"

RadioPlayer::RadioPlayer(QObject* parent, RadioLoader* _serializer) : QObject(parent), serializer(_serializer) {
    BASS_Init(-1, 44100, BASS_DEVICE_3D, 0, NULL);

}

void RadioPlayer::play(){
    //if (str != nullptr)
    BASS_ChannelPlay(str, false);
}

void RadioPlayer::pause(){
    //if (str != nullptr)
    BASS_ChannelPause(str);
}

void RadioPlayer::stop(){
    //if (str != nullptr)
    BASS_ChannelStop(str);
}

void RadioPlayer::next(){

}

void RadioPlayer::previous(){

}

void RadioPlayer::setCurrent(const int){

}

void RadioPlayer::changeVolume(const int index){

}

void RadioPlayer::load(){
    QVector<RadioData*> loaded_radiostations = serializer->loadSavedRadioItems();
    if (loaded_radiostations.size() != 0){
        vector_of_radiostations = loaded_radiostations;
        str = BASS_StreamCreateURL(vector_of_radiostations[0]->getName().toUtf8().constData(), 0, 0, NULL, 0);
    }
    else
        str = BASS_StreamCreateURL("http://dorognoe.hostingradio.ru:8000/radio", 0, 0, NULL, 0);
}

void RadioPlayer::save(){
    serializer->saveRadioItems(vector_of_radiostations);
}

RadioPlayer::~RadioPlayer()
{
    save();
    for (auto radiostation : vector_of_radiostations)
        delete radiostation;
    qDebug() << "r";
}
