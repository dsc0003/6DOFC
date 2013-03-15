#ifndef REFINTERFACE_H
#define REFINTERFACE_H

#include "rcmIf.h"
#include "rcm.h"
#include "hostInterfaceRCM.h"
#include "hostInterfaceCommon.h"
#include "solver.h"

#include <QObject>
#include <QThread>


struct rangeInfo {
    float R0;
    float R1;
    float R2;
    float R3;
    float x;
    float y;
    float z;
    float yaw;
    float pitch;
    float roll;
};


class RefInterface : public QThread
{
    Q_OBJECT
public:
    RefInterface();
    Solver *solver;
    void stop();

    rcmMsg_RangeInfo RangeInfo;
    rcmMsg_DataInfo dataInfo;
    rcmMsg_ScanInfo scanInfo;
    rcmMsg_FullScanInfo fullScanInfo;
    rcmIfType   rcmIf;
    rcmConfiguration config;
    rcmMsg_GetStatusInfoConfirm statusInfo;

protected:
    void run();
    float x0, y0;
    float x1, y1;
    float r0, r1;
    float seedx, seedy;
    float px, py;

signals:


public slots:


private:
    volatile bool stopped;

};

#endif // REFINTERFACE_H
