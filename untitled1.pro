QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appcontroller.cpp \
    data_controller.cpp \
    editorform.cpp \
    list_of_playlist_tracks.cpp \
    main.cpp \
    music_player.cpp \
    navigation_controller.cpp \
    playlist.cpp \
    playlistform.cpp \
    songs_data.cpp \
    tracks_loader.cpp \
    widget.cpp

HEADERS += \
    appcontroller.h \
    chorus_effect.h \
    data_controller.h \
    editor.h \
    editorform.h \
    list_of_playlist_tracks.h \
    media_data.h \
    media_loader.h \
    multimedia.h \
    music_player.h \
    navigation_controller.h \
    playlist.h \
    playlistform.h \
    songs_data.h \
    sound_effect.h \
    tracks_loader.h \
    video_data.h \
    video_player.h \
    widget.h

FORMS += \
    editorform.ui \
    list_of_playlist_tracks.ui \
    playlistform.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix|win32: LIBS += -L$$PWD/../bass/c/x64/ -lbass

INCLUDEPATH += $$PWD/../bass/c/include
DEPENDPATH += $$PWD/../bass/c/include


unix|win32: LIBS += -L$$PWD/../ffmpeg/lib/ -lavcodec

INCLUDEPATH += $$PWD/../ffmpeg/include
DEPENDPATH += $$PWD/../ffmpeg/include

unix|win32: LIBS += -L$$PWD/../ffmpeg/lib/ -lavdevice

INCLUDEPATH += $$PWD/../ffmpeg/include
DEPENDPATH += $$PWD/../ffmpeg/include

unix|win32: LIBS += -L$$PWD/../ffmpeg/lib/ -lavfilter

INCLUDEPATH += $$PWD/../ffmpeg/include
DEPENDPATH += $$PWD/../ffmpeg/include

unix|win32: LIBS += -L$$PWD/../ffmpeg/lib/ -lavformat

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''

unix|win32: LIBS += -L$$PWD/../ffmpeg/lib/ -lavutil

INCLUDEPATH += $$PWD/../ffmpeg/include
DEPENDPATH += $$PWD/../ffmpeg/include

unix|win32: LIBS += -L$$PWD/../ffmpeg/lib/ -lswresample

INCLUDEPATH += $$PWD/../ffmpeg/include
DEPENDPATH += $$PWD/../ffmpeg/include

unix|win32: LIBS += -L$$PWD/../ffmpeg/lib/ -lswscale

INCLUDEPATH += $$PWD/../ffmpeg/include
DEPENDPATH += $$PWD/../ffmpeg/include
