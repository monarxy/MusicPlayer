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
}

void RadioForm::on_pushButton_clicked()
{
    if (m_playListModel->rowCount() != 0){
        emit PlayClicked();}
}


void RadioForm::on_pushButton_3_clicked()
{
    if (m_playListModel->rowCount() != 0){
        emit PreviousClicked();
        if (current_row != 0)
            --current_row;
    }

}


void RadioForm::on_pushButton_2_clicked()
{
    if (m_playListModel->rowCount() != 0){
        emit NextClicked();
        if (current_row != m_playListModel->rowCount()-1)
            ++current_row;
    }

}


void RadioForm::on_pushButton_5_clicked()
{
    emit FormClicked("main_form");
}


void RadioForm::on_playlistView_clicked(const QModelIndex &index)
{
    emit RadioPlaylistViewClicked(index.row());
    emit PlayClicked();
}


void RadioForm::on_pushButton_4_clicked()
{
    QString radiostation_name = QInputDialog::getText(this, "New radiostation", "Enter radiostation's URL");
    if (radiostation_name!=""){
        QList<QStandardItem *> items;
        items.append(new QStandardItem(radiostation_name));
        m_playListModel->appendRow(items);
        emit NewRadiostationAddedClicked(radiostation_name);
    }
}


void RadioForm::on_pushButton_6_clicked()
{
    m_playListModel->removeRow(current_row);
    if (m_playListModel->rowCount()-1 < current_row)
        --current_row;
    emit DeleteRadiostationClicked();
}

