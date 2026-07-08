#ifndef RADIO_DATA_H
#define RADIO_DATA_H
#include <QString>

class RadioData{
    QString adress_of_radiostation;
public:
    RadioData(const QString&);
    ~RadioData();

    const QString& getName() const;
};

#endif // RADIO_DATA_H
