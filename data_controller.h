#ifndef DATA_CONTROLLER_H
#define DATA_CONTROLLER_H
#include "music_player.h"


class DataController : public QObject {
    Q_OBJECT
    MediaPlayer *music_player;
public:
    DataController(QObject *parent = nullptr, MediaPlayer* _music_player=nullptr);
    ~DataController();

    void setMusicPlayer(QStringList list_of_tracks);
    MediaPlayer* getPlayer();
    void loadSavedTracks();
signals:
    void LoadTracksFromMemory(QStringList list_of_tracks, QString name_of_album);
};
#endif // DATA_CONTROLLER_H
