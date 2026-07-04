#include "radio.h"

RadioPlayer::RadioPlayer(QObject* parent, RadioLoader* _serializer) : QObject(parent), serializer(_serializer), current_it(list_of_radiostations){
    BASS_Init(-1, 44100, BASS_DEVICE_3D, 0, NULL);
}

void RadioPlayer::play(){
    if (!list_of_radiostations.isEmpty())
        BASS_ChannelPlay(str, false);
}

void RadioPlayer::pause(){
    if (!list_of_radiostations.isEmpty())
        BASS_ChannelPause(str);
}

void RadioPlayer::stop(){
    if (!list_of_radiostations.isEmpty())
        BASS_ChannelStop(str);
}

void RadioPlayer::next(){
    if (!list_of_radiostations.isEmpty())
        if (current_it.hasNext()){
            BASS_ChannelStop(str);
            current = current_it.next();
            str = BASS_StreamCreateURL(current->getName().toUtf8().constData(), 0, 0, NULL, 0);
        }
    BASS_ChannelPlay(str, false);
}

void RadioPlayer::previous(){
    if (!list_of_radiostations.isEmpty())
        if (current_it.hasPrevious()){
            BASS_ChannelStop(str);
            current = current_it.previous();
            str = BASS_StreamCreateURL(current->getName().toUtf8().constData(), 0, 0, NULL, 0);
        }
    BASS_ChannelPlay(str, false);
}

void RadioPlayer::setCurrent(const int){

}

QStringList RadioPlayer::getListOfRadiostations() const {
    QStringList _list_of_radiostations;
    for (RadioData* radiostation : list_of_radiostations)
        _list_of_radiostations.append(radiostation->getName());
    return _list_of_radiostations;
}

void RadioPlayer::changeVolume(const int index){

}

void RadioPlayer::load(){
    QVector<RadioData*> loaded_radiostations = serializer->loadSavedRadioItems();
    if (loaded_radiostations.size() != 0){
        list_of_radiostations = loaded_radiostations.toList();
        current_it = QListIterator<RadioData*>(list_of_radiostations);
        if (current_it.hasNext())
            current = current_it.next();
        str = BASS_StreamCreateURL(current->getName().toUtf8().constData(), 0, 0, NULL, 0);
    }
    else{
        current_it = QListIterator<RadioData*>(list_of_radiostations);
        // if (current_it.hasNext())
        //qDebug() << "dd";
            //current = current_it.next();
        // str = BASS_StreamCreateURL(current->getName().toUtf8().constData(), 0, 0, NULL, 0);
    }
}

void RadioPlayer::save(){
    serializer->saveRadioItems(list_of_radiostations.toVector());
}

RadioPlayer::~RadioPlayer()
{
    save();
    for (auto radiostation : list_of_radiostations)
        delete radiostation;
    qDebug() << "r";
}
