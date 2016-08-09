#-------------------------------------------------
#
# Project created by QtCreator 2016-07-31T15:04:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DeviceManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    treedelegate.cpp \
    treeitem.cpp \
    treemodel.cpp \
    xmlprocessor.cpp \
    xmlwidget.cpp \
    cmpwidget.cpp

HEADERS  += mainwindow.h \
    treedelegate.h \
    treeitem.h \
    treemodel.h \
    xmldata.h \
    xmlprocessor.h \
    xmlwidget.h \
    cmpwidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
