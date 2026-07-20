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
#include "default_playlist.h"
#include "cover_extractor.h"

#define ORGANIZATION_NAME "Xfork"
#define ORGANIZATION_DOMAIN "22"
#define APPLICATION_NAME "Autoplayer"

class MediaLoader{
protected:
    QSettings settings;
public:
    MediaLoader();
    ~MediaLoader();
    QVector<Playlist*> loadSavedItems(const QString&) const;
    void saveItems(const std::map<QString, Playlist*>&, const QString&);

};
#endif // MEDIA_LOADER_H
