#ifndef IPLAYLISTNAMEMANAGEMENT_H
#define IPLAYLISTNAMEMANAGEMENT_H
#include <QString>

class IPlaylistNameManagement{
public:
    virtual QString getName() const = 0;
    virtual void setName(const QString&) = 0;
};

#endif // IPLAYLISTNAMEMANAGEMENT_H
