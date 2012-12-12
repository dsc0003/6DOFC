#include "EngineeringScreen.h"
#include "ui_dialog.h"
#include <QTime>
#include <QObject>
#include <QtGui>
#include <QApplication>
#include <QThread>
#include <QMutex>
#include <QQueue>
#include <stdio.h>
#include <stdlib.h>
#include <QtCore>
#include <QtDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    ui->setupUi(this);


    connect(ui->pauseButton,SIGNAL(clicked()),this,SLOT(pause()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::pause()
{

    if(refinterface.isRunning() || guiinterface.isRunning())
    {
        refinterface.stop();
        guiinterface.stop();
        ui->pauseButton->setText("Start");
    }
    else
    {
        refinterface.start();
        guiinterface.start();
        ui->pauseButton->setText("Pause");
    }


}
void Dialog::updateDisplay()
{
    qDebug()<<"Function:: Update Display";
}

void Dialog::closeEvent(QCloseEvent *event)
{
    refinterface.stop();
    guiinterface.stop();
    refinterface.wait();
    guiinterface.wait();
    event->accept();
}
