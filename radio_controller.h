#ifndef RADIO_CONTROLLER_H
#define RADIO_CONTROLLER_H
#include <QObject>
#include <QDir>
#include "radio.h"
#include "IGetRadioPlayerController.h"
#include "IPlayerController.h"
#include "IVolumeController.h"
#include "IRadiostationController.h"
#include "IFavouritePlaylistController.h"
#include "ILikeController.h"
#include "IRadioPlaylistController.h"

class RadioController : public QObject, public IPlayerController, public IGetRadioPlayerController, public IVolumeController, public IRadiostationController,
public IFavouritePlaylistController, public ILikeController, public IRadioPlaylistController{
    Q_OBJECT
    RadioPlayer *radio_player;
public:
    RadioController(QObject *parent = nullptr, RadioPlayer* player=nullptr);
    ~RadioController();

    void playReceive() override;
    void pauseReceive() override;
    void stopReceive() override;
    void nextReceive() override;
    void previousReceive() override;

    const RadioPlayer* getPlayer() const override;
    void getRadiostationsReceive() override;
    void setCurrentItemByIndex(const int) override;

    void changeVolumeReceive(const int) override;

    void addRadiostationReceive(const QString&) override;
    void setListOfFavouritePlaylistItemsReceive() override;

    const QStringList getListOfDefaultPlaylistItems() const override;
    const QStringList getListOfFavouritePlaylistItems() const override;

    void setPlaylistAndCurrentItemReceive(const int, const int) override;

    void setLikeReceive() override;
    void likeReceive() override;

    void deleteItemReceive() override;
signals:
    void LoadItemsToRadioWidgetReceive(const QStringList&);
    void SetListOfPlaylistsItems(const QStringList&);
    void LikeStatusSignal(const bool);
    void SetNameOfCurrentItemToMainWidget(const QString&);
    void SetIndexOfCurrentItemToMainWidget(const int);
    void EnableRadioFormButtons();
    void DisableRadioFormButtons();
};

#endif // RADIO_CONTROLLER_H
