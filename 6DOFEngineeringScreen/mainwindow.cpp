#include "mainwindow.h"
#include"ui_mainwindow.h"
#include <QtGui>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    engScreen = new Dialog();
    setCentralWidget(engScreen);
    setWindowTitle("6DOFC Engineering Screen");

    QObject::connect(ui->actionQuit,SIGNAL(triggered()),this,SLOT(close()));
    QObject::connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(open()));
    QObject::connect(ui->actionLog,SIGNAL(triggered()),this,SLOT(log()));


}

void MainWindow::open()
{
    qDebug()<<"Function: open()";

}

void MainWindow::log()
{
    qDebug()<<"Function: log()";

}

