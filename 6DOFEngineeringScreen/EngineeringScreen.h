#ifndef ENGINEERINGSCREEN_H
#define ENGINEERINGSCREEN_H

#include <QDialog>
#include <QtGui>
#include <refinterface.h>
#include <guiinterface.h>
#include <QGraphicsScene>
#include <QObject>
#include <mainwidget.h>
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
    
private:
    Ui::Dialog *ui;

private slots:
    void pause();
    void updateDisplay(float x, float y, float z, float R0, float R1, float R2, float R3, float roll, float pitch, float yaw);
    void log(float x, float y, float z, float R0, float R1, float R2, float R3, float roll, float pitch, float yaw, QString reqNode);
    void getUserParameters();

protected:
    RefInterface refinterface;
    GuiInterface guiinterface;
    MainWidget sword;

    void closeEvent(QCloseEvent *event);

};

#endif // ENGINEERINGSCREEN_H
