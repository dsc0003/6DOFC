#include "refinterface.h"
#include "guiinterface.h"
#include "3rdparty/qextserialport/src/qextserialport.h"
#include "rcmIf.c"


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
#include <QFile>

#define ANTENNAMODE_A 0
#define ANTENNAMODE_B 1

QMutex mutex;
QQueue<struct rangeInfo> msg;


RefInterface::RefInterface()
{
    solver = new Solver();

    msg.clear();

    radioNum = 0;
    antennaNum = 0;
    count = 1;
    errorCountR0 = 0;
    errorCountR1 = 0;
    errorCountR2 = 0;
    errorCountR3 = 0;
    thresholdErrorCountR0 = 0;
    thresholdErrorCountR1 = 0;
    thresholdErrorCountR2 = 0;
    thresholdErrorCountR3 = 0;


    readConfigFile();

    //initialize radio (USB and dest address)
    if (rcmIfInit(rcmIfUsb, radioPort.data()) != OK)
    {
        qDebug()<<"Initialization failed";
        exit(0);
    }

    radioCom = radioFd;
    qDebug()<<"radioCom"<<radioCom;
    if (rcmIfInit(rcmIfUsb, radioPort1.data()) != OK)
    {
        qDebug()<<"Initialization failed";
        exit(0);
    }
    radioCom1 = radioFd;
    qDebug()<<"radioCom1"<<radioCom1;
    stopped = false;
}

void RefInterface::run()
{

    while(!stopped)
    {
        //qDebug("Reference thread run");
        mutex.lock();

        range();

        emit getIMUData();


        if(!msg.isEmpty())
        {
           msg.clear();
        }


        switch(count)
        {
        case 1: solver->find_intersection_points_nlls3d(x0 ,y0, z0, r0, x1, y1, z1, r1, x2
                                                        , y2, z2, r2, 0.0, 0.0, 0.5, px, py, pz );
                count = count + 1;
                break;
        case 2: solver->find_intersection_points_nlls3d(x1 ,y1, z1, r1, x2, y2, z2, r2, x3
                                                       , y3, z3, r3, 0.0, 0.0, 0.5, px, py, pz );
               count = count + 1;
               break;
        case 3:  solver->find_intersection_points_nlls3d(x2 ,y2, z2, r2, x3, y3, z3, r3, x0
                                                         , y0, z0, r0, 0.0, 0.0, 0.5, px, py, pz );
                 count = count + 1;
                 break;
        case 4:  solver->find_intersection_points_nlls3d(x3 ,y3, z3, r3, x3, y0, z0, r0, x1
                                                         , y1, z1, r1, 0.0, 0.0, 0.5, px, py, pz );
                 count = 1;
                 break;
         default:
            break;
        }


        //Here I set the buffer struct to the position returned from solver
        oldx  = px;
        oldy = py;
        oldz = pz;
        buffer.x = px;
        buffer.y = py;
        buffer.z = pz;

        //append the buffer to the queue
        msg.append(buffer);

        //unlock the mutex so the consumer can have access to buffer
        mutex.unlock();
        //set stopped to true, so consumer has a turn
        stopped = false;
    }
}

