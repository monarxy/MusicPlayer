#include "music_player.h"

MusicPlayer::MusicPlayer(QObject *parent, MediaLoader* _serializer) : MediaPlayer(parent, _serializer){}

void MusicPlayer::setTracksToPlaylistByName(const QString& album_name, const QStringList& list_of_tracks){
    auto it = list_of_playlists.find(album_name);
    Playlist* playlist = (it != list_of_playlists.end()) ? it->second : nullptr;
    for (const QString& item : list_of_tracks)
        playlist->setListOfItems(new SongData(item, false));

}

void MusicPlayer::setTracksToCurrentPlaylist(const QStringList& list_of_tracks){
    for (const QString& item : list_of_tracks)
        playlist->setListOfItems(new SongData(item, false));

}


MusicPlayer::~MusicPlayer()
{
    // save();
    // for (const auto& pair : list_of_playlists)
    //     delete pair.second;
    // delete m_player;

}

