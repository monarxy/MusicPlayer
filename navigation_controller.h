#ifndef NAVIGATION_CONTROLLER_H
#define NAVIGATION_CONTROLLER_H

#include <QWidget>
#include "data_controller.h"

class NavigationController{
private:
    QWidget* current_widget;
    DataController *data_controller;
public:
    NavigationController(DataController *data_controller);
    void openPlaylistForm();
    void openListOfPlaylistsForm();
    void openMainForm();
    void openEditForm();
};
#endif // NAVIGATION_CONTROLLER_H
