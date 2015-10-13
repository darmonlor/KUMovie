#-------------------------------------------------
#
# Project created by QtCreator 2015-10-06T20:16:23
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KUMovie
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    databasecontrol.cpp \
    addmovie.cpp

HEADERS  += mainwindow.h \
    databasecontrol.h \
    addmovie.h

FORMS    += mainwindow.ui \
    addmovie.ui

DISTFILES +=

RESOURCES += \
    database.qrc
