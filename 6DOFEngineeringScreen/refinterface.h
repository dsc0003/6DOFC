#ifndef REFINTERFACE_H
#define REFINTERFACE_H

#include <QObject>
#include <QThread>


struct rangeInfo {
    int R0;
    int R1;
    int R2;
    int R3;
    int x;
    int y;
    int z;
    int yaw;
    int pitch;
    int roll;
};


class RefInterface : public QThread
{
    Q_OBJECT
public:
    RefInterface();
    void stop();

protected:
    void run();
    int x0, y0;
    int x1, y1;
    int r0, r1;
    int seedx, seedy;
    int px, py;

signals:


public slots:


private:
    volatile bool stopped;

};

#endif // REFINTERFACE_H
