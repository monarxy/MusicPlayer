#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "data_controller.h"
#include "navigation_controller.h"
#include "widget.h"
class AppController
{
    DataController* data_controller;
    NavigationController* navigation_controller;
public:
    AppController(DataController*, NavigationController*);
    void setConnections();
};

#endif // APPCONTROLLER_H
