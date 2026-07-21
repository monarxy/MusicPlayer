#ifndef RADIO_CONNECTIONS_CONTROLLER_H
#define RADIO_CONNECTIONS_CONTROLLER_H
#include "radio_controller.h"
#include "navigation_controller.h"

class RadioConnectionsController
{
    RadioController* radio_controller;
    NavigationController* navigation_controller;
public:
    RadioConnectionsController(RadioController* = nullptr, NavigationController* = nullptr);
    void setConnections();
};

#endif // RADIO_CONNECTIONS_CONTROLLER_H