void RefInterface::range()
{
    if(radioNum == 0)
    {
        radioFd = radioCom;

        if(antennaNum == 0)
        {
            buffer.reqNode = "101A";
            //range to the controller using radio A
            if (rcmRangeTo(destNode, ANTENNAMODE_A, 0, NULL,
                    &RangeInfo, &dataInfo, &scanInfo, &fullScanInfo) == 0)
            {

                //This gets the precision range measurement
                if (RangeInfo.rangeMeasurementType & RCM_RANGE_TYPE_PRECISION)
                {
                    ////qDebug()<<"Precision range: "<< RangeInfo.precisionRangeMm;
                    r0 = RangeInfo.precisionRangeMm;
                }

                //if the status comes back as 0, the radio ranged correctly
                if (RangeInfo.rangeStatus == 0)
                {

                    // add range to buffer structure
                    r0 = r0/1000;
                    buffer.R0 = r0;
                    buffer.mError = RangeInfo.precisionRangeErrEst;
                    buffer.status = RangeInfo.rangeStatus;
                    ////qDebug()<<"Range Successful";
                }
                else if(RangeInfo.precisionRangeErrEst > 60)
                {
                    if(!msg.isEmpty())
                    {
                        buffer.mError = RangeInfo.precisionRangeErrEst;
                        buffer.status = RangeInfo.rangeStatus;
                        thresholdErrorCountR0++;
                        emit sendThresholdCount(thresholdErrorCountR0, thresholdErrorCountR1, thresholdErrorCountR2, thresholdErrorCountR3);
                        emit display(buffer.x, buffer.y, buffer.z, RangeInfo.precisionRangeMm, buffer.R1, buffer.R2,
                                     buffer.R3,buffer.roll, buffer.pitch,buffer.yaw, buffer.mError,buffer.status);

                        r0 = msg.at(0).R0;
                        buffer.R0 = r0;
                    }
                }
                else
                {
                    r0 = msg.at(0).R0;
                    buffer.R0 = r0;
                    buffer.mError = RangeInfo.precisionRangeErrEst;
                    buffer.status = RangeInfo.rangeStatus;
                    errorCountR0++;
                    emit sendErrorCount(errorCountR0, errorCountR1, errorCountR2, errorCountR3);
                }
            } //end if
            antennaNum = 1;
            return;
        }
        if(antennaNum == 1)
        {
            buffer.reqNode = "101B";
            //range to controller using radio B
            if (rcmRangeTo(destNode, ANTENNAMODE_B, 0, NULL,
                    &RangeInfo, &dataInfo, &scanInfo, &fullScanInfo) == 0)
            {

                // Get precision range measurement from msg received
                if (RangeInfo.rangeMeasurementType & RCM_RANGE_TYPE_PRECISION)
                {
                    ////qDebug()<<"Precision range: "<< RangeInfo.precisionRangeMm;
                    r1 = RangeInfo.precisionRangeMm;
                }

                 //if the status is 0, range was successful
                if (RangeInfo.rangeStatus == 0)
                {
                    ////qDebug()<<"Range Successful";
                    //add range to buffer struct
                    r1 = r1/1000;
                    buffer.R1 = r1;
                    buffer.mError = RangeInfo.precisionRangeErrEst;
                    buffer.status = RangeInfo.rangeStatus;
                }
                else if(RangeInfo.precisionRangeErrEst >60)
                {
                    if(!msg.isEmpty())
                    {
                        buffer.mError = RangeInfo.precisionRangeErrEst;
                        buffer.status = RangeInfo.rangeStatus;
                        thresholdErrorCountR1++;
                        emit sendThresholdCount(thresholdErrorCountR0, thresholdErrorCountR1, thresholdErrorCountR2, thresholdErrorCountR3);
                        emit display(buffer.x, buffer.y, buffer.z, buffer.R0, RangeInfo.precisionRangeMm, buffer.R2,
                                     buffer.R3,buffer.roll, buffer.pitch,buffer.yaw, buffer.mError,buffer.status);
                        r1 = msg.at(0).R1;
                        buffer.R1 = r1;
                    }
                }
                else
                {
                    r1 = msg.at(0).R1;
                    buffer.R1 = r1;
                    buffer.mError = RangeInfo.precisionRangeErrEst;
                    buffer.status = RangeInfo.rangeStatus;
                    errorCountR1++;
                    emit sendErrorCount(errorCountR0, errorCountR1, errorCountR2, errorCountR3);
                }
            } //end if
            antennaNum = 0;
            radioNum = 1;
            return;
        }
    }
    if(radioNum == 1)
    {
        radioFd = radioCom1;
        if(antennaNum == 0)
        {
            buffer.reqNode = "102A";
            if (rcmRangeTo(destNode, ANTENNAMODE_A, 0, NULL,
                    &RangeInfo, &dataInfo, &scanInfo, &fullScanInfo) == 0)
            {

                //This gets the precision range measurement
                if (RangeInfo.rangeMeasurementType & RCM_RANGE_TYPE_PRECISION)
                {
                    ////qDebug()<<"Precision range: "<< RangeInfo.precisionRangeMm;
                    r2 = RangeInfo.precisionRangeMm;
                }

                //if the status comes back as 0, the radio ranged correctly
                if (RangeInfo.rangeStatus == 0)
                {
                    ////qDebug()<<"Range Successful";
                    // add range to buffer structure
                    r2 = r2/1000;
                    buffer.R2 = r2;
                    buffer.mError = RangeInfo.precisionRangeErrEst;
                    buffer.status = RangeInfo.rangeStatus;
                }
                else if(RangeInfo.precisionRangeErrEst > 60)
                {
                    if(!msg.isEmpty())
                    {
                        buffer.mError = RangeInfo.precisionRangeErrEst;
                        buffer.status = RangeInfo.rangeStatus;
                        thresholdErrorCountR3++;
                        emit sendThresholdCount(thresholdErrorCountR0, thresholdErrorCountR1, thresholdErrorCountR2, thresholdErrorCountR3);
                        emit display(buffer.x, buffer.y, buffer.z, buffer.R0,buffer.R1 , RangeInfo.precisionRangeMm,
                                     buffer.R3,buffer.roll, buffer.pitch,buffer.yaw, buffer.mError,buffer.status);
                        r2 = msg.at(0).R2;
                        buffer.R2 = r2;
                    }
                }
                else
                {
                    r2 = msg.at(0).R2;
                    buffer.R2 = r2;
                    buffer.mError = RangeInfo.precisionRangeErrEst;
                    buffer.status = RangeInfo.rangeStatus;
                    errorCountR2++;
                    emit sendErrorCount(errorCountR0, errorCountR1, errorCountR2, errorCountR3);

                }
            } //end if
            antennaNum = 1;
            return;
        }
        if(antennaNum == 1)
        {
            buffer.reqNode = "102B";
            if (rcmRangeTo(destNode, ANTENNAMODE_B, 0, NULL,
                    &RangeInfo, &dataInfo, &scanInfo, &fullScanInfo) == 0)
            {

                // Get precision range measurement from msg received
                if (RangeInfo.rangeMeasurementType & RCM_RANGE_TYPE_PRECISION)
                {
                    ////qDebug()<<"Precision range: "<< RangeInfo.precisionRangeMm;
                    r3 = RangeInfo.precisionRangeMm;
                }

                 //if the status is 0, range was successful
                if (RangeInfo.rangeStatus == 0)
                {
                    ////qDebug()<<"Range Successful"<<" r3"<<r3;
                    //add range to buffer struct
                    r3 = r3/1000;
                    buffer.R3 = r3;
                    buffer.mError = RangeInfo.precisionRangeErrEst;
                    buffer.status = RangeInfo.rangeStatus;
                }
                else if(RangeInfo.precisionRangeErrEst > 60)
                {
                    if(!msg.isEmpty())
                    {

                        buffer.mError = RangeInfo.precisionRangeErrEst;
                        buffer.status = RangeInfo.rangeStatus;
                        thresholdErrorCountR3++;
                        emit sendThresholdCount(thresholdErrorCountR0, thresholdErrorCountR1, thresholdErrorCountR2, thresholdErrorCountR3);
                        emit display(buffer.x, buffer.y, buffer.z, buffer.R0,buffer.R1 , buffer.R2,
                                     RangeInfo.precisionRangeMm,buffer.roll, buffer.pitch,buffer.yaw, buffer.mError,buffer.status);
                        r3 = msg.at(0).R3;
                        buffer.R3 = r3;
                    }
                }
                else
                {
                    r3 = msg.at(0).R3;
                    buffer.R3 = r3;
                    buffer.mError = RangeInfo.precisionRangeErrEst;
                    buffer.status = RangeInfo.rangeStatus;
                    errorCountR3++;
                    emit sendErrorCount(errorCountR0, errorCountR1, errorCountR2, errorCountR3);
                }
            } //end if
            antennaNum = 0;
            radioNum = 0;
            return;
        }
    }
}

