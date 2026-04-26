#ifndef RADIO_H
#define RADIO_H

#include "media_loader.h"
#include "ISerializable.h"
#include "IPlayer.h"
#include "IPlayerSettable.h"
#include "IVolumeChangeable.h"

class RadioPlayer: public QObject, public IPlayer, public ISerializable, public IVolumeChangeable{
    Q_OBJECT
public:

    RadioPlayer(QObject* parent = nullptr, MediaLoader* loader = nullptr);
    ~RadioPlayer();

    void play() override final;
    void pause() override final;
    void stop() override final;
    void next() override final;
    void previous() override final;


    void load() override final;
    void save() override final;


protected:
    MediaLoader* serializer;
};

#endif // RADIO_H
