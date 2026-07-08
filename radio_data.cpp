#include "radio_data.h"

RadioData::RadioData(const QString& _adress_of_radiostation) : adress_of_radiostation(_adress_of_radiostation) {}

RadioData::~RadioData(){}

const QString& RadioData::getName() const{
    return adress_of_radiostation;
}
