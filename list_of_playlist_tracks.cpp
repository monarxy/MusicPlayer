#include "list_of_playlist_tracks.h"
#include "ui_list_of_playlist_tracks.h"

ListOfPlaylistTracks::ListOfPlaylistTracks() :
    ui(new Ui::ListOfPlaylistTracks)
{
    current_player = 0;
    this->setFixedSize(861, 674);
    ui->setupUi(this);
    current_playlist_model = new QStandardItemModel(this);
    ui->songsView->setModel(current_playlist_model);
    current_playlist_model->setHorizontalHeaderLabels(QStringList()  << tr("Item"));
    ui->songsView->verticalHeader()->setVisible(false);
    ui->songsView->horizontalHeader()->setStretchLastSection(true);

    current_playlist_model->clear();
}

void ListOfPlaylistTracks::setItems(const QStringList& list_of_tracks, const QString& album_name, const int _is_favourite_album){
    is_favourite_album = _is_favourite_album;
    if (is_favourite_album == 1){
        ui->pushButton_3->hide();
        ui->pushButton->hide();
    }
    else{
        ui->pushButton_3->show();
        ui->pushButton->show();
    }
    ui->label->setText(album_name);
    current_playlist = album_name;
    current_playlist_model->clear();
    for (const QString& item : list_of_tracks){
        QList<QStandardItem *> items;
        items.append(new QStandardItem(item));
        current_playlist_model->appendRow(items);
    }
}

void ListOfPlaylistTracks::showAddAndDeleteButtons(){
    ui->pushButton_3->show();
    ui->pushButton->show();
}

void ListOfPlaylistTracks::setPlayer(const int index){
    current_player = index;
}

void ListOfPlaylistTracks::hideDeleteButton(){
    ui->pushButton_3->hide();
}

void ListOfPlaylistTracks::showDeleteButton(){
    ui->pushButton_3->show();
}

void ListOfPlaylistTracks::hideAddAndDeleteButtons(){
    ui->pushButton_3->hide();
    ui->pushButton->hide();
}

ListOfPlaylistTracks::~ListOfPlaylistTracks()
{
    delete ui;
}

void ListOfPlaylistTracks::on_pushButton_clicked()
{
    QStringList files;
    if (current_player == 0)
        files = QFileDialog::getOpenFileNames(this, tr("Open files"),QString(), tr("Audio Files (*.mp3 *.mp4 *.avi *.mkv *.wav *.ogg *.flac)"));
    else
        files = QFileDialog::getOpenFileNames(this, tr("Open files"), QString(), tr("Audio Files (*.mp4 *.avi *.mkv *.mov)"));
    for (const QString& filePath : files) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(QDir(filePath).dirName()));
        items.append(new QStandardItem(filePath));
        current_playlist_model->appendRow(items);

    }
    emit ItemsAddedToPlaylist(ui->label->text(), files);

}


void ListOfPlaylistTracks::on_pushButton_2_clicked()
{
    emit FormClicked("playlist_form");
}


void ListOfPlaylistTracks::on_songsView_clicked(const QModelIndex &index)
{
    const QString album_name = ui->label->text();
    if (album_name == "Default Album")
        emit ItemsListClicked(index.row(), "", is_favourite_album);
    else
        emit ItemsListClicked(index.row(), album_name, is_favourite_album);
    emit MuteRadioPlayer();
}


void ListOfPlaylistTracks::on_pushButton_3_clicked()
{
    emit DeletePlaylistClicked(current_playlist);
    emit UpdateListOfPlaylists();
    emit FormClicked("playlist_form");
}

