#ifndef IMUDIALOG_H
#define IMUDIALOG_H

#include <QDialog>

class QextSerialPort;

namespace Ui {
class IMUDialog;
}

class IMUDialog : public QDialog
{
    Q_OBJECT
    
public:
    QextSerialPort *port;
    explicit IMUDialog(QWidget *parent = 0);
    ~IMUDialog();
public slots:
    void connectit();
    void discon();
    void stopStream();
    void stream();

private:
    Ui::IMUDialog *ui;
};

#endif // IMUDIALOG_H
