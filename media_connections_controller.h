#ifndef MEDIA_CONNECTIONS_CONTROLLER_H
#define MEDIA_CONNECTIONS_CONTROLLER_H

#include "data_controller.h"
#include "radio_controller.h"
#include "navigation_controller.h"

class MediaConnectionsController
{
private:
    DataController* data_controller;
    NavigationController* navigation_controller;
public:
    MediaConnectionsController(DataController* = nullptr, NavigationController* = nullptr);

    void setConnections();
};

#endif // MEDIA_CONNECTIONS_CONTROLLER_H
