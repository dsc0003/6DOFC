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
        GEOM2D.cpp \
        mainwindow.cpp \
        glwidget.cpp \
        imu.cpp \
        mainwidget.cpp \
        geometryengine.cpp

HEADERS  += EngineeringScreen.h \
        refinterface.h \
        guiinterface.h \
        mainwindow.h \
        glwidget.h \
        imu.h \
        mainwidget.h \
        geometryengine.h

FORMS    += \
        dialog.ui \
        mainwindow.ui

RESOURCES += \
        files.qrc \
        textures.qrc \
        shaders.qrc

OTHER_FILES += \
        vshader.glsl \
        fshader.glsl
