#include "tracks_loader.h"
#include "music_player.h"
#include "widget.h"
#include "navigation_controller.h"
#include <QApplication>
#include "iostream"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);
    QApplication a(argc, argv);
    TracksLoader* tracks_loader = new TracksLoader();
    MusicPlayer* music_player = new MusicPlayer(tracks_loader->loadSavedTracks());

    DataController* data_controller = new DataController(nullptr, music_player);
    NavigationController* navigation_controller = new NavigationController(nullptr);
    QObject::connect(data_controller, &DataController::LoadTracksFromMemory, static_cast<Widget*>(navigation_controller->getMainForm()), &Widget::setPlaylist);
    data_controller->loadSavedTracks();
    navigation_controller->openMainForm();
    return a.exec();
}
