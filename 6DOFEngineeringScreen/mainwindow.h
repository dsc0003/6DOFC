#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "EngineeringScreen.h"
#include "guiinterface.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    Dialog *engScreen;
    GuiInterface *guiinterface;


private:
    Ui::MainWindow *ui;

    
signals:
    
public slots:
    void log();
    
};

#endif // MAINWINDOW_H
