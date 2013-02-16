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

#define SLEEPMODE 0
#define DESTINATION_NODE    100
#define ANTENNAMODE_A 0
#define ANTENNAMODE_B 1
#define ANTENNAMODE_C 2
#define ANTENNAMODE_D 3

QMutex mutex;
QQueue<struct rangeInfo> msg;
rangeInfo buffer;

RefInterface::RefInterface()
{
    msg.clear();
    //sets seeds and reference radio positions
    //this will be put in config file
    seedx = 0.0;
    seedy = 1.0;
    x0 = -500;
    y0 = 0;
    x1= 500;
    y1 = 0;

    char *destAdd = "/dev/cu.usbmodem101"; //this will be different in windows
    //  TO DO!! -- need to figure out a way to scan ports and auto figure path to com port - windows?

    //initialize radio (USB and dest address)
    //dest address is path to com port
    if (rcmIfInit(rcmIfUsb, destAdd) != OK)
    {
        printf("Initialization failed.\n");
        exit(0);
    }
    if(OK)
    {
        if (rcmOpModeSet(RCM_OPMODE_RCM) != 0)
        {
            printf("Time out waiting for opmode set.\n");
            exit(0);

        }
    }
       stopped = false;
}

void RefInterface::run()
{


    //while the pause button is not pressed (!stopped), run the ref thread
    while(!stopped)
    {
        qDebug("Reference thread run");
        mutex.lock();

        //wait 2 seconds
        sleep(2);


//        //range to the controller using radio A
//        if (rcmRangeTo(DESTINATION_NODE, ANTENNAMODE_A, 0, NULL,
//                &RangeInfo, &dataInfo, &scanInfo, &fullScanInfo) == 0)
//        {

//            //This gets the precision range measurement
//            if (RangeInfo.rangeMeasurementType & RCM_RANGE_TYPE_PRECISION)
//            {
//                qDebug()<<"Precision range: "<< RangeInfo.precisionRangeMm;
//                r0 = RangeInfo.precisionRangeMm;

//                // add range to buffer structure
//                buffer.R0 = r0;
//            }

//            //if the status comes back as 0, the radio ranged correctly
//            if (RangeInfo.rangeStatus == 0)
//            {
//                qDebug()<<"Range Successful";
//            }
//        } //end if


//        //range to controller using radio B
//        if (rcmRangeTo(DESTINATION_NODE, ANTENNAMODE_B, 0, NULL,
//                &RangeInfo, &dataInfo, &scanInfo, &fullScanInfo) == 0)
//        {

//            // Get precision range measurement from msg received
//            if (RangeInfo.rangeMeasurementType & RCM_RANGE_TYPE_PRECISION)
//            {
//                qDebug()<<"Precision range: "<< RangeInfo.precisionRangeMm;
//                r1 = RangeInfo.precisionRangeMm;

//                //add range to buffer struct
//                buffer.R1 = r1;
//                qDebug()<<"Buffer R1:  "<<buffer.R1;
//            }

//             //if the status is 0, range was successful
//            if (RangeInfo.rangeStatus == 0)
//            {
//                qDebug()<<"Range Successful";
//            }
//        } //end if



        //for debug
        r0 = qrand()%2000;
        r1 = qrand()%2000;
        buffer.R0 = r0;
        buffer.R1 = r1;

        //TO DO!! -- add ranging to radios C and D,  simulate for now
        //copy range A to C and range B to D

        //call solver method -- am using geom2d right now until solver class is added
        find_intersection_points(x0 ,y0 ,x1 , y1 , r0, r1, seedx, seedy, &px, &py);
        qDebug()<<"x and y: "<<px<< " "<<py;

        //Here I set the buffer struct to the position returned from solver
        buffer.x = px;
        buffer.y = py;
        //For now, setting ranges 2 and 3 (radio C and D) to 0, will simulate and copy A and B here
        buffer.R2 = 0;
        buffer.R3 = 0;
        //randomly generating roll, pitch, yaw here
        buffer.roll = qrand()%360;
        buffer.pitch = qrand()%360;
        buffer.yaw = qrand()%360;

        //append the buffer to the queue
        msg.append(buffer);

        //unlock the mutex so the consumer can have access to buffer

        //set stopped to false, so consumer has a turn
        stopped = false;

        mutex.unlock();
    }
}

void RefInterface::stop()
{
    //stop ref thread so consumer can grab info
    qDebug("Reference thread stopped");
    stopped = true;
//    rcmIfFlush();
//    rcmIfClose();
}


GuiInterface::GuiInterface()
{
    //clear msg queue in constructor
    msg.clear();
    //engScreen = new Dialog();
    stoppedConsumer = false;
}

void GuiInterface::run()
{
    //while consumer is not stopped, grab info and emit signal for eng screen to update display
    while(!stoppedConsumer)
    {

        //lock mutex
       mutex.lock();

       //sleep(2);
       //qDebug()<<"Gui thread run" <<endl;

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
            //remove msg just copied
           msg.removeFirst();
           //emit signal for eng screen to update display
           emit display(dataGathered.x, dataGathered.y, dataGathered.z, dataGathered.R0, dataGathered.R1, dataGathered.R2,
                        dataGathered.R3,dataGathered.roll, dataGathered.pitch,dataGathered.yaw);
            //will also emit a signal for logging data -- this allows for an easy way to get the data to the engineering screen
           emit logSignal(dataGathered.x, dataGathered.y, dataGathered.z, dataGathered.R0, dataGathered.R1, dataGathered.R2,
                          dataGathered.R3,dataGathered.roll, dataGathered.pitch,dataGathered.yaw);


           }
        //unlock the mutex, so the producer has another turn
          mutex.unlock();
    }
    stoppedConsumer = false;

}

void GuiInterface::stop()
{
    qDebug("GuiInterface thread stopped");
    stoppedConsumer = true;
//    rcmIfFlush();
//    rcmIfClose();
}


