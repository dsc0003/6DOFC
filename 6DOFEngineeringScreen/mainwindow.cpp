#include "mainwindow.h"
#include"ui_mainwindow.h"

#include <QtGui>
#include <QDebug>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    engScreen = new Dialog();
    setCentralWidget(engScreen);
    setWindowTitle("6DOFC Engineering Screen");



    QObject::connect(ui->actionQuit,SIGNAL(triggered()),this,SLOT(close()));
    QObject::connect(ui->actionLog,SIGNAL(triggered()),this,SLOT(log()));


}



void MainWindow::log()
{
    qDebug()<<"Function: log() in main window";

    QString file = QFileDialog::getSaveFileName(this, "Log","", "Text (*.txt)");
    //engScreen->fileName = QFileDialog::getSaveFileName(this, "Log","", "Text (*.txt)");

//    QFile myfile(file);
//    myfile.open(QIODevice::WriteOnly);
//    QTextStream log(&myfile);
//    log<<"test"<<endl;

      engScreen->fileName = file;
      engScreen->logFlag = TRUE;
    //qDebug() << "save file name " << engScreen->fileName;
    //qDebug() << "save file name " <<file;



}

