#include "media_loader.h"

MediaLoader::MediaLoader(){
    settings = new QSettings(ORGANIZATION_NAME, APPLICATION_NAME);
}
