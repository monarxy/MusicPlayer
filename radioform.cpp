#include "radioform.h"
#include "ui_radioform.h"

RadioForm::RadioForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RadioForm)
{
    ui->setupUi(this);
}

RadioForm::~RadioForm()
{
    delete ui;
}

void RadioForm::on_pushButton_clicked()
{
    emit PlayClicked();
}

