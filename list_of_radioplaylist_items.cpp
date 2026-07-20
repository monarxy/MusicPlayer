#include "list_of_radioplaylist_items.h"
#include "ui_list_of_radioplaylist_items.h"

ListOfRadioPlaylistItems::ListOfRadioPlaylistItems(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListOfRadioPlaylistItems)
{
    this->setFixedSize(861, 674);
    ui->setupUi(this);
    m_playListModel = new QStandardItemModel(this);
    ui->playlistView->setModel(m_playListModel);
    ui->playlistView->horizontalHeader()->setStretchLastSection(true);
}

ListOfRadioPlaylistItems::~ListOfRadioPlaylistItems()
{
    delete ui;
}

void ListOfRadioPlaylistItems::setPlaylist(const QStringList& list_of_tracks){
    ui->label->setText("Favourite");
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


void ListOfRadioPlaylistItems::on_playlistView_clicked(const QModelIndex &index)
{
    emit ItemsListClicked(index.row(), 1);
}
