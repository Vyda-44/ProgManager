#-------------------------------------------------
#
# Project created by QtCreator 2014-03-03T11:27:56
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProgManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    language.cpp \
    form.cpp

HEADERS  += mainwindow.h \
    database.h \
    language.h \
    form.h

FORMS    += mainwindow.ui \
    language.ui \
    form.ui
