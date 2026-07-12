#ifndef RADIO_CONTROLLER_H
#define RADIO_CONTROLLER_H
#include <QObject>
#include "radio.h"
#include "IGetRadioPlayerController.h"
#include "IPlayerController.h"
#include "IVolumeController.h"
#include "IRadiostationController.h"
#include "IFavouritePlaylistController.h"

class RadioController : public QObject, public IPlayerController, public IGetRadioPlayerController, public IVolumeController, public IRadiostationController,
public IFavouritePlaylistController{
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

    void loadSavedItemsReceive(const QString&) override;
    void changeVolumeReceive(const int) override;

    void addRadiostationReceive(const QString&) override;
    void removeRadiostationReceive() override;
    void setListOfFavouritePlaylistItemsReceive() override;
    QStringList getListOfFavouritePlaylistItems() const override;

    void deleteItemReceive() override;
signals:
    void LoadItemsToRadioWidgetReceive(const QStringList&);
};

#endif // RADIO_CONTROLLER_H
