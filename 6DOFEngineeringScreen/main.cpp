#include "EngineeringScreen.h"
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Dialog w;
//    w.show();
    MainWindow window;
    window.show();
    
    return a.exec();
}
