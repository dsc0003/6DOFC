#include "imu.h"
#include "qextserialport.h"
#include <QtDebug>
#include <QObject>
#include <QtGui>
#include <QApplication>
#include <QThread>
#include <QMutex>
#include <QQueue>
#include <stdio.h>
#include <stdlib.h>
#include <QtCore>

IMU::IMU()
{
#ifdef Q_OS_UNIX
    port = new QextSerialPort(QLatin1String("/dev/tty.FireFly-8842-SPP"), QextSerialPort::Polling);
#else
    port = new QextSerialPort(QLatin1String("COM1"), QextSerialPort::Polling);
#endif /*Q_OS_UNIX*/
   //this->port = new QextSerialPort(portName, QextSerialPort::EventDriven);
    port->setBaudRate(BAUD57600);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_2);

    if (port->open(QIODevice::ReadWrite) == true) {
        //connect(port,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
        //connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        //connect(port, SIGNAL(dsrChanged(bool)), this, SLOT(onDsrChanged(bool)));
        if (!(port->lineStatus() & LS_DSR))
            qDebug() << "warning: device is not turned on";
        qDebug() << "listening for data on" << port->portName();
    }
    else {
        qDebug() << "device failed to open:" << port->errorString();
    }
}

void IMU::onReadyRead()
{
    QByteArray bytes;
    int a = port->bytesAvailable();
    bytes.resize(a);
    port->read(bytes.data(), bytes.size());
    qDebug() << "bytes read:" << bytes.size();
    qDebug() << "bytes:" << bytes;
}

void IMU::onDsrChanged(bool status)
{
    if (status)
        qDebug() << "device was turned on";
    else
        qDebug() << "device was turned off";
}
