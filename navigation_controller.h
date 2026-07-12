#ifndef NAVIGATION_CONTROLLER_H
#define NAVIGATION_CONTROLLER_H

#include <QWidget>
#include <QString>
#include "data_controller.h"
#include "playlistform.h"
#include "widget.h"
#include "radioform.h"
#include "list_of_playlist_tracks.h"
#include "list_of_radioplaylist_tracks.h"

class NavigationController : public QObject{

    Q_OBJECT
private:
    QWidget* current_widget;
    std::map<QString, QWidget*> active_widgets;
public:

    NavigationController(QObject *parent = nullptr);
    ~NavigationController();
    void openForm(const QString&);
    QWidget* getForm(const QString&);
};
#endif // NAVIGATION_CONTROLLER_H
