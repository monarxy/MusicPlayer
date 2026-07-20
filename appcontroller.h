#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "data_controller.h"
#include "radio_controller.h"
#include "navigation_controller.h"

class AppController : public QObject
{
    Q_OBJECT
private:
    DataController* data_controller;
    RadioController* radio_controller;
    NavigationController* navigation_controller;
public:
    AppController(QObject* parent = nullptr, DataController* = nullptr,
                  RadioController* = nullptr, NavigationController* = nullptr);
    ~AppController();

    void setConnections();
};

#endif // APPCONTROLLER_H
