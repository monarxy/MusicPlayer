#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include "media_loader.h"
#include "ISerializable.h"
#include "IPlayer.h"
#include "IPlaylistManagement.h"
#include "IMultimediaGetManagement.h"
#include "IDurationChangeable.h"
#include "IVolumeChangeable.h"
#include "ILikeable.h"
#include "IFavouritePlaylist.h"
#include "cover_extractor.h"

class MediaPlayer: public IPlayer<MediaData>, public ISerializable, public IPlaylistManagement, public IMultimediaGetManagement,
public ILikeable, public IVolumeChangeable, public IDurationChangeable, public IFavouritePlaylist<Playlist>{
public:

    MediaPlayer(MediaLoader* loader);
    ~MediaPlayer();


    const QMediaPlayer* getPlayer() const override final;

    const Playlist* getPlaylist(const QString&) const override final;

    const MediaData* getCurrentItem() const override final;

    const Playlist* getCurrentPlaylist() const override final;
    const Playlist* getFavouritePlaylist() const override final;

    const QVector<QString> getListOfPlaylists() const override final;

    void play() override final;
    void pause() override final;
    void stop() override final;
    void next() override final;
    void previous() override final;

    void changeVolume(const int) override final;
    void changeDuration(const int) override final;

    void setLike()  override final;
    void setCurrent(const int) override final;
    void deleteCurrent() override final;

    void setPlaylist(Playlist*) override final;

    void addPlaylist(const QString&) override final;
    void deletePlaylist(const QString&) override final;

    void setTracksToPlaylistByName(const QString&, const QStringList&) override;
    void setTracksToCurrentPlaylist(const QStringList&) override;
    void setCurrentPlaylistByName(const QString&) override final;
    void setFavouritePlaylistAsMain() override final;

    void load() override = 0;
    void save() override = 0;


protected:
    QMediaPlayer *m_player;
    std::map<QString, Playlist*> list_of_playlists;
    Playlist *playlist;
    FavouritePlaylist* favourite_playlist;
    MediaData* current_item;
    MediaLoader* serializer;
};


#endif // MULTIMEDIA_H
