#ifndef IRADIOSTATIONSMANAGEMENT_H
#define IRADIOSTATIONSMANAGEMENT_H
#include "media_data.h"

#include <QStringList>

class IRadiostationsManagement{
public:
    virtual const QStringList getListOfRadiostations() const = 0;
    virtual void addRadiostation(const QString&) = 0;
    virtual const MediaData* getCurrentItem() const = 0;
};


#endif // IRADIOSTATIONSMANAGEMENT_H
