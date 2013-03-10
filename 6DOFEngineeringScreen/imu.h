#ifndef IMU_H
#define IMU_H
class QextSerialPort;
class IMU
{
private:
    QextSerialPort *port;
public:

    IMU();
};

#endif // IMU_H
