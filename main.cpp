#include "tracks_loader.h"
#include "video_loader.h"

#include "music_player.h"
#include "video_player.h"
#include "widget.h"
#include "navigation_controller.h"
#include "radio_controller.h"
#include "appcontroller.h"
#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);


    QApplication a(argc, argv);
    MediaLoader* music_loader = new TracksLoader();
    MediaLoader* video_loader = new VideoLoader();
    RadioLoader* radio_loader = new RadioLoader();

    MediaPlayer* music_player = new MusicPlayer(&a, music_loader);
    MediaPlayer* video_player = new VideoPlayer(&a, video_loader);
    RadioPlayer* radio_player = new RadioPlayer(&a, radio_loader);

    QVector<ISerializable*> loading_objects;
    loading_objects.append(music_player);
    loading_objects.append(video_player);
    loading_objects.append(radio_player);

    for (ISerializable* object : loading_objects)
        object->load();

    std::map<QString, MediaPlayer*> players;
    players["music_player"] = music_player;
    players["video_player"] = video_player;

    RadioController* radio_controller = new RadioController(&a, radio_player);
    DataController* data_controller = new DataController(&a);
    for (const auto [name, object] : players) {
        data_controller->setMapOfPlayers(name, object);
    }

    data_controller->setMainPlayerByName("music_player");


    NavigationController* navigation_controller = new NavigationController(&a);
    AppController* app_controller = new AppController(data_controller, radio_controller, navigation_controller);

    app_controller->setConnections();
    radio_controller->getRadiostationsReceive();
    navigation_controller->openForm("main_form");
    int result = a.exec();

    delete music_loader;
    delete video_loader;
    delete app_controller;

    return result;
}
