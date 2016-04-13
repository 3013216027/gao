######################################################################
# Automatically generated by qmake (2.01a) ?? 10? 5 00:22:54 2015
######################################################################

QT	+= core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

UI_DIR=./UI

TARGET = gao
TEMPLATE = app

HEADERS += clostpair.h mainwindow.h settingnumberdialog.h settingrangedialog.h \
    inputdialog.h
SOURCES += clostpair.cpp main.cpp mainwindow.cpp settingnumberdialog.cpp settingrangedialog.cpp \
    inputdialog.cpp
FORMS	+= mainwindow.ui settingnumberdialog.ui settingrangedialog.ui \
    inputdialog.ui

#Enable std-c++11/gnu-c++11 option
QMAKE_CXX = g++-4.8
QMAKE_CXXFLAGS += -std=gnu++11
#CONFIG += debug_and_release

#DEBUG
#debug {
        #DEFINES += DEBUG
#}

#datatype for points, default float, change it to CLOST_PAIR_TYPE_INT for integer type.
DEFINES += CLOST_PAIR_TYPE_DBL

DISTFILES += \
    favicon.ico

#icon file
RC_FILE = icon.rc
