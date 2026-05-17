#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "data_controller.h"
#include "radio_controller.h"
#include "navigation_controller.h"

class AppController
{
    DataController* data_controller;
    RadioController* radio_controller;
    NavigationController* navigation_controller;
public:
    AppController(DataController*, RadioController*, NavigationController*);
    void setConnections();
};

#endif // APPCONTROLLER_H
