#ifndef ENGINEERINGSCREEN_H
#define ENGINEERINGSCREEN_H

#include <QDialog>
#include <QtGui>
#include <refinterface.h>
#include <guiinterface.h>
#include <QGraphicsScene>
#include <QObject>
#include "window.h"
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    bool logFlag;
    QString fileName;
    IMUDialog *imu;

signals:
    void emitRotationData(float, float, float);

    
private:
    Ui::Dialog *ui;

private slots:
    void pause();
    void updateDisplay(float x, float y, float z, float R0, float R1, float R2, float R3, float roll, float pitch
                       , float yaw,float mError, float status);
    void log(float x, float y, float z, float R0, float R1, float R2, float R3, float roll, float pitch
             , float yaw, QString reqNode,float mError, float status);
    void getUserParameters();
    void getData();
    void updateErrorCount(int errorCountR0, int errorCountR1, int errorCountR2, int errorCountR3);
    void updateThresholdErrorCount(int thresholdErrorCountR0, int thresholdErrorCountR1,int thresholdErrorCountR2,int thresholdErrorCountR3);

protected:
    RefInterface refinterface;
    GuiInterface guiinterface;
    //MainWidget sword;
    Window sword;


    void closeEvent(QCloseEvent *event);

};

#endif // ENGINEERINGSCREEN_H
