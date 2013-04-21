#include "EngineeringScreen.h"
#include <QApplication>
#include <QtGui>
#include <QLabel>
#include "mainwindow.h"

#ifndef QT_NO_OPENGL
//#include "mainwidget.h"
#include "window.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Dialog w;
//    w.show();
    MainWindow window;
    window.show();
    
    return a.exec();
}

