#include "imudialog.h"
#include "ui_imudialog.h"
#include "qextserialport.h"

IMUDialog::IMUDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IMUDialog)
{
    ui->setupUi(this);


#ifdef Q_OS_UNIX
    port = new QextSerialPort(QLatin1String("/dev/tty.FireFly-8842-SPP"), QextSerialPort::Polling);
#else
    port = new QextSerialPort(QLatin1String("COM1"), QextSerialPort::Polling);
#endif /*Q_OS_UNIX*/
    port->setBaudRate(BAUD57600);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_2);
    //set timeouts to 500 ms
    port->setTimeout(500);

    connect(ui->connectButton,SIGNAL(clicked()),this,SLOT(connectit()));
    connect(ui->disconButton,SIGNAL(clicked()),this,SLOT(discon()));
    connect(ui->stopStreamButton,SIGNAL(clicked()),this,SLOT(stopStream()));
    connect(ui->streamButton,SIGNAL(clicked()),this,SLOT(stream()));


}

void IMUDialog::connectit(){
    port->open(QIODevice::ReadWrite | QIODevice::Unbuffered);
    qDebug("is open: %d", port->isOpen());
}

void IMUDialog::discon(){
    port->close();
    qDebug("is open: %d", port->isOpen());
}

void IMUDialog::stopStream(){
    port->write("#o0");
    ui->textEditStream->clear();

}

void IMUDialog::stream(){
    port->write("#ot");
    port->write("#o1");
    port->write("#oe0");
    char buff[1024];


    /*numBytes = port->bytesAvailable();
    if(numBytes > 1024)
        numBytes = 1024;*/

    int numBytes;
    int i = port->read(buff, numBytes);
    if (i != -1)
        buff[i] = '\0';
    else
        buff[0] = '\0';
    QString msg = QLatin1String(buff);

    ui->textEditStream->append(msg);

    //received_msg->ensureCursorVisible();
    //qDebug("bytes available: %d", numBytes);
    //qDebug("received: %d", i);

}

IMUDialog::~IMUDialog()
{
    delete ui;
}
