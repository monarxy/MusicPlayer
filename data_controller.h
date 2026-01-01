#ifndef DATA_CONTROLLER_H
#define DATA_CONTROLLER_H
#include "music_player.h"


class DataController : public QObject {
    Q_OBJECT
    MediaPlayer *music_player;
public:
    DataController(QObject *parent = nullptr, MediaPlayer* _music_player=nullptr);
    ~DataController();

    void setMusicPlayer(const QStringList&);
    MediaPlayer* getPlayer();
    void loadSavedTracks(const QString&);
    void setCurrentTrack(const int&);
    void getPlaylistNames();

    QStringList getPlaylistItems(const QString&);
    void addNewPlaylist(const QString&);
    void setListOfPlaylistsItems(const QString&);

    void play();
signals:
    void LoadTracksFromMemory(const QStringList&, const QString&);
    void LoadPlaylistsFromMemory(const QStringList&);
    void SetListOfPlaylistsItems(const QStringList&, const QString&);
};
#endif // DATA_CONTROLLER_H
