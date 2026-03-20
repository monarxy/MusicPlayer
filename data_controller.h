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
    MediaPlayer* getPlayer() const;
    void loadSavedTracks(const QString&) ;
    void setCurrentTrack(const int);

    QStringList getPlaylistItems(const QString&) const;
    void addNewPlaylist(const QString&);
    void addTracksToPlaylist(const QString&, const QStringList&);


    void play();
    void pause();
    void stop();
    void next();
    void previous();
    void changeVolume(const int);
    void changeDuration(const int);
    void setLike();

    void likeReceiver();
    void setListOfPlaylistsItemsReceiver(const QString&);
    void setPlaylistAndCurrentTrackReceiver(const int, const QString&);
    void getPlaylistNamesReceiver();
signals:
    void LoadTracksToMainWidget(const QStringList&, const QString&);
    void LoadPlaylistsFromMemory(const QStringList&);
    void SetListOfPlaylistsItems(const QStringList&, const QString&);
    void LikeStatusSignal(const bool);
};
#endif // DATA_CONTROLLER_H
