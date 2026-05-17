#include "radio_loader.h"

RadioLoader::RadioLoader(){
    settings = new QSettings(ORGANIZATION_NAME, APPLICATION_NAME);
}

QVector<RadioData*> RadioLoader::loadSavedRadioItems() const{
    QVector<RadioData*> vector_of_loaded_radiostations;
    QByteArray json_data = settings->value("radio").toByteArray();
    QJsonDocument doc = QJsonDocument::fromJson(json_data);

    QJsonArray radiostations = doc["list_of_radiostations"].toArray();
    for (const QJsonValue& item : radiostations){
        QJsonObject radiostation_item = item.toObject();
        RadioData* radiostation = new RadioData(radiostation_item["radiostation_name"].toString());

        vector_of_loaded_radiostations.append(radiostation);
    }
    return vector_of_loaded_radiostations;
}

void RadioLoader::saveRadioItems(const QVector<RadioData*>& vector_of_radiostations) const {
    QJsonObject radio;
    QJsonArray array_of_radiostations;
    for (const RadioData* radiostation : vector_of_radiostations){
        QJsonObject radiostation_item;
        radiostation_item["radiostation_name"] = radiostation->getName();
        array_of_radiostations.append(radiostation_item);
    }
    radio["list_of_radiostations"] = array_of_radiostations;
    QJsonDocument doc(radio);
    settings->setValue("radio", doc.toJson(QJsonDocument::Compact));
}
