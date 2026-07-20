#ifndef RADIO_DATA_H
#define RADIO_DATA_H
#include <QString>
#include "data.h"

class RadioData : public Data {
public:
    RadioData(const QString&);
    RadioData(const QString&, bool);
    ~RadioData();
};

#endif // RADIO_DATA_H
