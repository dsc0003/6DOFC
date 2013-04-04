#ifndef IMUDIALOG_H
#define IMUDIALOG_H

#include <QDialog>
#include <QtDebug>

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
    float yawread;
    float pitchread;
    float rollread;
    bool open;
    QString tempmsg;
public slots:
    void openUp();
    void discon();
    void stopStream();
    void stream();
private:
    Ui::IMUDialog *ui;
};

#endif // IMUDIALOG_H
