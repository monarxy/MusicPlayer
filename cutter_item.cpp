#include "cutter_item.h"

CutterItem::CutterItem(int _start_position, int _end_position, const QString& _input_file, const QString& _output_file) : start_position(_start_position),
    end_position(_end_position), input_file(_input_file), output_file(_output_file){}

int CutterItem::getStartPosition() const{
    return start_position;
}
int CutterItem::getEndPosition() const{
    return end_position;
}
QString CutterItem::getInputFile() const{
    return input_file;
}
QString CutterItem::getOutputFile() const{
    return output_file;
}

void CutterItem::setStartPosition(const int _start_position) { start_position = _start_position;}
void CutterItem::setEndPosition(const int _end_position ) { end_position = _end_position;}
void CutterItem::setInputFile(const QString& _input_file) { input_file = _input_file;}
void CutterItem::setetOutputFile(const QString& _output_file) {output_file = _output_file;}
