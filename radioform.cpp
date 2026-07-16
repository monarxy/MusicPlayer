#include "radioform.h"
#include "ui_radioform.h"
#include <QDebug>

RadioForm::RadioForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RadioForm)
{
    current_item = 0;
    ui->setupUi(this);
    m_playListModel = new QStandardItemModel(this);
    ui->playlistView->setModel(m_playListModel);
    ui->pushButton_9->hide();
    ui->verticalSlider->setValue(50);
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

void RadioForm::setCurrentIndex(const int index){
    current_item = index;
}

void RadioForm::setLikeButton(const bool like_status){
    (like_status == false) ? ui->label_2->setText("0") : ui->label_2->setText("1");
}

void RadioForm::enableButtonsForFavouritePlaylist(){
    ui->pushButton_4->show();
    ui->pushButton_8->show();
    ui->label_3->show();
    ui->label_2->show();
    ui->likeButton->show();
    ui->pushButton_9->hide();
}

void RadioForm::disableButtonsForFavouritePlaylist(){
    ui->pushButton_4->hide();
    ui->pushButton_8->hide();
    ui->label_3->hide();
    ui->label_2->hide();
    ui->likeButton->hide();
    ui->pushButton_9->show();
}

void RadioForm::setCurrentName(const QString& radiostation_name){
    ui->label->setText(radiostation_name);
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
        if (current_item != 0)
            --current_item;
    }

}


void RadioForm::on_pushButton_2_clicked()
{
    if (m_playListModel->rowCount() != 0){
        emit NextClicked();
        if (current_item != m_playListModel->rowCount()-1)
            ++current_item;
    }

}


void RadioForm::on_pushButton_5_clicked()
{
    emit FormClicked("main_form");
}


void RadioForm::on_playlistView_clicked(const QModelIndex &index)
{
    emit RadioPlaylistViewClicked(index.row());
    current_item = index.row();
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
    m_playListModel->removeRow(current_item);
    if (m_playListModel->rowCount()-1 < current_item)
        --current_item;
    emit DeleteRadiostationClicked();
}


void RadioForm::on_pushButton_8_clicked()
{
    emit FavouritePlaylistClicked();
    emit FormClicked("list_of_radioplaylist_items_form");
}


void RadioForm::on_likeButton_clicked()
{
    emit LikeButtonClicked();
    (ui->label_2->text() == "0") ? ui->label_2->setText("1") : ui->label_2->setText("0");
}


void RadioForm::on_pushButton_9_clicked()
{
    emit ItemsListClicked(0, 0);
}


void RadioForm::on_verticalSlider_valueChanged(int value)
{
    emit ChangeVolumeClicked(value);
}


void RadioForm::on_pushButton_7_clicked()
{
    emit PauseClicked();
}


void RadioForm::on_pushButton_10_clicked()
{
    emit StopClicked();
}

