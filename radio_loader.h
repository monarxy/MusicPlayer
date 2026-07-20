#ifndef RADIO_LOADER_H
#define RADIO_LOADER_H

#include <QSettings>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QSettings>
#include "radio_data.h"

#define ORGANIZATION_NAME "Xfork"
#define ORGANIZATION_DOMAIN "22"
#define APPLICATION_NAME "Autoplayer"

class RadioLoader {
    QSettings settings;
public:
    RadioLoader();
    ~RadioLoader();
    QVector<RadioData*> loadSavedRadioItems() const;
    void saveRadioItems(const QVector<RadioData*>&);
};

#endif // RADIO_LOADER_H
