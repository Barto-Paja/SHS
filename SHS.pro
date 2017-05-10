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
    album.cpp \
    myqlabel.cpp \
    item.cpp \
    dialog.cpp \
    dialogt.cpp \
    categories.cpp

HEADERS  += mainwindow.h \
    album.h \
    myqlabel.h \
    item.h \
    dialog.h \
    dialogt.h \
    categories.h

FORMS    += mainwindow.ui \
    album.ui \
    dialog.ui \
    dialogt.ui \
    categories.ui

RESOURCES += \
    zasoby.qrc

DISTFILES += \

