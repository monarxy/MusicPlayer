#include "playlistform.h"
#include "ui_playlistform.h"


PlaylistForm::PlaylistForm() :
    ui(new Ui::PlaylistForm)
{
    ui->setupUi(this);
    playlists_model = new QStandardItemModel(this);
    ui->playlistsView->setModel(playlists_model);
    playlists_model->setHorizontalHeaderLabels(QStringList()  << tr("Album name"));
    ui->playlistsView->verticalHeader()->setVisible(false);                  // Скрываем нумерацию строк
    ui->playlistsView->setSelectionBehavior(QAbstractItemView::SelectRows);  // Включаем выделение строк
    ui->playlistsView->setSelectionMode(QAbstractItemView::SingleSelection); // Разрешаем выделять только одну строку
    ui->playlistsView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->playlistsView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
}

PlaylistForm::~PlaylistForm()
{
    delete ui;
}

void PlaylistForm::on_pushButton_clicked()
{
    emit HomeClicked();
}

void PlaylistForm::on_pushButton_2_clicked()
{
    QString album_name = QInputDialog::getText(this, "New album", "Enter album's name");
    ui->label->setText(album_name);
    if (album_name!=""){
        QList<QStandardItem *> items;
        items.append(new QStandardItem(album_name));
        playlists_model->appendRow(items);
    }

}

void PlaylistForm::on_playlistsView_clicked(const QModelIndex &index)
{
    emit ListOfPlaylistsTracksClicked(ui->playlistsView->model()->data(index).toString());
}