void RefInterface::readConfigFile()
{

    QStringList stringlist;
    QFile textfile(":/Config.txt");
    QTextStream ts(&textfile);
    if(!textfile.open(QIODevice::ReadOnly))
    {
        //qDebug()<<"config file not opened";
    }
    else
    {
    while(true)
    {
        QString line = ts.readLine();
        if(line.isNull())
        {
            break;
        }
        else
        {
            stringlist.append(line);
        }
    }

    x0 = stringlist.at(0).toFloat();
    y0 = stringlist.at(1).toFloat();
    z0 = stringlist.at(2).toFloat();
    x1 = stringlist.at(3).toFloat();
    y1 = stringlist.at(4).toFloat();
    z1 = stringlist.at(5).toFloat();
    x2 = stringlist.at(6).toFloat();
    y2 = stringlist.at(7).toFloat();
    z2 = stringlist.at(8).toFloat();
    x3 = stringlist.at(9).toFloat();
    y3 = stringlist.at(10).toFloat();
    z3 = stringlist.at(11).toFloat();
    oldx = stringlist.at(12).toFloat();
    oldy = stringlist.at(13).toFloat();
    oldz = stringlist.at(14).toFloat();
    destNode = stringlist.at(15).toInt();
    radioPort.append(stringlist.at(16).toLocal8Bit());
    radioPort1.append(stringlist.at(17).toLocal8Bit());
    r0 = stringlist.at(18).toFloat();
    r1 = stringlist.at(19).toFloat();
    r2 = stringlist.at(20).toFloat();
    r3 = stringlist.at(21).toFloat();
    }
}

