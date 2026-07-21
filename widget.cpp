#include <QFileDialog>
#include <QDir>
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget() : ui(new Ui::Widget){
    current_player = 0;
    current_item = 0;
    ui->setupUi(this);


    ui->tabWidget->setCurrentIndex(0);
    ui->label_4->setScaledContents(true);
    ui->label_4->setPixmap(QPixmap(":/icons/icons/free-icon-music-note-1816908.png"));
    ui->btn_play_6->hide();

    this->setFixedSize(861, 674);
    m_playListModel = new QStandardItemModel(this);

    ui->playlistView->setModel(m_playListModel);
    ui->playlistView->hideColumn(1);
    ui->playlistView->verticalHeader()->setVisible(false);
    ui->playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->playlistView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->playlistView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->playlistView->horizontalHeader()->setStretchLastSection(true);

    ui->verticalSlider->setValue(50);

    video_widget = new QVideoWidget(ui->groupBox);

    QVBoxLayout *groupLayout = new QVBoxLayout(ui->groupBox);
    groupLayout->setContentsMargins(0, 0, 0, 0);
    groupLayout->addWidget(video_widget);
    video_widget->show();
}

Widget::~Widget()
{
    if (fullScreenWindow != nullptr)
        delete fullScreenWindow;
    delete ui;
}

void Widget::on_btn__clicked()
{
    QStringList files;
    if (current_player == 0)
        files = QFileDialog::getOpenFileNames(this, tr("Open files"), QString(), tr("Audio Files (*.mp3 *.mp4 *.avi *.mkv *.wav *.ogg *.flac)"));
    else
        files = QFileDialog::getOpenFileNames(this, tr("Open files"), QString(), tr("Audio Files (*.mp4 *.avi *.mkv *.mov)"));
    foreach (QString filePath, files) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(QDir(filePath).dirName()));
        items.append(new QStandardItem(filePath));
        m_playListModel->appendRow(items);
    }
    emit UpdateTracksInAlbum(files);
}

void Widget::position_changed(qint64 index){
    ui->horizontalSlider->setValue(index/1000);
}

void Widget::duration_changed(qint64 duration){
    ui->horizontalSlider->setMaximum(duration/1000);
}


void Widget::on_btn_play_clicked()
{
    emit PlayClicked();
}



void Widget::on_tabWidget_currentChanged(int index)
{
    current_player = index;
    current_item = 0;
    emit PlayerChanged(index);
    ui->verticalSlider->setValue(50);
    ui->horizontalSlider->setValue(0);
    if (index == 1){
        emit SetVideoOutput(video_widget);
        ui->btn_play_6->show();
    }
    else
        ui->btn_play_6->hide();
}


void Widget::on_toolButton_2_clicked()
{

}



void Widget::on_playlistView_clicked(const QModelIndex &index){
    emit PlaylistViewClicked(index.row());
    current_item = index.row();
    ui->label->setText(m_playListModel->item(index.row(), 0)->data(Qt::DisplayRole).toString());
}


void Widget::on_horizontalSlider_valueChanged(int value){

}


void Widget::on_horizontalSlider_sliderMoved(int position){
    emit ChangeDurationPositionClicked(position);
}


void Widget::on_likeButton_clicked(){
    emit LikeButtonClicked();
    (ui->label_2->text() == "0") ? ui->label_2->setText("1") : ui->label_2->setText("0");
}

void Widget::updateSlider(const qint64 position) {
    ui->horizontalSlider->setValue(position / 1000);
    if (current_item != m_playListModel->rowCount()-1)
        emit SliderUpdated(position, 0);
    else
        emit SliderUpdated(position, 1);
    TimeFormatter time_formatter;
    ui->label_5->setText(time_formatter.formatTime(position));
}

void Widget::setSliderRange(const qint64 duration) {
    ui->horizontalSlider->setRange(0, duration / 1000);
}

void Widget::setLikeButton(const bool like_status){
    (like_status == false) ? ui->label_2->setText("0") : ui->label_2->setText("1");
}

void Widget::setItemName(const QString& name_of_item){
    ui->label->setText(name_of_item);
}

void Widget::setCurrentItem(const int index){
    current_item = index;
}

void Widget::setPicture(const QPixmap& picture){
    if (!picture.isNull())
        ui->label_4->setPixmap(picture);
    else
        ui->label_4->setPixmap(QPixmap(":/icons/icons/free-icon-music-note-1816908.png"));
}

void Widget::showAddButtons(){
    ui->btn_->show();
    ui->likeButton->show();
    ui->label_2->show();
    ui->label_3->show();
}

void Widget::hideAddButtons(){
    ui->btn_->hide();
    ui->likeButton->hide();
    ui->label_2->hide();
    ui->label_3->hide();
}

void Widget::setSliderRangeAfterSwitchingPlayers(const qint64 duration){
    ui->horizontalSlider->setRange(0, duration/1000);
    ui->horizontalSlider->setValue(0);
}

void Widget::on_pushButton_clicked()
{
    emit FormClicked("playlist_form");
    emit UpdateListOfPlaylists();
}

