#ifndef LIST_OF_PLAYLIST_TRACKS_H
#define LIST_OF_PLAYLIST_TRACKS_H

#include <QFileDialog>
#include <QWidget>
#include <QDir>
#include <QStandardItemModel>
#include "playlist.h"
#include "songs_data.h"
#include "playlistform.h"
#include "widget.h"

namespace Ui {
class ListOfPlaylistTracks;
}

class ListOfPlaylistTracks : public QWidget
{
    Q_OBJECT

public:
    explicit ListOfPlaylistTracks(QWidget *parent, NavigationController *navigation_controller, DataController *data_controller);
    ~ListOfPlaylistTracks();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_songsView_clicked(const QModelIndex &index);

signals:
    void PlaylistsFormClicked();
private:
    Ui::ListOfPlaylistTracks *ui;
    QStandardItemModel *current_playlist_model;
    NavigationController *navigation_controller;
    DataController *data_controller;
};

#endif // LIST_OF_PLAYLIST_TRACKS_H
