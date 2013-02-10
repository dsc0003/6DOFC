#include "refinterface.h"
#include "guiinterface.h"
#include "GEOM2D.cpp"
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
    seedx = 0;
    seedy = 1;
    x0 = -500;
    y0 = 0;
    x1= 500;
    y1 = 0;
    stopped = false;
}

void RefInterface::run()
{

    while(!stopped)
    {
        qDebug("Reference thread run");
        mutex.lock();

        sleep(2);

        r0 = qrand()%2000;
        r1 = qrand()%2000;

        find_intersection_points(x0,y0,x1,y1,r0,r1,seedx,seedy,&px,&py);


        buffer.R0 = r0;
        buffer.R1 = r1;
        buffer.x = px;
        buffer.y = py;
        buffer.R2 = 0;
        buffer.R3 = 0;
        buffer.roll = qrand()%360;
        buffer.pitch = qrand()%360;
        buffer.yaw = qrand()%360;

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
    //engScreen = new Dialog();
    stoppedConsumer = false;
}

void GuiInterface::run()
{
    while(!stoppedConsumer)
    {

       mutex.lock();

       //sleep(2);
       //qDebug()<<"Gui thread run" <<endl;

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

                   emit logSignal(dataGathered.x, dataGathered.y, dataGathered.z, dataGathered.R0, dataGathered.R1, dataGathered.R2,
                                  dataGathered.R3,dataGathered.roll, dataGathered.pitch,dataGathered.yaw);


           }

          mutex.unlock();
    }
    stoppedConsumer = false;

     //qDebug()<<"\n";
}

void GuiInterface::stop()
{
    qDebug("GuiInterface thread stopped");
    stoppedConsumer = true;
}


