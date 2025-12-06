#include "list_of_playlist_tracks.h"
#include "ui_list_of_playlist_tracks.h"

ListOfPlaylistTracks::ListOfPlaylistTracks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListOfPlaylistTracks)
{
    ui->setupUi(this);
    current_playlist_model = new QStandardItemModel(this);
    ui->songsView->setModel(current_playlist_model);    // Устанавливаем модель данных в TableView
        // Устанавливаем заголовки таблицы
    current_playlist_model->setHorizontalHeaderLabels(QStringList()  << tr("Track"));
    ui->songsView->verticalHeader()->setVisible(false);                  // Скрываем нумерацию строк
    ui->songsView->setSelectionBehavior(QAbstractItemView::SelectRows);  // Включаем выделение строк
    ui->songsView->setSelectionMode(QAbstractItemView::SingleSelection); // Разрешаем выделять только одну строку
    ui->songsView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->songsView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    current_playlist_model->clear();
    // foreach (MediaData* song, *(data_controller->getPlayer()->getPlaylist()->getListOfItems())){
    //     QList<QStandardItem *> items;
    //     items.append(new QStandardItem(QDir(song->getPath()).dirName()));
    //     current_playlist_model->appendRow(items);
    // }
}

void ListOfPlaylistTracks::setLabelText(QString album_name){
    ui->label->setText(album_name);
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

    foreach (QString filePath, files) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(QDir(filePath).dirName()));
        items.append(new QStandardItem(filePath));
        current_playlist_model->appendRow(items);
        //data_controller->getPlayer()->getPlaylist()->getListOfItems()->push_back(new SongData(filePath));
    }
}


void ListOfPlaylistTracks::on_pushButton_2_clicked()
{
    //navigation_controller->openPlaylistForm();
}


void ListOfPlaylistTracks::on_songsView_clicked(const QModelIndex &index)
{

}

