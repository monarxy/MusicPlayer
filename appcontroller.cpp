#include "appcontroller.h"

AppController::AppController(DataController* _data_controller, NavigationController* _navigation_controller) {
    data_controller = _data_controller;
    navigation_controller = _navigation_controller;
    QObject::connect(data_controller, &DataController::LoadTracksFromMemory, static_cast<Widget*>(navigation_controller->getMainForm()), &Widget::setPlaylist);
}
