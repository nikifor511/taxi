#-------------------------------------------------
#
# Project created by QtCreator 2017-05-15T18:45:24
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taxi_srv
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    my_taxi_server.cpp

HEADERS  += mainwindow.h \
    my_taxi_server.h

FORMS    += mainwindow.ui