void Widget::setPlaylist(const QStringList& list_of_tracks, const QString& album_name){
    current_item = 0;
    (album_name != "") ? ui->album_name_label->setText(album_name) : ui->album_name_label->setText("Default Album");
    (!list_of_tracks.isEmpty()) ? ui->label->setText(list_of_tracks[0]) : ui->label->setText("Item name");
    m_playListModel->clear();
    foreach (QString item, list_of_tracks){
        QList<QStandardItem *> items;
        items.append(new QStandardItem(item));
        m_playListModel->appendRow(items);
    }
}

void Widget::on_pushButton_2_clicked()
{
    emit FormClicked("radio_form");
}

void Widget::on_editorButton_clicked()
{
}


void Widget::on_btn_play_3_clicked()
{
    emit PauseClicked();
}


void Widget::on_btn_play_4_clicked()
{
    emit PreviousClicked();
    if (current_item != 0)
        --current_item;
}


void Widget::on_btn_play_5_clicked()
{
    emit NextClicked();
    if (current_item != m_playListModel->rowCount()-1)
        ++current_item;
}


void Widget::on_verticalSlider_valueChanged(int value)
{
    emit ChangeVolumeClicked(value);
}


void Widget::on_pushButton_5_clicked()
{
    emit FormClicked("playlist_form");
    emit UpdateListOfPlaylists();
}


void Widget::on_playlistView_3_clicked(const QModelIndex &index)
{
    emit PlaylistViewClicked(index.row());
    current_item = index.row();
    ui->label->setText(m_playListModel->item(index.row(), 0)->data(Qt::DisplayRole).toString());
}


void Widget::on_horizontalSlider_rangeChanged(int min, int max)
{

}


void Widget::on_btn_play_7_clicked()
{
    emit StopClicked();
}


void Widget::on_toolButton_clicked()
{

}


void Widget::on_pushButton_3_clicked()
{
    emit DeleteItemClicked();
    m_playListModel->removeRow(current_item);
    if (current_item != 0)
        --current_item;
}


void Widget::on_btn_play_6_clicked()
{
    enterFullScreen();
}

void Widget::enterFullScreen() {
    if (!video_widget) return;
    savedParent = ui->groupBox;
    savedLayout = ui->groupBox->layout();

    fullScreenWindow = new QWidget(nullptr, Qt::Window | Qt::FramelessWindowHint);
    fullScreenWindow->setStyleSheet("background: black;");

    video_widget->setParent(fullScreenWindow);

    QVBoxLayout* mainLayout = new QVBoxLayout(fullScreenWindow);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(video_widget);

    controlsPanel = new QWidget();
    controlsPanel->setFixedHeight(120);
    controlsPanel->setStyleSheet("background: rgba(0, 0, 0, 200);");

    QVBoxLayout* panelLayout = new QVBoxLayout(controlsPanel);
    panelLayout->setContentsMargins(20, 5, 20, 10);
    panelLayout->setSpacing(5);

    QHBoxLayout* topRow = new QHBoxLayout();
    topRow->setSpacing(10);

    QLabel* timeLabel = new QLabel("00:00 / 00:00");
    timeLabel->setStyleSheet("color: white; font-size: 13px; min-width: 110px;");

    topRow->addWidget(ui->horizontalSlider);
    topRow->addWidget(timeLabel);
    panelLayout->addLayout(topRow);
    savedTopRow = topRow;

    QHBoxLayout* bottomRow = new QHBoxLayout();
    bottomRow->setSpacing(8);

    QPushButton* prevBtn = new QPushButton("");
    prevBtn->setIcon(QIcon(":/icons/icons/free-icon-previous-18407650.png"));
    QPushButton* playBtn = new QPushButton("");
    playBtn->setIcon(QIcon(":/icons/icons/free-icon-play-1250997.png"));
    QPushButton* pauseBtn = new QPushButton("");
    pauseBtn->setIcon(QIcon(":/icons/icons/free-icon-stop-18407648.png"));
    QPushButton* stopBtn = new QPushButton("");
    stopBtn->setIcon(QIcon(":/icons/icons/free-icon-black-square-1601.png"));
    QPushButton* nextBtn = new QPushButton("");
    nextBtn->setIcon(QIcon(":/icons/icons/free-icon-music-player-5733742.png"));
    QPushButton* exitBtn = new QPushButton("");
    exitBtn->setIcon(QIcon(":/icons/icons/free-icon-reduce-722302.png"));

    QString btnStyle = R"(
        QPushButton {
            color: white;
            background: rgba(255, 255, 255, 20);
            border: 1px solid rgba(255,255,255,30);
            border-radius: 4px;
            padding: 8px 16px;
            font-size: 16px;
            font-weight: bold;
            min-width: 40px;
            min-height: 30px;
        }
        QPushButton:hover {
            background: rgba(255, 255, 255, 60);
        }
    )";

    prevBtn->setStyleSheet(btnStyle);
    playBtn->setStyleSheet(btnStyle);
    pauseBtn->setStyleSheet(btnStyle);
    stopBtn->setStyleSheet(btnStyle);
    nextBtn->setStyleSheet(btnStyle);
    exitBtn->setStyleSheet(btnStyle);

    QLabel* volLabel = new QLabel("🔊");
    volLabel->setStyleSheet("color: white; font-size: 16px;");

    QSlider* volumeSlider = new QSlider(Qt::Vertical);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(ui->verticalSlider->value());
    volumeSlider->setFixedHeight(40);
    volumeSlider->setStyleSheet(R"(
        QSlider::groove:vertical {
            width: 4px;
            background: rgba(255,255,255,50);
            border-radius: 2px;
        }
        QSlider::handle:vertical {
            background: #4CAF50;
            width: 14px;
            height: 14px;
            margin: 0 -5px;
            border-radius: 7px;
        }
        QSlider::sub-page:vertical {
            background: #4CAF50;
            border-radius: 2px;
        }
    )");

    bottomRow->addWidget(prevBtn);
    bottomRow->addWidget(playBtn);
    bottomRow->addWidget(pauseBtn);
    bottomRow->addWidget(stopBtn);
    bottomRow->addWidget(nextBtn);
    bottomRow->addStretch();
    bottomRow->addWidget(volLabel);
    bottomRow->addWidget(volumeSlider);
    bottomRow->addWidget(exitBtn);

    panelLayout->addLayout(bottomRow);
    mainLayout->addWidget(controlsPanel);

    connect(playBtn, &QPushButton::clicked, this, &Widget::on_btn_play_clicked);
    connect(pauseBtn, &QPushButton::clicked, this, &Widget::on_btn_play_3_clicked);
    connect(stopBtn, &QPushButton::clicked, this, &Widget::on_btn_play_7_clicked);
    connect(prevBtn, &QPushButton::clicked, this, &Widget::on_btn_play_4_clicked);
    connect(nextBtn, &QPushButton::clicked, this, &Widget::on_btn_play_5_clicked);
    connect(exitBtn, &QPushButton::clicked, this, &Widget::exitFullScreen);

    connect(volumeSlider, &QSlider::valueChanged, this, Widget::on_verticalSlider_valueChanged);

    volumeSlider->setValue(ui->verticalSlider->value());

    hideControlsTimer = new QTimer(this);
    hideControlsTimer->setSingleShot(true);
    connect(hideControlsTimer, &QTimer::timeout, this, [this]() {
        toggleControlsVisibility(false);
    });

    fullScreenWindow->setMouseTracking(true);
    fullScreenWindow->installEventFilter(this);

    controlsVisible = true;
    toggleControlsVisibility(true);
    hideControlsTimer->start(5000);

    fullScreenWindow->showFullScreen();
    fullScreenWindow->setMouseTracking(true);
    video_widget->setMouseTracking(true);
    controlsPanel->setMouseTracking(true);

    fullScreenWindow->installEventFilter(this);
    video_widget->installEventFilter(this);
    controlsPanel->installEventFilter(this);
}

