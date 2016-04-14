#-------------------------------------------------
#
# Project created by QtCreator 2016-04-09T10:22:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Playlist
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Playlist_Container.cpp \
    Playlist.cpp \
    Song_Container.cpp \
    Song.cpp \
    Text_Parser.cpp \
    Top8_Playlist_Container.cpp \
    Try.cpp

HEADERS  += mainwindow.h \
    Playlist_Container.h \
    Playlist.h \
    Song_Container.h \
    Song.h \
    Text_Parser.h \
    Top8_Playlist_Container.h \
    Try.h

FORMS    += mainwindow.ui
