#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "media_loader.h"
#include "ISerializable.h"
#include "IPlayer.h"
#include "IPlaylistManagement.h"
#include "IMultimediaGetManagement.h"
#include "IDurationChangeable.h"
#include "IVolumeChangeable.h"
#include "ILikeable.h"

class MediaPlayer: public QObject, public IPlayer, public ISerializable, public IPlaylistManagement, public IMultimediaGetManagement,
public ILikeable, public IVolumeChangeable, public IDurationChangeable{
    Q_OBJECT
public:

    MediaPlayer(QObject* parent = nullptr, MediaLoader* loader = nullptr);
    ~MediaPlayer();


    const QMediaPlayer* getPlayer() const override final;

    const Playlist* getPlaylist(const QString&) const override final;

    const MediaData* getCurrentItem() const override final;

    const Playlist* getCurrentPlaylist() const override final;
    QVector<QString> getListOfPlaylists() const override final;

    void play() override final;
    void pause() override final;
    void stop() override final;
    void next() override final;
    void previous() override final;

    void changeVolume(const int) override final;
    void changeDuration(const int) override final;

    void setLike()  override final;
    void setCurrent(const int) override final;

    void setPlaylist(Playlist*) override final;

    void addPlaylist(const QString&) override final;

    void setTracksToPlaylistByName(const QString&, const QStringList&) override = 0;
    void setTracksToCurrentPlaylist(const QStringList&) override = 0;
    void setCurrentPlaylistByName(const QString&) override final;

    void load() override final;
    void save() override final;


protected:
    QMediaPlayer        *m_player;          // Проигрыватель треков
    std::map<QString, Playlist*> list_of_playlists;
    Playlist *playlist;
    MediaData* current_item;
    MediaLoader* serializer;
};


#endif // MULTIMEDIA_H