void RefInterface::stop()
{
    //stop ref thread so consumer can grab info
    qDebug("Reference thread stopped");
   // stopped = false;
    stopped = true;
    rcmIfClose();
}


GuiInterface::GuiInterface()
{
    //clear msg queue in constructor
    msg.clear();
    stoppedConsumer = false;
}

void GuiInterface::run()
{

    //while consumer is not stopped, grab info and emit signal for eng screen to update display
    while(!stoppedConsumer)
    {

        //lock mutex
       mutex.lock();


       ////qDebug()<<"Gui thread running" <<endl;

       if(!msg.isEmpty())
       {
            //get data from queue
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
           dataGathered.reqNode = msg.first().reqNode;
           dataGathered.mError = msg.first().mError;
           dataGathered.status = msg.first().status;


           //emit signal for eng screen to update display
           //sleep(1000);
           emit display(dataGathered.x, dataGathered.y, dataGathered.z, dataGathered.R0, dataGathered.R1, dataGathered.R2,
                        dataGathered.R3,dataGathered.roll, dataGathered.pitch,dataGathered.yaw, dataGathered.mError,dataGathered.status);
            //will also emit a signal for logging data -- this allows for an easy way to get the data to the engineering screen
           emit logSignal(dataGathered.x, dataGathered.y, dataGathered.z, dataGathered.R0, dataGathered.R1, dataGathered.R2,
                          dataGathered.R3,dataGathered.roll, dataGathered.pitch,dataGathered.yaw, dataGathered.reqNode
                          , dataGathered.mError,dataGathered.status);

           emit emitPositionData(dataGathered.x, dataGathered.y, dataGathered.z);




          }


      mutex.unlock();
    }

    stoppedConsumer = false;
    //unlock the mutex, so the producer has another turn
}

void GuiInterface::stop()
{
    qDebug("GuiInterface thread stopped");
    stoppedConsumer = true;

    rcmIfClose();
}


