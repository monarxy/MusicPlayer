#include "cutter_controller.h"

CutterController::CutterController(QObject *parent) : QObject(parent){

}

CutterController::~CutterController(){}

#include <QDebug>
void CutterController::cut(const CutterItem& item){
    MediaCutter cutter;
    int start_position = item.getStartPosition();
    int end_position = item.getEndPosition();
    QString input_file = item.getInputFile();
    QString output_file = item.getOutputFile();

    TagLib::FileRef f(input_file.toLocal8Bit().toStdString().c_str());
    if (f.audioProperties()->length() < end_position || start_position < 0
        || start_position > f.audioProperties()->length())
        return;

    QString output_file_concatenated = input_file.section('.', 0, -2) + output_file;
    qDebug() << output_file_concatenated ;
    cutter.trimAudio(input_file.toStdString(), output_file_concatenated.toStdString(), start_position, end_position);
}
