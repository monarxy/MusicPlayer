#ifndef NAVIGATION_CONTROLLER_H
#define NAVIGATION_CONTROLLER_H

#include <QWidget>

class NavigationController{
private:
    QWidget* current_widget;
public:
    NavigationController();
    void openPlaylistFrom();
    void openListOfPlaylistsForm();
    void openMainForm();
};
#endif // NAVIGATION_CONTROLLER_H
