#ifndef RADIO_H
#define RADIO_H

#include "bass.h"
#include "radio_loader.h"
#include "ISerializable.h"
#include "IPlayer.h"
#include "IPlayerSettable.h"
#include "IVolumeChangeable.h"

class RadioPlayer: public QObject, public IPlayer, public ISerializable, public IVolumeChangeable{
    Q_OBJECT
public:

    RadioPlayer(QObject* parent = nullptr, RadioLoader* loader = nullptr);
    ~RadioPlayer();

    void play() override final;
    void pause() override final;
    void stop() override final;
    void next() override final;
    void previous() override final;

    void setCurrent(const int) override final;


    void load() override final;
    void save() override final;

    void changeVolume(const int) override final;


protected:
    RadioLoader* serializer;
    QVector<RadioData*> vector_of_radiostations;
    HSTREAM str;
    RadioData* current;
};

#endif // RADIO_H
