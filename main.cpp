#include "media_loader.h"

#include "music_player.h"
#include "video_player.h"
#include "widget.h"
#include "navigation_controller.h"
#include "radio_controller.h"
#include "appcontroller.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);


    QApplication a(argc, argv);
    MediaLoader* loader = new MediaLoader();
    RadioLoader* radio_loader = new RadioLoader();

    MusicPlayer* music_player = new MusicPlayer(loader);
    VideoPlayer* video_player = new VideoPlayer(loader);
    RadioPlayer* radio_player = new RadioPlayer(radio_loader);

    QVector<ISerializable*> loading_objects;
    loading_objects.append(music_player);
    loading_objects.append(video_player);
    loading_objects.append(radio_player);

    for (ISerializable* object : loading_objects)
        object->load();

    RadioController* radio_controller = new RadioController(&a, radio_player);
    DataController* data_controller = new DataController(&a, music_player, video_player);

    NavigationController* navigation_controller = new NavigationController(&a);
    AppController app_controller = AppController(data_controller, radio_controller, navigation_controller);

    app_controller.setConnections();
    radio_controller->getRadiostationsReceive();
    data_controller->setCurrentPlayerByIndex(0);
    navigation_controller->openForm("main_form");

    int result = a.exec();
    delete music_player;
    delete video_player;
    delete radio_player;
    delete radio_loader;
    delete loader;

    return result;
}
