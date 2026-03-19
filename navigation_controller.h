#ifndef NAVIGATION_CONTROLLER_H
#define NAVIGATION_CONTROLLER_H

#include <QWidget>
#include "data_controller.h"
#include <QString>

class NavigationController : public QObject{

    Q_OBJECT
private:
    QWidget* current_widget;
    std::map<QString, QWidget*> active_widgets;
public:

    explicit NavigationController(QObject *parent = nullptr);
    ~NavigationController();
    void openForm(const QString&);
    QWidget* getForm(const QString&);
};
#endif // NAVIGATION_CONTROLLER_H
