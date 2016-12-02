#-------------------------------------------------
#
# Project created by QtCreator 2016-09-18T19:00:33
#
#-------------------------------------------------

QT       += websockets
QT += widgets

TARGET = client
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    client.cpp \
    logi.cpp \
    login.cpp \
    pudel.cpp

HEADERS += \
    client.h \
    logi.h \
    login.h \
    pudel.h

CONFIG += c++14

FORMS += \
    logi.ui \
    login.ui \
    pudel.ui

RESOURCES += \
    dogs.qrc
