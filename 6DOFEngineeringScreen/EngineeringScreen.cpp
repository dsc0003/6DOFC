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
    QObject::connect(&guiinterface,SIGNAL(display(int,int,int,int,int,int,int,int,int,int)),
                     this,SLOT(updateDisplay(int,int,int,int,int,int,int,int,int,int)));
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
void Dialog::updateDisplay(int x, int y, int z, int R0, int R1, int R2, int R3, int roll , int pitch, int yaw)
{
    qDebug()<<"Function:: Update Display";


    ui->TimeLineEdit->setText(QTime::currentTime().toString());
    ui->XLineEdit->setText(QString::number(x));
    ui->YLineEdit->setText(QString::number(y));
    ui->ZLineEdit->setText(QString::number(z));
    ui->R0LineEdit->setText(QString::number(R0));
    ui->R1LineEdit->setText(QString::number(R1));
    ui->R2LineEdit->setText(QString::number(R2));
    ui->R3LineEdit->setText(QString::number(R3));
    ui->RollLineEdit->setText(QString::number(roll));
    ui->PitchLineEdit->setText(QString::number(pitch));
    ui->YawLineEdit->setText(QString::number(yaw));

}

void Dialog::closeEvent(QCloseEvent *event)
{
    refinterface.stop();
    guiinterface.stop();
    refinterface.wait();
    guiinterface.wait();
    event->accept();
}
