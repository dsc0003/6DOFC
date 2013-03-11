#include "imudialog.h"
#include "ui_imudialog.h"
#include "qextserialport.h"

IMUDialog::IMUDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IMUDialog)
{
    ui->setupUi(this);


#ifdef Q_OS_UNIX
    port = new QextSerialPort(QLatin1String("/dev/tty.FireFly-8842-SPP"), QextSerialPort::EventDriven);
#else
    port = new QextSerialPort(QLatin1String("COM1"), QextSerialPort::EventDriven);
#endif /*Q_OS_UNIX*/
    port->setBaudRate(BAUD57600);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_2);
   //set timeouts to 500 ms
   // port->setTimeout(500);

    connect(ui->connectButton,SIGNAL(clicked()),this,SLOT(connectit()));
    connect(ui->disconButton,SIGNAL(clicked()),this,SLOT(discon()));
    connect(ui->stopStreamButton,SIGNAL(clicked()),this,SLOT(stopStream()));
    connect(ui->streamButton,SIGNAL(clicked()),this,SLOT(stream()));


}

void IMUDialog::connectit(){
    if (port->open(QIODevice::ReadWrite) == true) {
        connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        connect(port, SIGNAL(dsrChanged(bool)), this, SLOT(onDsrChanged(bool)));
        if (!(port->lineStatus() & LS_DSR))
            ui->textEditStream->append("warning: device is not turned on");
        ui->textEditStream->append("listening for data on" + port->portName());
    }
    else {
        ui->textEditStream->append("device failed to open:" + port->errorString());
    }
}

void IMUDialog::onReadyRead()
{
    QByteArray bytes;
    int a = port->bytesAvailable();
    bytes.resize(a);
    port->read(bytes.data(), 25);
    ui->textEditStream->append("bytes read:");
    ui->textEditStream->append(QString(bytes.size()));
    //QLatin1String b = bytes.at(0);
    //QByteArray yaw;
    //for (int i = 6; i<10; i++)
        //yaw.append(bytes[i]);
    ui->textEditStream->setText(bytes);
}

void IMUDialog::onDsrChanged(bool status)
{
    if (status)
        ui->textEditStream->append("device was turned on");
    else
        ui->textEditStream->append("device was turned off");
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

    port->flush();  // Clear input buffer up to here
    port->write("#s00");  // Request synch token
    char buff[1024];

    int numBytes;
    numBytes = port->bytesAvailable();
    if(numBytes > 1024)
        numBytes = 1024;


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
