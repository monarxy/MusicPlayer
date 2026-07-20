#ifndef LIST_OF_PLAYLIST_TRACKS_H
#define LIST_OF_PLAYLIST_TRACKS_H

#include <QFileDialog>
#include <QWidget>
#include <QDir>
#include <QStandardItemModel>
#include "playlist.h"
#include "playlistform.h"
#include "widget.h"

namespace Ui {
class ListOfPlaylistTracks;
}

class ListOfPlaylistTracks : public QWidget
{
    Q_OBJECT

public:
    ListOfPlaylistTracks();
    ~ListOfPlaylistTracks();
    void setItems(const QStringList&, const QString&, const int);
    void hideAddAndDeleteButtons();
    void showAddAndDeleteButtons();
    void setPlayer(const int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_songsView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

signals:
    void FormClicked(const QString&);
    void ItemsAddedToPlaylist(const QString&, const QStringList&);
    void ItemsListClicked(const int, const QString&, const int);
    void MuteRadioPlayer();
    void DeletePlaylistClicked(const QString&);
    void UpdateListOfPlaylists();

private:
    Ui::ListOfPlaylistTracks *ui;
    QStandardItemModel *current_playlist_model;
    QString current_playlist;
    int is_favourite_album;
    int current_player;
};

#endif // LIST_OF_PLAYLIST_TRACKS_H
