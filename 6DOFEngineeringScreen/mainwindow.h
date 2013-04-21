#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "EngineeringScreen.h"
#include "guiinterface.h"
#include "imudialog.h"

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
    IMUDialog *imuScreen;


private:
    Ui::MainWindow *ui;

    
signals:
    
public slots:
    void log();
    void imuSetup();
    
};

#endif // MAINWINDOW_H