void Widget::toggleControlsVisibility(bool show) {
    if (!controlsPanel) return;

    controlsVisible = show;
    controlsPanel->setVisible(show);

    if (fullScreenWindow) {
        fullScreenWindow->setCursor(show ? Qt::ArrowCursor : Qt::BlankCursor);
    }
}

void Widget::startHideTimer() {
    if (hideControlsTimer) {
        hideControlsTimer->stop();
        hideControlsTimer->start(5000);
    }
}

bool Widget::eventFilter(QObject* obj, QEvent* event) {
    if (obj == fullScreenWindow) {
        if (event->type() == QEvent::MouseMove) {
            if (!controlsVisible) {
                toggleControlsVisibility(true);
            }
            startHideTimer();
            return false;
        }
        else if (event->type() == QEvent::Leave) {
            toggleControlsVisibility(false);
            if (hideControlsTimer) {
                hideControlsTimer->stop();
            }
            return false;
        }
    }
    return QWidget::eventFilter(obj, event);
}

void Widget::exitFullScreen() {
    if (!fullScreenWindow) return;

    if (hideControlsTimer) {
        hideControlsTimer->stop();
    }

    video_widget->setParent(savedParent);
    video_widget->setWindowFlags(Qt::Widget);

    if (savedLayout) {
        savedLayout->addWidget(video_widget);
    }
    video_widget->show();

    ui->horizontalSlider->setParent(ui->stackedWidget);
    ui->horizontalSlider->setGeometry(30, 570, 541, 16);
    ui->horizontalSlider->show();

    if (fullscreen_volume_slider) {
        ui->verticalSlider->setValue(fullscreen_volume_slider->value());
    }

    fullScreenWindow->close();
    delete fullScreenWindow;
    fullScreenWindow = nullptr;

    savedParent = nullptr;
    savedLayout = nullptr;
    controlsPanel = nullptr;
    controlsVisible = true;
}

void Widget::increaseCurrentItem(){
    ++current_item;
}

void Widget::closeEvent(QCloseEvent *event){
    disconnect(this, &Widget::SliderUpdated, nullptr, nullptr);
    QWidget::closeEvent(event);
}

void Widget::on_pushButton_4_clicked()
{
    emit FormClicked("cutter_form");
}

