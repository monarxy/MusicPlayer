#include "widget.h"
#include "multimedia.h"
#include "music_player.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget), player(new MusicPlayer){
    ui->setupUi(this);
    playlist_form = new PlaylistForm(this);
    m_playListModel = new QStandardItemModel(this);
    ui->playlistView->setModel(m_playListModel);    // Устанавливаем модель данных в TableView
        // Устанавливаем заголовки таблицы
    m_playListModel->setHorizontalHeaderLabels(QStringList()  << tr("Audio Track") << tr("File Path"));
    ui->playlistView->hideColumn(1);    // Скрываем колонку, в которой хранится путь к файлу
    ui->playlistView->verticalHeader()->setVisible(false);                  // Скрываем нумерацию строк
    ui->playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);  // Включаем выделение строк
    ui->playlistView->setSelectionMode(QAbstractItemView::SingleSelection); // Разрешаем выделять только одну строку
    ui->playlistView->setEditTriggers(QAbstractItemView::NoEditTriggers);   // Отключаем редактирование
        // Включаем подгонку размера последней видимой колонки к ширине TableView
    ui->playlistView->horizontalHeader()->setStretchLastSection(true);
    ui->stackedWidget->insertWidget(1, playlist_form);
    connect(player->getPlayer(), &QMediaPlayer::positionChanged, this, &Widget::position_changed);
    connect(player->getPlayer(), &QMediaPlayer::durationChanged, this, &Widget::duration_changed);
    connect(static_cast<PlaylistForm*>(playlist_form), &PlaylistForm::HomeClicked, this, &Widget::move_home);
    //ui->horizontalSlider->setRange(0, player->m_player->duration()/1000);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_btn__clicked()
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
        m_playListModel->appendRow(items);
        player->getQPlaylist()->addMedia(QUrl(filePath));
        player->getPlaylist()->setListOfItems(new SongData(filePath));
        //player->list_of_items.push_back(new SongData(filePath));
    }
}

void Widget::position_changed(qint64 index){
    ui->horizontalSlider->setValue(index/1000);
}

void Widget::duration_changed(qint64 duration){
    ui->horizontalSlider->setMaximum(duration/1000);
}


void Widget::on_btn_play_clicked()
{
    player->play();
}


void Widget::on_tabWidget_currentChanged(int index)
{

}


void Widget::on_toolButton_2_clicked()
{

}



void Widget::on_playlistView_clicked(const QModelIndex &index)
{
    QString s = QString::number(index.row());
    //ui->label->setText(m_playListModel->item(index.row(), 1)->data(Qt::DisplayRole).toString());
    //layer->getPlaylist()->setCurrentIndex(index.row());
    player->setCurrent(index.row());
    if (player->getCurrentItem()->getLikeInfo()) ui->label->setText("1");
    else ui->label->setText("0");
}


void Widget::on_horizontalSlider_valueChanged(int value)
{

}


void Widget::on_verticalSlider_actionTriggered(int action)
{
     player->changeVolume(action);
}


void Widget::on_horizontalSlider_sliderMoved(int position)
{
    player->changeDuration(position);
}


void Widget::on_likeButton_clicked()
{
    player->setLike();
}

MediaPlayer* Widget::getPlayer(){
    return player;
}


void Widget::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::move_home()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::setPlaylist(Playlist* new_playlist){
    ui->album_name_label->setText(new_playlist->getName());
    m_playListModel->clear();
    player->setPlaylist(new_playlist);
    player->deleteQPlaylist();
    foreach (MediaData* item, *(new_playlist->getListOfItems())) {
         QList<QStandardItem *> items;
         items.append(new QStandardItem(QDir(item->getPath()).dirName()));
         items.append(new QStandardItem(item->getPath()));
         m_playListModel->appendRow(items);
         player->getQPlaylist()->addMedia(QUrl(item->getPath()));
    }
}
