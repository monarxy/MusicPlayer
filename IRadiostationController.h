#ifndef IRADIOSTATIONCONTROLLER_H
#define IRADIOSTATIONCONTROLLER_H

#include <QString>

class IRadiostationController{
public:
    virtual void addRadiostationReceive(const QString&) = 0;
    virtual void removeRadiostationReceive(const int) = 0;
    virtual ~IRadiostationController() = default;
};

#endif // IRADIOSTATIONCONTROLLER_H
