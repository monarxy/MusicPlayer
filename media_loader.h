#ifndef MEDIA_LOADER_H
#define MEDIA_LOADER_H
#include <QString>
#include <QSettings>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMediaPlayer>
#include <QMediaPlaylist>
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
    virtual QVector<Playlist*> loadSavedTracks() const {}
    virtual void saveTracks(const std::map<QString, Playlist*>&) const{}

};
#endif // MEDIA_LOADER_H
