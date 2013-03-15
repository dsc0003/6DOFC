#ifndef GUIINTERFACE_H
#define GUIINTERFACE_H

#include <QObject>
#include <QThread>
#include <QtCore>


struct myStruct {
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

class GuiInterface : public QThread
{
    Q_OBJECT
public:
    GuiInterface();
    void run();
    void stop();
    myStruct dataGathered;
     volatile bool stoppedConsumer;

    //Dialog* engScreen;

protected:


signals:
    void display(float x, float y, float z, float R0, float R1, float R2, float R3, float roll, float pitch, float yaw);
    void logSignal(float x, float y, float z, float R0, float R1, float R2, float R3, float roll, float pitch, float yaw);

public slots:

private:


};

#endif // GUIINTERFACE_H
