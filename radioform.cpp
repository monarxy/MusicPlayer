#include "radioform.h"
#include "ui_radioform.h"
#include <QDebug>

RadioForm::RadioForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RadioForm)
{
    ui->setupUi(this);
    m_playListModel = new QStandardItemModel(this);
    ui->playlistView->setModel(m_playListModel);
}

RadioForm::~RadioForm()
{
    delete ui;
}

void RadioForm::setPlaylist(const QStringList& list_of_tracks){
    m_playListModel->clear();
    foreach (QString item, list_of_tracks){
        QList<QStandardItem *> items;
        items.append(new QStandardItem(item));
        m_playListModel->appendRow(items);
    }
    qDebug() << "d";
}

void RadioForm::on_pushButton_clicked()
{
    emit PlayClicked();
}


void RadioForm::on_pushButton_3_clicked()
{
    emit PreviousClicked();
}


void RadioForm::on_pushButton_2_clicked()
{
    emit NextClicked();
}


void RadioForm::on_pushButton_5_clicked()
{
    emit FormClicked("main_form");
}

