#ifndef RADIOFORM_H
#define RADIOFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include <QInputDialog>

namespace Ui {
class RadioForm;
}

class RadioForm : public QWidget
{
    Q_OBJECT

public:
    explicit RadioForm(QWidget *parent = nullptr);
    ~RadioForm();
    void setPlaylist(const QStringList& list_of_tracks);
    void setCurrentIndex(const int);
    void setLikeButton(const bool);
    void setCurrentName(const QString&);
    void enableButtonsForFavouritePlaylist();
    void disableButtonsForFavouritePlaylist();
signals:
    void FormClicked(const QString&);
    void PlayClicked();
    void PauseClicked();
    void StopClicked();
    void PreviousClicked();
    void NextClicked();
    void RadioPlaylistViewClicked(const int);
    void NewRadiostationAddedClicked(const QString&);
    void DeleteRadiostationClicked();
    void FavouritePlaylistClicked();
    void LikeButtonClicked();
    void ItemsListClicked(const int, const int);
    void ChangeVolumeClicked(const int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_playlistView_clicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_likeButton_clicked();

    void on_pushButton_9_clicked();

    void on_verticalSlider_valueChanged(int value);

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::RadioForm *ui;
    QStandardItemModel  *m_playListModel;
    int current_item;
};

#endif // RADIOFORM_H
