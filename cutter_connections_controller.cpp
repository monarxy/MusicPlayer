#include "cutter_connections_controller.h"

CutterConnectionsController::CutterConnectionsController(CutterController* _cutter_controller, NavigationController* _navigation_controller) :
    cutter_controller(_cutter_controller), navigation_controller(_navigation_controller){}

void CutterConnectionsController::setConnections(){
    QObject::connect(static_cast<CutterForm*>(navigation_controller->getForm("cutter_form")), &CutterForm::CutRequest, cutter_controller, &CutterController::cut);
}
