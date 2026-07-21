#ifndef CUTTER_ITEM_H
#define CUTTER_ITEM_H
#include <QString>

class CutterItem{
    int start_position;
    int end_position;
    QString input_file;
    QString output_file;
public:
    CutterItem(int, int, const QString&, const QString&);
    int getStartPosition() const;
    int getEndPosition() const;
    QString getInputFile() const;
    QString getOutputFile() const;

    void setStartPosition(const int);
    void setEndPosition(const int);
    void setInputFile(const QString&);
    void setetOutputFile(const QString&);
};

#endif // CUTTER_ITEM_H
