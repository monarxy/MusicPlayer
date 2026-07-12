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
signals:
    void FormClicked(const QString&);
    void PlayClicked();
    void PreviousClicked();
    void NextClicked();
    void RadioPlaylistViewClicked(const int);
    void NewRadiostationAddedClicked(const QString&);
    void DeleteRadiostationClicked();
    void FavouritePlaylistClicked();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_playlistView_clicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::RadioForm *ui;
    QStandardItemModel  *m_playListModel;
    int current_row;
};

#endif // RADIOFORM_H
