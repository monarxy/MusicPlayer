#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtGui>
#include <QStandardItemModel>
#include <QIcon>
#include <QTimer>
#include <QVBoxLayout>
#include <QMediaContent>
#include <QSlider>
#include <QCloseEvent>
#include "time_formatter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget();
    ~Widget();

    void setPlaylist(const QStringList&, const QString&);
    void updateSlider(const qint64);
    void setSliderRange(const qint64);
    void setSliderRangeAfterSwitchingPlayers(const qint64);
    void setLikeButton(const bool);
    void setItemName(const QString&);
    void setCurrentItem(const int);
    void setPicture(const QPixmap&);
    void showAddButtons();
    void hideAddButtons();
    void enterFullScreen();
    void exitFullScreen();
    void increaseCurrentItem();
    bool eventFilter(QObject* obj, QEvent* event);


signals:
    void FormClicked(const QString&);
    void PlaylistViewClicked(const int);
    void PlayClicked();
    void PauseClicked();
    void StopClicked();
    void NextClicked();
    void PreviousClicked();
    void ChangeVolumeClicked(const int);
    void ChangeDurationPositionClicked(const int);

    void LikeButtonClicked();

    void SliderUpdated(const qint64, const int);

    void UpdateTracksInAlbum(const QStringList& list_of_tracks);
    void PlayerChanged(const int);
    void UpdateListOfPlaylists();

    void SetVideoOutput(QVideoWidget*);
    void DeleteItemClicked();

private slots:
    void on_btn__clicked();

    void on_btn_play_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_toolButton_2_clicked();

    void on_playlistView_clicked(const QModelIndex &index);

    void on_horizontalSlider_valueChanged(int value);

    void position_changed(qint64 index);

    void duration_changed(qint64 duration);

    void on_horizontalSlider_sliderMoved(int position);

    void on_likeButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_editorButton_clicked();

    void on_btn_play_3_clicked();

    void on_btn_play_4_clicked();

    void on_btn_play_5_clicked();

    void on_verticalSlider_valueChanged(int value);

    void on_pushButton_5_clicked();

    void on_playlistView_3_clicked(const QModelIndex &index);

    void on_horizontalSlider_rangeChanged(int min, int max);

    void on_btn_play_7_clicked();

    void on_toolButton_clicked();

    void on_pushButton_3_clicked();

    void on_btn_play_6_clicked();

    void toggleControlsVisibility(bool);

    void startHideTimer();

private:
    void closeEvent(QCloseEvent *event) override;

    Ui::Widget* ui;
    QStandardItemModel* m_playListModel;
    QVideoWidget* video_widget;
    QWidget *fullScreenWindow = nullptr;
    QWidget *savedParent = nullptr;
    QLayout *savedLayout = nullptr;
    QHBoxLayout* savedTopRow = nullptr;
    QSlider* fullscreen_volume_slider = nullptr;
    QWidget* controlsPanel = nullptr;
    QTimer* hideControlsTimer = nullptr;
    bool controlsVisible = true;

    int current_player;
    int current_item;
};

#endif // WIDGET_H
