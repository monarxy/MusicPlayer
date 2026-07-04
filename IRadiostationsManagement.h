#ifndef IRADIOSTATIONSMANAGEMENT_H
#define IRADIOSTATIONSMANAGEMENT_H

#include <QStringList>

class IRadiostationsManagement{
public:
    virtual QStringList getListOfRadiostations() const = 0;
};


#endif // IRADIOSTATIONSMANAGEMENT_H
