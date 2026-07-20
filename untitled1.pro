QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appcontroller.cpp \
    cover_extractor.cpp \
    data.cpp \
    data_controller.cpp \
    default_playlist.cpp \
    favourite_playlist.cpp \
    list_of_playlist_tracks.cpp \
    list_of_radioplaylist_items.cpp \
    main.cpp \
    media_data.cpp \
    media_loader.cpp \
    multimedia.cpp \
    music_player.cpp \
    navigation_controller.cpp \
    playlist.cpp \
    playlistform.cpp \
    radio.cpp \
    radio_controller.cpp \
    radio_data.cpp \
    radio_default_playlist.cpp \
    radio_favourite_playlist.cpp \
    radio_loader.cpp \
    radio_playlist.cpp \
    radioform.cpp \
    time_formatter.cpp \
    video_data.cpp \
    video_player.cpp \
    widget.cpp

HEADERS += \
    IContinuousPlayer.h \
    IDefaultPlaylist.h \
    IDeleteItemsInPlaylistManagement.h \
    IDurationChangeable.h \
    IDurationController.h \
    IFavouritePlaylist.h \
    IFavouritePlaylistController.h \
    IFewPlayersController.h \
    IGetPlayerController.h \
    IGetRadioPlayerController.h \
    ILikeController.h \
    ILikeable.h \
    IMovementPlaylistManagement.h \
    IMultimediaGetManagement.h \
    IPlayer.h \
    IPlayerController.h \
    IPlayerSettable.h \
    IPlaylistController.h \
    IPlaylistItemsManagement.h \
    IPlaylistManagement.h \
    IPlaylistNameManagement.h \
    IQPlaylistManagement.h \
    IRadioPlaylistController.h \
    IRadiostationController.h \
    IRadiostationsManagement.h \
    ISerializable.h \
    IVideoManagementController.h \
    IVolumeChangeable.h \
    IVolumeController.h \
    appcontroller.h \
    cover_extractor.h \
    data.h \
    data_controller.h \
    default_playlist.h \
    favourite_playlist.h \
    list_of_playlist_tracks.h \
    list_of_radioplaylist_items.h \
    media_data.h \
    media_loader.h \
    multimedia.h \
    music_player.h \
    navigation_controller.h \
    playlist.h \
    playlistform.h \
    radio.h \
    radio_controller.h \
    radio_data.h \
    radio_default_playlist.h \
    radio_favourite_playlist.h \
    radio_loader.h \
    radio_playlist.h \
    radioform.h \
    sound_effect.h \
    time_formatter.h \
    video_data.h \
    video_player.h \
    widget.h

FORMS += \
    list_of_playlist_tracks.ui \
    list_of_radioplaylist_items.ui \
    playlistform.ui \
    radioform.ui \
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

RESOURCES += \
    resources.qrc

unix|win32: LIBS += -L$$PWD/../../../../taglib/build/lib/ -llibtag.dll

INCLUDEPATH += $$PWD/../../../../taglib/build/include
DEPENDPATH += $$PWD/../../../../taglib/build/include
