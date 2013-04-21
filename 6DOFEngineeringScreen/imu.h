#ifndef IMU_H
#define IMU_H

#include <QObject>

class QextSerialPort;
class IMU
{

private:
    QextSerialPort *port;

public:
    IMU();

public slots:
    void onReadyRead();
    void onDsrChanged(bool status);
};

#endif // IMU_H
