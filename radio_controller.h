#ifndef RADIO_CONTROLLER_H
#define RADIO_CONTROLLER_H
#include <QObject>
#include "radio.h"
#include "IPlayerController.h"
#include "IVolumeController.h"
#include "IRadiostationController.h"

class RadioController : public QObject, public IPlayerController, public IVolumeController, public IRadiostationController {
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
    const MediaPlayer* getPlayer() const override;
    void setCurrentItemByIndex(const int) override;

    void loadSavedItemsReceive(const QString&) override;
    void changeVolumeReceive(const int) override;

    void addRadiostationReceive(const QString&) override;
    void removeRadiostationReceive(const int) override;
};

#endif // RADIO_CONTROLLER_H
