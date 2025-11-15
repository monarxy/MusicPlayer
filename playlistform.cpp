#include "playlistform.h"
#include "ui_playlistform.h"


PlaylistForm::PlaylistForm() :
    ui(new Ui::PlaylistForm)
{
    ui->setupUi(this);
    list_of_playlists_tracks_form = new ListOfPlaylistTracks(this);
    playlists_model = new QStandardItemModel(this);
    ui->playlistsView->setModel(playlists_model);    // Устанавливаем модель данных в TableView
        // Устанавливаем заголовки таблицы
    playlists_model->setHorizontalHeaderLabels(QStringList()  << tr("Album name"));
    ui->playlistsView->verticalHeader()->setVisible(false);                  // Скрываем нумерацию строк
    ui->playlistsView->setSelectionBehavior(QAbstractItemView::SelectRows);  // Включаем выделение строк
    ui->playlistsView->setSelectionMode(QAbstractItemView::SingleSelection); // Разрешаем выделять только одну строку
    ui->playlistsView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->playlistsView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    //ui->stackedWidget->insertWidget(0, this);
    ui->stackedWidget->insertWidget(1, list_of_playlists_tracks_form);

    connect(static_cast<ListOfPlaylistTracks*>(list_of_playlists_tracks_form), &ListOfPlaylistTracks::PlaylistsFormClicked, this, &PlaylistForm::move_to_playlists_form);
}

PlaylistForm::~PlaylistForm()
{
    delete ui;
}

void PlaylistForm::on_pushButton_clicked()
{
    emit HomeClicked();
}

void PlaylistForm::move_to_playlists_form(){
    ui->stackedWidget->setCurrentIndex(0);
}

void PlaylistForm::on_pushButton_2_clicked()
{
    QString album_name = QInputDialog::getText(this, "New album", "Enter album's name");
    ui->label->setText(album_name);
    if (album_name!=""){
        QList<QStandardItem *> items;
        items.append(new QStandardItem(album_name));
        playlists_model->appendRow(items);
        list_of_playlists.push_back(new Playlist(album_name));
    }

}




void PlaylistForm::on_playlistsView_clicked(const QModelIndex &index)
{
    static_cast<ListOfPlaylistTracks*>(list_of_playlists_tracks_form)->setTracks(list_of_playlists[index.row()]);
    ui->stackedWidget->setCurrentIndex(1);
}


