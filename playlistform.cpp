#include "playlistform.h"
#include "ui_playlistform.h"


PlaylistForm::PlaylistForm() :
    ui(new Ui::PlaylistForm)
{
    this->setFixedSize(861, 674);
    ui->setupUi(this);
    playlists_model = new QStandardItemModel(this);
    ui->playlistsView->setModel(playlists_model);
    ui->playlistsView->horizontalHeader()->setStretchLastSection(true);
}

PlaylistForm::~PlaylistForm()
{
    delete ui;
}

void PlaylistForm::on_pushButton_clicked()
{
    emit FormClicked("main_form");
}

void PlaylistForm::on_pushButton_2_clicked()
{
    QString album_name = QInputDialog::getText(this, "New album", "Enter album's name");
    if (album_name!="Default Album"){
        QList<QStandardItem *> items;
        items.append(new QStandardItem(album_name));
        playlists_model->appendRow(items);
        emit NewAlbumAddedClicked(album_name);
    }
    else
        QMessageBox::warning(this, "Warning", "You can't create playlist with name of basic playlist. Change other name.");

}

void PlaylistForm::on_playlistsView_clicked(const QModelIndex &index)
{
    auto name = ui->playlistsView->model()->data(index).toString();
    if (name == "Default Album"){
        emit ListOfPlaylistsTracksClicked("");
        emit HideDeleteButtonOnItemsForm();
    }
    else{
        emit ListOfPlaylistsTracksClicked(name);
        emit ShowDeleteButtonOnItemsForm();
    }
    emit FormClicked("list_of_playlist_tracks_form");
}

void PlaylistForm::setListOfPlaylists(const QStringList& list_of_playlists){
    playlists_model->clear();
    for (const QString& playlist_name : list_of_playlists){
        QList<QStandardItem *> items;
        (playlist_name == "") ? items.append(new QStandardItem("Default Album")) : items.append(new QStandardItem(playlist_name));
        playlists_model->appendRow(items);
    }
}

void PlaylistForm::on_pushButton_3_clicked()
{
    emit FavouritePlaylistClicked();
    emit FormClicked("list_of_playlist_tracks_form");
}

