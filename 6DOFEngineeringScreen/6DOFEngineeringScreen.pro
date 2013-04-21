#-------------------------------------------------
#
# Project created by QtCreator 2012-12-11T10:15:48
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 6DOFEngineeringScreen
TEMPLATE = app

win32 {
LIBS += -lws2_32 #2-18-13 JR added winsock2 library to project
}
SOURCES += main.cpp\
        EngineeringScreen.cpp \
        refinterface.cpp \
        mainwindow.cpp \
    rcmIf.c \
    rcm.c \
    solver.cpp \
    imudialog.cpp \
    window.cpp \
    glwidget.cpp

HEADERS  += EngineeringScreen.h \
        refinterface.h \
        guiinterface.h \
        mainwindow.h \
    rcmIf.h \
    rcm.h \
    hostInterfaceRCM.h \
    hostInterfaceCommon.h \
    solver.h \
    imudialog.h \
    window.h \
    glwidget.h

FORMS    += \
        dialog.ui \
        mainwindow.ui \
    imudialog.ui

RESOURCES += \
        files.qrc \
        textures.qrc \
        shaders.qrc

OTHER_FILES += \
        vshader.glsl \
        fshader.glsl \
    ConfigReadMe.txt

include(3rdparty/qextserialport/src/qextserialport.pri) #serial port com library
