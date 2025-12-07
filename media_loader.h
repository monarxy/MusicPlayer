#ifndef MEDIA_LOADER_H
#define MEDIA_LOADER_H
#include <QString>
#include <QSettings>

#define ORGANIZATION_NAME "Xfork"
#define ORGANIZATION_DOMAIN "22"
#define APPLICATION_NAME "Autoplayer"

class MediaLoader{
protected:
    QSettings* settings;
public:
    virtual QStringList loadSavedTracks(){}

};
#endif // MEDIA_LOADER_H
