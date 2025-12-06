#include "widget.h"
#include <QApplication>
#include "iostream"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);
    QApplication a(argc, argv);
    DataController* data_controller = new DataController(nulllptr);
    NavigationController* navigation_controller = new NavigationController(nullptr);
    navigation_controller->openMainForm();
    return a.exec();
}
