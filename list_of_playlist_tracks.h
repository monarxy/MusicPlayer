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
    ListOfPlaylistTracks();
    ~ListOfPlaylistTracks();
    void setItems(const QStringList&, const QString&);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_songsView_clicked(const QModelIndex &index);

signals:
    void FormClicked(const QString&);
    void ItemsAddedToPlaylist(const QString&, const QStringList&);
    void ItemsListClicked(const int, const QString&);
    void MuteRadioPlayer();
private:
    Ui::ListOfPlaylistTracks *ui;
    QStandardItemModel *current_playlist_model;
};

#endif // LIST_OF_PLAYLIST_TRACKS_H
