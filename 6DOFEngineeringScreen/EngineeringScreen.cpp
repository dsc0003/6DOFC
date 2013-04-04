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
#include "imudialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    ui->setupUi(this);

    logFlag = false;

    connect(ui->pauseButton,SIGNAL(clicked()),this,SLOT(pause()));

    QObject::connect(&guiinterface,SIGNAL(display(float,float,float,float,float,float,float,float,float,float)),
                     this,SLOT(updateDisplay(float,float,float,float,float,float,float,float,float,float)));

    QObject::connect(&guiinterface, SIGNAL(display(float,float,float,float,float,float,float,float,float,float)),
                     &sword,SLOT(updateCube(float,float,float,float,float,float,float,float,float,float)));

    QObject::connect(&guiinterface,SIGNAL(logSignal(float,float,float,float,float,float,float,float,float,float,QString)),
                     this,SLOT(log(float,float,float,float,float,float,float,float,float,float,QString)));


    QObject::connect(&refinterface,SIGNAL(getIMUData()),this,SLOT(getData()));

    connect(ui->pb_set,SIGNAL(clicked()),this,SLOT(getUserParameters()));




}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::pause()
{
    qDebug()<<"Pause";
    if(refinterface.isRunning())
    {
        refinterface.stop();
        guiinterface.stop();
        ui->pauseButton->setText("Start");
    }
    else if(guiinterface.isRunning())
    {
        guiinterface.stop();
        refinterface.stop();
        ui->pauseButton->setText("Start");
    }
    else
    {
        //init the imu class
    imu = new IMUDialog();
    //do the bluetooth connection from here
    while(!imu->port->isOpen()){
        imu->openUp();
            sleep(10);
        }
        refinterface.start();
        guiinterface.start();
        ui->pauseButton->setText("Pause");
    }


}
void Dialog::updateDisplay(float x, float y, float z, float R0, float R1, float R2, float R3, float roll , float pitch, float yaw)
{
    //qDebug()<<"Function:: Update Display";


    ui->TimeLineEdit->setText(QTime::currentTime().toString());
    ui->XLineEdit->setText(QString::number(x));
    ui->YLineEdit->setText(QString::number(y));
    ui->ZLineEdit->setText(QString::number(z));
    ui->R0LineEdit->setText(QString::number(R0));
    ui->R1LineEdit->setText(QString::number(R1));
    ui->R2LineEdit->setText(QString::number(R2));
    ui->R3LineEdit->setText(QString::number(R3));
//    ui->RollLineEdit->setText(QString::number(roll));
//    ui->PitchLineEdit->setText(QString::number(pitch));
//    ui->YawLineEdit->setText(QString::number(yaw));
    //MainWidget newWidget;
    //newWidget.controllerMovement(R0,R1);
    //newWidget.exec();
}


void Dialog::log(float x, float y, float z, float R0, float R1, float R2, float R3, float roll, float pitch, float yaw, QString reqNode)
{
    if(logFlag)
    {
        QFile f(fileName);
        QTextStream ts(&f);

        if (f.open(QIODevice::Append))
        {
            ts <<QTime::currentTime().toString() << ", "<<reqNode<<", " << x <<", "<<y<<", "<<z
               << ", " << roll <<", "<<pitch<<", "<<yaw
               << ", " << R0 <<", "<<R1<<", "<<R2 <<", "<<R3<< endl;

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
    refinterface.x0 = ui->le_x0->text().toFloat();
    refinterface.y0 = ui->le_y0->text().toFloat();
    refinterface.z0 = ui->le_z0->text().toFloat();
    refinterface.x1 = ui->le_x1->text().toFloat();
    refinterface.y1 = ui->le_y1->text().toFloat();
    refinterface.z1 = ui->le_z1->text().toFloat();
    refinterface.x2 = ui->le_x2->text().toFloat();
    refinterface.y2 = ui->le_y2->text().toFloat();
    refinterface.z2 = ui->le_z2->text().toFloat();
    refinterface.x3 = ui->le_x3->text().toFloat();
    refinterface.y3 = ui->le_y3->text().toFloat();
    refinterface.z3 = ui->le_z3->text().toFloat();

    //get com port info
    refinterface.radioPort.clear();
    refinterface.radioPort.append(ui->le_radioPort->text());
    refinterface.radioPort1.clear();
    refinterface.radioPort1.append(ui->le_radioPort2->text());

    //get Solver Parameters
    refinterface.NumOfIter = ui->le_numOfIter->text().toInt();
    refinterface.E = ui->le_E->text().toFloat();

    //get destination node of radio
    refinterface.destNode = ui->le_destNode->text().toInt();
}

//getData slot in eng screen
void Dialog::getData()
{
//    call the stream from here
    imu->stream();
//    set the refinterface variables from here - I believe you can do that
//    refinterface.buffer.roll = imu->rollread;
//    refinterface.buffer.pitch = imu->pitchread;
//    refinterface.buffer.yaw = imu->yawread;

    //ui->RollLineEdit->setText(QString::number(imu->rollread));
    //ui->PitchLineEdit->setText(QString::number(imu->pitchread));
    //ui->YawLineEdit->setText(QString::number(imu->yawread));
    qDebug() << "yaw" << imu->yawread;
    qDebug() << "pitch" << imu->pitchread;
    qDebug() << "roll" << imu->rollread;
    //or take the roll, pitch, yaw straight from here and not put it in the buffer at all since the solver doesn't need it,
    // only the engineering screen and the openGL widget needs it
    //it just needs to be called in the refinterface
}
