QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    list_of_playlist_tracks.cpp \
    main.cpp \
    music_player.cpp \
    playlist.cpp \
    playlistform.cpp \
    songs_data.cpp \
    widget.cpp

HEADERS += \
    list_of_playlist_tracks.h \
    media_data.h \
    multimedia.h \
    music_player.h \
    playlist.h \
    playlistform.h \
    songs_data.h \
    video_data.h \
    video_player.h \
    widget.h

FORMS += \
    list_of_playlist_tracks.ui \
    playlistform.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
