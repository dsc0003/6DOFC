#ifndef IMU_H
#define IMU_H
class QextSerialPort;
class IMU
{
private:
    QextSerialPort *port;
public:

    IMU();
    void onReadyRead();
    void onDsrChanged(bool status);
};

#endif // IMU_H
