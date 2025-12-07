#include "tracks_loader.h"

TracksLoader::TracksLoader(){
    settings = new QSettings(ORGANIZATION_NAME, APPLICATION_NAME);
}

QStringList TracksLoader::loadSavedTracks(){
    return settings->value("List_of_pathes").value<QStringList>();
}
