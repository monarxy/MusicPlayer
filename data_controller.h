#ifndef DATA_CONTROLLER_H
#define DATA_CONTROLLER_H
#include "video_player.h"
#include "music_player.h"
#include "IPlayerController.h"
#include "IFewPlayersController.h"
#include "IPlaylistController.h"
#include "IVolumeController.h"
#include "IDurationController.h"
#include "ILikecontroller.h"
#include "IVideoManagementController.h"
#include "IGetPlayerController.h"
#include "IFavouritePlaylistController.h"
#include "IContinuousPlayer.h"
#include "cover_extractor.h"

class DataController : public QObject, public IPlayerController, public IGetPlayerController, public IFewPlayersController, public IPlaylistController,
                       public IVolumeController, public IDurationController, public ILikeController, public IVideoManagementController, public IFavouritePlaylistController,
                       public IContinuousPlayer
{
    Q_OBJECT
    MediaPlayer *player;
    VideoPlayer *video_player;
    MusicPlayer *music_player;
    int player_type;
public:
    DataController(QObject *parent = nullptr, MusicPlayer* = nullptr, VideoPlayer* = nullptr);
    ~DataController();

    void setCurrentPlayerByIndex(const int) override;
    void setItemsToPlayer(const QStringList&) override;
    const MediaPlayer* getPlayer() const override;
    void setCurrentItemByIndex(const int) override;

    void setLikeReceive() override;
    void setListOfPlaylistsItemsReceive(const QString&) override;
    void setListOfFavouritePlaylistItemsReceive() override;

    void setPlaylistAndCurrentItemReceive(const int, const QString&, const int) override;
    void setVideoOutput(QVideoWidget*) override;

    QStringList getListOfPlaylistItems(const QString&) const override;
    const QStringList getListOfFavouritePlaylistItems() const override;
    void getPlaylistNamesReceive() override;
    const QVector<MediaPlayer*> getListOfPlayers() const override;

    void addNewPlaylist(const QString&) override;
    void addItemsToPlaylist(const QString&, const QStringList&) override;
    void deletePlaylistReceive(const QString&) override;

    void deleteItemReceive() override;

    void playReceive() override;
    void pauseReceive() override;
    void stopReceive() override;
    void nextReceive() override;
    void automaticallyNextReceive(const qint64, const int) override;
    void previousReceive() override;
    void likeReceive() override;

    void changeVolumeReceive(const int) override;
    void changeDurationReceive(const int) override;

signals:
    void LoadItemsToMainWidget(const QStringList&, const QString&);
    void LoadPlaylistsFromMemory(const QStringList&);
    void SetListOfPlaylistsItems(const QStringList&, const QString&, const int);
    void LikeStatusSignal(const bool);
    void SetNameOfCurrentItemToMainWidget(const QString&);
    void SetIndexOfCurrentItemToMainWidget(const int);
    void EnableAddAndDeleteButtons();
    void DisableAddAndDeleteButtons();
    void SetDurationToMainWidget(const qint64);
    void UpdateCurrentItemInMainWidget();
    void SetPictureToMainWidget(const QPixmap&);
};
#endif // DATA_CONTROLLER_H
