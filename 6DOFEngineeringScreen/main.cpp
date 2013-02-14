#include "EngineeringScreen.h"
#include <QApplication>
#include <QtGui>
#include <QLabel>
#include "mainwindow.h"

#ifndef QT_NO_OPENGL
#include "mainwidget.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Dialog w;
//    w.show();
    MainWindow window;
    window.show();
    
    return a.exec();



/* 2-14-13 JR launch point for cube graphic, will be meshed soon */
/*    QApplication b(argc, argv);
    b.setApplicationName("cube");
    b.setApplicationVersion("0.1");
#ifndef QT_NO_OPENGL
    MainWidget w;
    w.resize(640, 480);
    w.show();
#else
    QLabel * notifyLabel = new QLabel("OpenGL Support required");
    notifyLabel->show();
#endif
    return b.exec(); */











}
