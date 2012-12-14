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
    msg.clear();
    stopped = false;
}

void RefInterface::run()
{

    while(!stopped)
    {
        qDebug("Reference thread run");
        mutex.lock();

        sleep(2);

        buffer.x = qrand()%10;
        buffer.y = qrand()%10;
        buffer.z = qrand()%10;
        buffer.R0 = qrand()%10;
        buffer.R1 = qrand()%10;
        buffer.R2 = qrand()%10;
        buffer.R3 = qrand()%10;
        buffer.roll = qrand()%10;
        buffer.pitch = qrand()%10;
        buffer.yaw = qrand()%10;
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
    msg.clear();
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
       emit display(dataGathered.x, dataGathered.y, dataGathered.z, dataGathered.R0, dataGathered.R1, dataGathered.R2,
                    dataGathered.R3,dataGathered.roll, dataGathered.pitch,dataGathered.yaw);
       qDebug()<<"Gui Interface: "<<dataGathered.x <<" "<<dataGathered.y<<" "<<dataGathered.z<<" "<<dataGathered.R0<<"\n";
       }


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
