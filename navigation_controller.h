#ifndef NAVIGATION_CONTROLLER_H
#define NAVIGATION_CONTROLLER_H

#include <QWidget>
#include "data_controller.h"

class NavigationController : public QObject{

    Q_OBJECT
private:
    QWidget* current_widget;
    std::map<std::string, QWidget*> active_widgets;
public:

    NavigationController(QObject *parent = nullptr);
    ~NavigationController();
    void openPlaylistForm();
    void openListOfPlaylistsForm(QString);
    void openMainForm();
    void openEditForm();
};
#endif // NAVIGATION_CONTROLLER_H
