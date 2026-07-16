#ifndef DATA_CONTROLLER_H
#define DATA_CONTROLLER_H
#include "video_player.h"
#include "IPlayerController.h"
#include "IFewPlayersController.h"
#include "IPlaylistController.h"
#include "IVolumeController.h"
#include "IDurationController.h"
#include "ILikecontroller.h"
#include "IVideoManagementController.h"
#include "IGetPlayerController.h"
#include "IFavouritePlaylistController.h"


class DataController : public QObject, public IPlayerController, public IGetPlayerController, public IFewPlayersController, public IPlaylistController,
public IVolumeController, public IDurationController, public ILikeController, public IVideoManagementController, public IFavouritePlaylistController
{
    Q_OBJECT
    MediaPlayer *player;
    std::map<QString, MediaPlayer*> players;
public:
    DataController(QObject *parent = nullptr);
    ~DataController();

    void setCurrentPlayerByIndex(const int) override;//fp
    void setItemsToPlayer(const QStringList&) override; //IPlaylistController
    void setMapOfPlayers(const QString&, MediaPlayer*) override;//fp
    void setMainPlayerByName(const QString&) override;//fp
    const MediaPlayer* getPlayer() const override;//IGetPlayerController
    void setCurrentItemByIndex(const int) override;//IController
    void setLikeReceive() override;//likeable
    void setListOfPlaylistsItemsReceive(const QString&) override;//IPlaylistController
    void setListOfFavouritePlaylistItemsReceive() override;

    void setPlaylistAndCurrentItemReceive(const int, const QString&, const int) override;//IPlaylistController
    void setVideoOutput(QVideoWidget*) override;

    QStringList getListOfPlaylistItems(const QString&) const override;//IPlaylistController
    const QStringList getListOfFavouritePlaylistItems() const override;
    void getPlaylistNamesReceive() override;//IPlaylistController
    const QVector<MediaPlayer*> getListOfPlayers() const override;

    void addNewPlaylist(const QString&) override;//IPlaylistController
    void addItemsToPlaylist(const QString&, const QStringList&) override;//IPlaylistController
    void deletePlaylistReceive(const QString&);

    void deleteItemReceive() override;

    void playReceive() override;
    void pauseReceive() override;
    void stopReceive() override;
    void nextReceive() override;
    void previousReceive() override;
    void likeReceive() override;//likeable

    void changeVolumeReceive(const int) override;//volume changeable
    void changeDurationReceive(const int) override;//duration changeable



signals:
    void LoadItemsToMainWidget(const QStringList&, const QString&);
    void LoadPlaylistsFromMemory(const QStringList&);
    void SetListOfPlaylistsItems(const QStringList&, const QString&, const int);
    void LikeStatusSignal(const bool);
    void SetNameOfCurrentItemToMainWidget(const QString&);
    void SetIndexOfCurrentItemToMainWidget(const int);
    void EnableAddAndDeleteButtons();
    void DisableAddAndDeleteButtons();
};
#endif // DATA_CONTROLLER_H
