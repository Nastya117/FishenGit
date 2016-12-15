#-------------------------------------------------
#
# Project created by QtCreator 2016-09-18T19:00:33
#
#-------------------------------------------------

QT       += websockets
QT += widgets

TARGET = FishCli

TEMPLATE = app

SOURCES += \
    main.cpp \
    client.cpp \
    logi.cpp \
    login.cpp \
    pudel.cpp \
    mainwindow.cpp \
    reddak.cpp

HEADERS += \
    client.h \
    logi.h \
    login.h \
    pudel.h \
    mainwindow.h \
    reddak.h

CONFIG += c++14

FORMS += \
    logi.ui \
    login.ui \
    pudel.ui \
    mainwindow.ui \
    reddak.ui

RESOURCES += \
    dogs.qrc
