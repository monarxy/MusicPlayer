#ifndef IRADIOSTATIONSMANAGEMENT_H
#define IRADIOSTATIONSMANAGEMENT_H
#include "radio_data.h"

#include <QStringList>

class IRadiostationsManagement{
public:
    virtual const QStringList getListOfRadiostations() const = 0;
    virtual void addRadiostation(const QString&) = 0;
};


#endif // IRADIOSTATIONSMANAGEMENT_H
