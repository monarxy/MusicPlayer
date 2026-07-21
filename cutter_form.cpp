#include "cutter_form.h"
#include "ui_cutter_form.h"

CutterForm::CutterForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CutterForm)
    , cutter_item(0, 0, "", "")

{
    ui->setupUi(this);
    ui->label_4->setScaledContents(true);
}

CutterForm::~CutterForm()
{
    delete ui;
}

void CutterForm::on_pushButton_clicked()
{
    QStringList files;
        files = QFileDialog::getOpenFileNames(this, tr("Open files"), QString(), tr("Audio Files (*.mp3 *.mp4 *.avi *.mkv *.wav *.ogg *.flac)"));
    cutter_item.setInputFile(files[0]);
}


void CutterForm::on_pushButton_3_clicked()
{
    cutter_item.setStartPosition(ui->lineEdit->text().toInt());
    cutter_item.setEndPosition(ui->lineEdit_2->text().toInt());
    cutter_item.setetOutputFile(ui->lineEdit_3->text());
    emit CutRequest(cutter_item);
}

