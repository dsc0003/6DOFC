#-------------------------------------------------
#
# Project created by QtCreator 2012-12-11T10:15:48
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 6DOFEngineeringScreen
TEMPLATE = app


SOURCES += main.cpp\
        EngineeringScreen.cpp \
    refinterface.cpp \
    NLLS2D.cpp \
    GEOM2D.cpp \
    mainwindow.cpp \
    glwidget.cpp

HEADERS  += EngineeringScreen.h \
    refinterface.h \
    guiinterface.h \
    mainwindow.h \
    glwidget.h

FORMS    += \
    dialog.ui \
    mainwindow.ui

RESOURCES += \
    files.qrc
