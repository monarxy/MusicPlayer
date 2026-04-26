#include "list_of_playlist_tracks.h"
#include "ui_list_of_playlist_tracks.h"

ListOfPlaylistTracks::ListOfPlaylistTracks() :
    ui(new Ui::ListOfPlaylistTracks)
{
    ui->setupUi(this);
    current_playlist_model = new QStandardItemModel(this);
    ui->songsView->setModel(current_playlist_model);
    current_playlist_model->setHorizontalHeaderLabels(QStringList()  << tr("Track"));
    ui->songsView->verticalHeader()->setVisible(false);
    ui->songsView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->songsView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->songsView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->songsView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    current_playlist_model->clear();
}

void ListOfPlaylistTracks::setItems(const QStringList& list_of_tracks, const QString& album_name){
    ui->label->setText(album_name);
    current_playlist_model->clear();
    for (const QString& item : list_of_tracks){
        QList<QStandardItem *> items;
        items.append(new QStandardItem(item));
        current_playlist_model->appendRow(items);
    }
}

ListOfPlaylistTracks::~ListOfPlaylistTracks()
{
    delete ui;
}

void ListOfPlaylistTracks::on_pushButton_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      tr("Open files"),
                                                      QString(),
                                                      tr("Audio Files (*.mp3)"));

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
    emit ItemsListClicked(index.row(), ui->label->text());
}

