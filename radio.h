#ifndef RADIO_H
#define RADIO_H

#include "bass.h"
#include <QList>
#include "radio_loader.h"
#include "IRadiostationsManagement.h"
#include "ISerializable.h"
#include "IPlayer.h"
#include "IPlayerSettable.h"
#include "IVolumeChangeable.h"
#include "ILikeable.h"
#include "radio_favourite_playlist.h"
#include "radio_default_playlist.h"

class RadioPlayer: public QObject, public IPlayer, public ISerializable, public IVolumeChangeable, public IRadiostationsManagement, public ILikeable {
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
    const QStringList getListOfRadiostations() const override final;
    void addRadiostation(const QString&) override final;
    void deleteCurrent() override final;

    void setLike() override final;

    void load() override final;
    void save() override final;

    void changeVolume(const int) override final;


protected:
    RadioLoader* serializer;
    RadioPlaylist* playlist;
    RadioPlaylist* favourite_playlist;
    HSTREAM str;
    MediaData* current_item;
};

#endif // RADIO_H
