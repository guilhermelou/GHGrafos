#-------------------------------------------------
#
# Project created by QtCreator 2014-03-21T21:48:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GHGrafos
TEMPLATE = app
CONFIG += console
SOURCES += main.cpp\
    opmain.cpp \
    ghgrafo.cpp \
    ghedge.cpp \
    ghnode.cpp \
    viewmain.cpp \
    ghmatrizadjacencia.cpp \
    ghlistaadjacencia.cpp \
    utils.cpp \
    groupboxoption.cpp

HEADERS  += \
    viewmain.h \
    opmain.h \
    ghgrafo.h \
    ghedge.h \
    ghnode.h \
    ghmatrizadjacencia.h \
    ghlistaadjacencia.h \
    utils.h \
    groupboxoption.h

FORMS    += \
    groupboxoption.ui
