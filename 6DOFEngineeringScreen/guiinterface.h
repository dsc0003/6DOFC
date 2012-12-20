#ifndef GUIINTERFACE_H
#define GUIINTERFACE_H

#include <QObject>
#include <QThread>
#include <QtCore>


struct myStruct {
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

class GuiInterface : public QThread
{
    Q_OBJECT
public:
    GuiInterface();
    void run();
    void stop();
    myStruct dataGathered;

    //Dialog* engScreen;

protected:


signals:
    void display(int x, int y, int z, int R0, int R1, int R2, int R3, int roll, int pitch, int yaw);
    void logSignal(int x, int y, int z, int R0, int R1, int R2, int R3, int roll, int pitch, int yaw);

public slots:

private:
    volatile bool stoppedConsumer;

};

#endif // GUIINTERFACE_H
