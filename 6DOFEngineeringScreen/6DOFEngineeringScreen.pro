#-------------------------------------------------
#
# Project created by QtCreator 2012-12-11T10:15:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 6DOFEngineeringScreen
TEMPLATE = app


SOURCES += main.cpp\
        EngineeringScreen.cpp \
    refinterface.cpp \
    NLLS2D.cpp

HEADERS  += EngineeringScreen.h \
    refinterface.h \
    guiinterface.h

FORMS    += \
    dialog.ui

RESOURCES += \
    files.qrc
