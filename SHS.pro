#-------------------------------------------------
#
# Project created by QtCreator 2016-12-08T19:13:12
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SHS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    kategorie.cpp \
    album.cpp \
    myqlabel.cpp \
    item.cpp \
    dialog.cpp \
    dialogt.cpp

HEADERS  += mainwindow.h \
    kategorie.h \
    album.h \
    myqlabel.h \
    item.h \
    dialog.h \
    dialogt.h

FORMS    += mainwindow.ui \
    kategorie.ui \
    album.ui \
    dialog.ui \
    dialogt.ui

RESOURCES += \
    zasoby.qrc

DISTFILES += \
    txt/zle_odpowiedzi.txt
