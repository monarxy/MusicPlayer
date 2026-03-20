#ifndef PLAYLISTFORM_H
#define PLAYLISTFORM_H

#include <QWidget>
#include <QInputDialog>
#include <QStandardItemModel>
#include <vector>

namespace Ui {
class PlaylistForm;
}

class PlaylistForm : public QWidget
{
    Q_OBJECT

public:
    PlaylistForm();
    ~PlaylistForm();

    void setListOfPlaylists(const QStringList&);
private:
    Ui::PlaylistForm *ui;
    QStandardItemModel *playlists_model;
    QWidget *list_of_playlists_tracks_form;

signals:
    void FormClicked(const QString& form_name);
    void ListOfPlaylistsTracksClicked(const QString& album_name);
    void NewAlbumAddedClicked(QString album_name);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_playlistsView_clicked(const QModelIndex &index);

};

#endif // PLAYLISTFORM_H
