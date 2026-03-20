#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QOpenGLWidget>
#include <gl/glu.h>
#include <gl/gl.h>
#include <QIcon>


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
    void setLikeButton(const bool);
signals:
    void FormClicked(const QString&);
    void PlaylistViewClicked(const int);
    void PlayClicked();
    void PauseClicked();
    void NextClicked();
    void PreviousClicked();
    void ChangeVolumeClicked(const int);
    void ChangeDurationPositionClicked(const int);

    void LikeButtonClicked();

    void UpdateTracksInAlbum(const QStringList& list_of_tracks);

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

private:
    Ui::Widget *ui;
    QStandardItemModel  *m_playListModel;
    QWidget *editor_form;

};

#endif // WIDGET_H
