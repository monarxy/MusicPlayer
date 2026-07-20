#ifndef RADIO_H
#define RADIO_H

#include "bass.h"
#include "radio_loader.h"
#include "IRadiostationsManagement.h"
#include "ISerializable.h"
#include "IPlayer.h"
#include "IPlayerSettable.h"
#include "IVolumeChangeable.h"
#include "ILikeable.h"
#include "IFavouritePlaylist.h"
#include "IDefaultPlaylist.h"
#include "radio_favourite_playlist.h"
#include "radio_default_playlist.h"

class RadioPlayer: public IPlayer<RadioData>, public ISerializable, public IVolumeChangeable, public IRadiostationsManagement,
public ILikeable, public IFavouritePlaylist<RadioPlaylist>, public IDefaultPlaylist<RadioPlaylist>{
public:

    RadioPlayer(RadioLoader* loader);
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

    const RadioData* getCurrentItem() const override;

    void setFavouritePlaylistAsMain();
    const RadioPlaylist* getFavouritePlaylist() const;
    void setDefaultPlaylistAsMain();
    const RadioPlaylist* getDefaultPlaylist() const;

    void changeVolume(const int) override final;


protected:
    RadioLoader* serializer;
    RadioPlaylist* playlist;
    RadioFavouritePlaylist* favourite_playlist;
    RadioDefaultPlaylist* default_playlist;
    HSTREAM str;
    RadioData* current_item;
};

#endif // RADIO_H
