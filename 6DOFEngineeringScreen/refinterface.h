#ifndef REFINTERFACE_H
#define REFINTERFACE_H

#include "rcmIf.h"
#include "rcm.h"
#include "hostInterfaceRCM.h"
#include "hostInterfaceCommon.h"
#include "solver.h"

#include <QObject>
#include <QThread>
#include <QByteArray>
#include <qextserialport.h>


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
    QString reqNode;
};


class RefInterface : public QThread
{
    Q_OBJECT
public:
    RefInterface();
    void stop();
    void range();
    void readConfigFile();

    Solver *solver;
    rcmMsg_RangeInfo RangeInfo;
    rcmMsg_DataInfo dataInfo;
    rcmMsg_ScanInfo scanInfo;
    rcmMsg_FullScanInfo fullScanInfo;
    rcmIfType   rcmIf;
    rcmConfiguration config;
    rcmMsg_GetStatusInfoConfirm statusInfo;
    float x0, y0, z0;
    float x1, y1, z1;
    float x2, y2, z2;
    float x3, y3, z3;
    float r0, r1, r2, r3;
    float seedx, seedy;
    float px, py, pz;
    QByteArray radioPort;
    QByteArray radioPort1;
    int NumOfIter;
    float E;
    int destNode;
    int radioNum;
    int antennaNum;
    int radioCom;
    int radioCom1;
    QString solverType;
    rangeInfo buffer;
    volatile bool stopped;
protected:
    void run();


signals:


public slots:


private:


};

#endif // REFINTERFACE_H
