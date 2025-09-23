#ifndef PLAYLISTFORM_H
#define PLAYLISTFORM_H

#include <QWidget>
#include <QInputDialog>
#include <QStandardItemModel>
#include "media_data.h"
#include "playlist.h"
#include "list_of_playlist_tracks.h"
#include <vector>

namespace Ui {
class PlaylistForm;
}

class PlaylistForm : public QWidget
{
    Q_OBJECT

public:
    explicit PlaylistForm(QWidget *parent);
    QWidget* getParent();
    ~PlaylistForm();

private:
    Ui::PlaylistForm *ui;
    QStandardItemModel *playlists_model;
    std::vector<Playlist*> list_of_playlists;
    QWidget *list_of_playlists_tracks_form;
    QWidget *parent_form;

signals:
    void HomeClicked();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_playlistsView_clicked(const QModelIndex &index);
    void move_to_playlists_form();

};

#endif // PLAYLISTFORM_H
