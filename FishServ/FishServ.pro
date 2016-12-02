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
    serv.cpp

HEADERS += \
    serv.h

CONFIG += c++14

