#include "tracks_loader.h"
#include "music_player.h"
#include "widget.h"
#include "navigation_controller.h"
#include "appcontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);
    QApplication a(argc, argv);
    MediaLoader* tracks_loader = new TracksLoader();
    MediaPlayer* music_player = new MusicPlayer(tracks_loader);

    DataController* data_controller = new DataController(nullptr, music_player);
    NavigationController* navigation_controller = new NavigationController(nullptr);
    AppController* app_controller = new AppController(data_controller, navigation_controller);
    app_controller->setConnections();
    data_controller->loadSavedTracks();
    navigation_controller->openMainForm();
    return a.exec();
}
