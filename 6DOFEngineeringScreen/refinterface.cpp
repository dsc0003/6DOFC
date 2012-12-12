#include "refinterface.h"
#include "guiinterface.h"
#include <QtGui>
#include <QApplication>
#include <QThread>
#include <QMutex>
#include <QQueue>
#include <stdio.h>
#include <stdlib.h>
#include <QtCore>
#include <QTime>
#include <QtDebug>

QMutex mutex;
QQueue<struct rangeInfo> msg;
rangeInfo buffer;

RefInterface::RefInterface()
{
    stopped = false;
}

void RefInterface::run()
{

    while(!stopped)
    {
        qDebug("Reference thread run");
        mutex.lock();

        sleep(2);

        buffer.x = qrand();
        buffer.y = qrand();
        buffer.z = qrand();
        buffer.R0 = qrand();
        buffer.R1 = qrand();
        buffer.R2 = qrand();
        buffer.R3 = qrand();
        buffer.roll = qrand();
        buffer.pitch = qrand();
        buffer.yaw = qrand();
        qDebug()<<"Ref Interface: "<<buffer.x<<" "<<buffer.y<<" "<<buffer.z<<" "<<buffer.R0<<endl;
        msg.append(buffer);

        mutex.unlock();
    }

        stopped = false;
}

void RefInterface::stop()
{
    qDebug("Reference thread stopped");
    stopped = true;
}


GuiInterface::GuiInterface()
{
    stoppedConsumer = false;
}

void GuiInterface::run()
{
    while(!stoppedConsumer)
    {

       mutex.lock();

       sleep(2);
       qDebug()<<"Gui thread run" <<endl;

       if(!msg.isEmpty())
       {

       dataGathered.x = msg.first().x;
       dataGathered.y = msg.first().y;
       dataGathered.z = msg.first().z;
       dataGathered.R0 = msg.first().R0;
       dataGathered.R1 = msg.first().R1;
       dataGathered.R2 = msg.first().R2;
       dataGathered.R3 = msg.first().R3;
       dataGathered.roll = msg.first().roll;
       dataGathered.pitch = msg.first().pitch;
       dataGathered.yaw = msg.first().yaw;

       msg.removeFirst();
       qDebug()<<"Gui Interface: "<<dataGathered.x <<" "<<dataGathered.y<<" "<<dataGathered.z<<" "<<dataGathered.R0<<"\n";
       }

       emit display();

        mutex.unlock();
    }
    stoppedConsumer = false;

     qDebug()<<"\n";
}

void GuiInterface::stop()
{
    qDebug("GuiInterface thread stopped");
    stoppedConsumer = true;
}
