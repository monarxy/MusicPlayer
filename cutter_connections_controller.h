#ifndef CUTTER_CONNECTIONS_CONTROLLER_H
#define CUTTER_CONNECTIONS_CONTROLLER_H
#include "navigation_controller.h"
#include "cutter_controller.h"

class CutterConnectionsController
{
    NavigationController* navigation_controller;
    CutterController* cutter_controller;
public:
    CutterConnectionsController(CutterController*_cutter_controller, NavigationController*_navigation_controller);
    void setConnections();
};

#endif // CUTTER_CONNECTIONS_CONTROLLER_H
