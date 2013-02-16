#ifndef ENGINEERINGSCREEN_H
#define ENGINEERINGSCREEN_H

#include <QDialog>
#include <QtGui>
#include <refinterface.h>
#include <guiinterface.h>
#include <QGraphicsScene>
#include <QObject>
#include <mainwidget.h>
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


    //void log(int x, int y, int z, int R0, int R1, int R2, int R3, int roll, int pitch, int yaw);

private slots:
    void pause();
    void updateDisplay(int x, int y, int z, int R0, int R1, int R2, int R3, int roll, int pitch, int yaw);
    void log(int x, int y, int z, int R0, int R1, int R2, int R3, int roll, int pitch, int yaw);

protected:
    RefInterface refinterface;
    GuiInterface guiinterface;

    void closeEvent(QCloseEvent *event);

};

#endif // ENGINEERINGSCREEN_H
