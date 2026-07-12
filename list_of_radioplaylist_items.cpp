#include "list_of_radioplaylist_items.h"
#include "ui_list_of_radioplaylist_items.h"

ListOfRadioPlaylistItems::ListOfRadioPlaylistItems(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListOfRadioPlaylistItems)
{
    ui->setupUi(this);
    m_playListModel = new QStandardItemModel(this);
    ui->playlistView->setModel(m_playListModel);
}

ListOfRadioPlaylistItems::~ListOfRadioPlaylistItems()
{
    delete ui;
}

void ListOfRadioPlaylistItems::on_songsView_clicked(const QModelIndex &index)
{
    emit ItemsListClicked(index.row());
    //emit MuteMediaPlayer();
}

void ListOfRadioPlaylistItems::setPlaylist(const QStringList& list_of_tracks){
    current_item = 0;
    ui->album_name_label->setText("Favourite");
    m_playListModel->clear();
    foreach (QString item, list_of_tracks){
        QList<QStandardItem *> items;
        items.append(new QStandardItem(item));
        m_playListModel->appendRow(items);
    }
}


void ListOfRadioPlaylistItems::on_pushButton_2_clicked()
{
    emit FormClicked("radio_form");
}

