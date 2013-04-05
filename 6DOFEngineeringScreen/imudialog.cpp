#include "imudialog.h"
#include "ui_imudialog.h"
#include "qextserialport.h"

IMUDialog::IMUDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IMUDialog)
{
    ui->setupUi(this);
    yawread = 0;
    pitchread = 0;
    rollread = 0;


    //modify the port settings on your own
/*#ifdef Q_OS_UNIX
    port = new QextSerialPort(QLatin1String("/dev/tty.FireFly-8842-SPP"), QextSerialPort::Polling);
#else
    port = new QextSerialPort(QLatin1String("COM1"), QextSerialPort::Polling);
#endif /*Q_OS_UNIX*/
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
    //port->setTimeout(500);

    connect(ui->connectButton,SIGNAL(clicked()),this,SLOT(openUp()));
    //connect(ui->disconButton,SIGNAL(clicked()),this,SLOT(discon()));
    //connect(ui->stopStreamButton,SIGNAL(clicked()),this,SLOT(stopStream()));
    connect(ui->streamButton,SIGNAL(clicked()),this,SLOT(stream()));


}

void IMUDialog::openUp(){
    //open = port->open(QIODevice::ReadWrite | QIODevice::Unbuffered);
    if (port->open(QIODevice::ReadWrite) == true) {
        connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        connect(port, SIGNAL(dsrChanged(bool)), this, SLOT(onDsrChanged(bool)));
        if (!(port->lineStatus() & LS_DSR))
            qDebug() << "warning: device is not turned on";
        qDebug() << "listening for data on" << port->portName();
    }
    else
        qDebug() << "device failed to open:" << port->errorString();
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
    //port->write("#o0");
   //port->write("#f");
   //port->flush();  // Clear input buffer up to here
    char buff[100];

    int numBytes;
    numBytes = port->bytesAvailable();
    qDebug() << "numbytes before if" << numBytes;
    if(numBytes > 1024)
        numBytes = 1024;

    qDebug() << "numbytes" << QString::number(numBytes);
    int i = port->readLine(buff, numBytes);
    if (i != -1)
        buff[i] = '\0';
    else
        buff[0] = '\0';
    QString msg = QLatin1String(buff);

    ui->textEditStream->append(msg);
    if (msg[0] == '#')
    {
        tempmsg = msg.remove(0,5);
        //ui->textEditStream->append(tempmsg);
        QStringList msglist = tempmsg.split(",");
        yawread = msglist[0].toFloat();
        pitchread = msglist[1].toFloat();
        rollread = msglist[2].toFloat();
        QString yawstr = QString::number(yawread);
        QString pitchstr = QString::number(pitchread);
        QString rollstr = QString::number(rollread);
        ui->textEditStream->append(yawstr);
        ui->textEditStream->append(pitchstr);
        ui->textEditStream->append(rollstr);

        }

    //received_msg->ensureCursorVisible();
    //qDebug("bytes available: %d", numBytes);
    //qDebug("received: %d", i);

}

void IMUDialog::onReadyRead()
{
    QByteArray bytes;
    int a = port->bytesAvailable();
    bytes.resize(a);
    port->read(bytes.data(), bytes.size());
    qDebug() << "bytes read:" << bytes.size();
    qDebug() << "bytes:" << bytes;
}

void IMUDialog::onDsrChanged(bool status)
{
    if (status)
        qDebug() << "device was turned on";
    else
        qDebug() << "device was turned off";
}

IMUDialog::~IMUDialog()
{
    port->close();
    delete ui;
    delete port;
    port = NULL;
}
