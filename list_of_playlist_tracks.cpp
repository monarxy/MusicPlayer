#include "list_of_playlist_tracks.h"
#include "ui_list_of_playlist_tracks.h"

ListOfPlaylistTracks::ListOfPlaylistTracks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListOfPlaylistTracks), parent_form(parent)
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
}

ListOfPlaylistTracks::~ListOfPlaylistTracks()
{
    delete ui;
}

void ListOfPlaylistTracks::setTracks(Playlist *_playlist){
     playlist = _playlist;
     ui->label->setText(playlist->getName());
     current_playlist_model->clear();
     foreach (MediaData* song, *(playlist->getListOfItems())){
         QList<QStandardItem *> items;
         items.append(new QStandardItem(QDir(song->getPath()).dirName()));
         current_playlist_model->appendRow(items);
     }

}

void ListOfPlaylistTracks::on_pushButton_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      tr("Open files"),
                                                      QString(),
                                                      tr("Audio Files (*.mp3)"));

    // Далее устанавливаем данные по именам и пути к файлам
    // в плейлист и таблицу отображающую плейлист
    foreach (QString filePath, files) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(QDir(filePath).dirName()));
        items.append(new QStandardItem(filePath));
        current_playlist_model->appendRow(items);
        playlist->getListOfItems()->push_back(new SongData(filePath));
    }
    //auto tmp = static_cast<PlaylistForm*>(parent_form)->getParent();
    //auto t = static_cast<Widget*>(tmp);
    //t->move_home();
}


void ListOfPlaylistTracks::on_pushButton_2_clicked()
{
    emit PlaylistsFormClicked();
}


void ListOfPlaylistTracks::on_songsView_clicked(const QModelIndex &index)
{
    (static_cast<Widget*>(static_cast<PlaylistForm*>(parent_form)->getParent()))->setPlaylist(playlist);
    (static_cast<Widget*>(static_cast<PlaylistForm*>(parent_form)->getParent()))->getPlayer()->setCurrent(index.row());
}

