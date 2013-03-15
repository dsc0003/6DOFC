#include "EngineeringScreen.h"
#include "ui_dialog.h"
//#include "mainwidget.h"
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

    logFlag = false;
        //ui->mainwidget->setMouseTracking(true);
        //ui->mainwidget->activateWindow();
    //ui->mainwidget->resizeGL(640,480);
        //ui->mainwidget->grabMouse();
    //ui->mainwidget->show();
        //ui->mainwidget->repaint();

    connect(ui->pauseButton,SIGNAL(clicked()),this,SLOT(pause()));

    QObject::connect(&guiinterface,SIGNAL(display(float,float,float,float,float,float,float,float,float,float)),
                     this,SLOT(updateDisplay(float,float,float,float,float,float,float,float,float,float)));

    QObject::connect(&guiinterface,SIGNAL(logSignal(float,float,float,float,float,float,float,float,float,float)),
                     this,SLOT(log(float,float,float,float,float,float,float,float,float,float)));

    connect(ui->pb_set,SIGNAL(clicked()),this,SLOT(getUserParameters()));

   // QObject::connect(&guiinterface, SIGNAL(logSignal(int,int,int,int,int,int,int,int,int,int)),
     //                this, SLOT(controllerMovementEvent(int,int,int)));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::pause()
{
    qDebug()<<"Pause";
    if(refinterface.isRunning() || guiinterface.isRunning())
    {

        refinterface.stop();
        guiinterface.stop();

//        refinterface.wait();
//        guiinterface.wait();
        ui->pauseButton->setText("Start");
    }

    else
    {
        refinterface.start();
        guiinterface.start();
        ui->pauseButton->setText("Pause");
    }


}
void Dialog::updateDisplay(float x, float y, float z, float R0, float R1, float R2, float R3, float roll , float pitch, float yaw)
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
    //MainWidget newWidget;
    //newWidget.controllerMovement(R0,R1);
    //newWidget.exec();
}


void Dialog::log(float x, float y, float z, float R0, float R1, float R2, float R3, float roll, float pitch, float yaw)
{
    if(logFlag)
    {
        QFile f(fileName);
        QTextStream ts(&f);

        if (f.open(QIODevice::Append))
        {
            ts <<"Time: "<< QTime::currentTime().toString() << "       x: " << x <<"       y: "<<y<<"       z: "<<z
               << "       roll: " << roll <<"       pitch: "<<pitch<<"       yaw: "<<yaw
               << "       R0: " << R0 <<"       R1: "<<R1<<"       R2: "<<R2 <<"       R3: "<<R3<< endl;

        }
    }
}

void Dialog::closeEvent(QCloseEvent *event)
{
    refinterface.stop();
    guiinterface.stop();
    refinterface.wait();
    guiinterface.wait();
    event->accept();
}

void Dialog::getUserParameters()
{

    //get Reference Positions
    refinterface.x0 = ui->le_ref1->text().toFloat();
    refinterface.y0 = ui->le_ref2->text().toFloat();
    refinterface.x1 = ui->le_ref3->text().toFloat();
    refinterface.y1 = ui->le_ref4->text().toFloat();

    //get com port info
    refinterface.radioPort.clear();
    refinterface.radioPort.append(ui->le_radioPort->text().toInt());
    refinterface.usbInterfacePort.clear();
    refinterface.usbInterfacePort.append(ui->le_usbPort->text().toInt());

    //get Solver Parameters
    refinterface.NumOfIter = ui->le_numOfIter->text().toInt();
    refinterface.E = ui->le_E->text().toFloat();

    //get destination node of radio
    refinterface.destNode = ui->le_destNode->text().toInt();


}
