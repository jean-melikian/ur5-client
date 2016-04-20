#-------------------------------------------------
#
# Project created by QtCreator 2015-02-04T09:29:52
#
#-------------------------------------------------

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ur5-client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connectdlg.cpp \
    fontclass.cpp \
    bzview.cpp \
    previewdlg.cpp

HEADERS  += \
    mainwindow.h \
    connectdlg.h \
    fontclass.h \
    bzview.h \
    previewdlg.h

FORMS    += mainwindow.ui \
    connectdlg.ui \
    previewdlg.ui

DISTFILES +=

RESOURCES += \
    mainwindow.qrc
