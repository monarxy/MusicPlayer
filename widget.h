#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QOpenGLWidget>
#include <gl/glu.h>
#include <gl/gl.h>
#include "multimedia.h"
#include "music_player.h"
#include "media_data.h"
#include "songs_data.h"
#include "playlistform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void setPlaylist(Playlist*);

    MediaPlayer* getPlayer();

private slots:
    void on_btn__clicked();

    void on_btn_play_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_toolButton_2_clicked();

    void on_playlistView_clicked(const QModelIndex &index);

    void on_horizontalSlider_valueChanged(int value);

    void on_verticalSlider_actionTriggered(int action);

    void position_changed(qint64 index);

    void duration_changed(qint64 duration);

    void on_horizontalSlider_sliderMoved(int position);

    void on_likeButton_clicked();

    void on_pushButton_clicked();

    void move_home();

private:
    Ui::Widget *ui;
    MediaPlayer *player;
    MediaPlayer *video_player;
    QStandardItemModel  *m_playListModel;
    QWidget *playlist_form;

};

#endif // WIDGET_H
