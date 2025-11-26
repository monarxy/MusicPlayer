#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);
    QApplication a(argc, argv);
    DataController* data_controller = new DataController();
    NavigationController* navigation_controller = new NavigationController(data_controller);
    navigation_controller->openMainForm();
    return a.exec();
}
