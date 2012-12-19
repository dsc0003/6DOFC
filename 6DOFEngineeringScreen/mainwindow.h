#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "EngineeringScreen.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    Dialog *engScreen;

private:
    Ui::MainWindow *ui;
//    QAction* quitAction;
//    QAction* openAction;
//    QAction* logAction;
//    QToolBar* toolbar;
    
signals:
    
public slots:
    void log();
    void open();
    
};

#endif // MAINWINDOW_H
