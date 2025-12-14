#ifndef MEDIA_LOADER_H
#define MEDIA_LOADER_H
#include <QString>
#include <QSettings>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "media_data.h"
#include "songs_data.h"
#include "video_data.h"
#include "playlist.h"

#define ORGANIZATION_NAME "Xfork"
#define ORGANIZATION_DOMAIN "22"
#define APPLICATION_NAME "Autoplayer"

class MediaLoader{
protected:
    QSettings* settings;
public:
    virtual QVector<Playlist*> loadSavedTracks(){}
    virtual void saveTracks(std::map<QString, Playlist*>){}

};
#endif // MEDIA_LOADER_H
