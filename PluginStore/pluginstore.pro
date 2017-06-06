#-------------------------------------------------
#
# Project created by QtCreator 2017-05-09T17:28:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
 QT += webchannel
QT += webenginewidgets
QT += sql
TEMPLATE     = lib
CONFIG	    += dll
TARGET = pluginstore
TRANSLATIONS+=cn.ts

SOURCES += pluginstoremodule.c\
        webpluginevent.cpp \
    pluginstore.cpp\
    plugindb.cpp

HEADERS  += pluginstore.h \
    webpluginevent.h\
    plugindb.h\
    zip_file.hpp

FORMS    += forms\pluginstore.ui

RESOURCES += forms\PluginInfo.sql\
    forms\resource.qrc
include(qtwinmigrate/src/qtwinmigrate.pri)
