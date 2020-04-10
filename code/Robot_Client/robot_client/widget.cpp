#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Six-legged walking Robot");
    this->setMaximumSize(381,360);
    this->setMinimumSize(381,360);

/*    buttom  */
    connect(ui->stop,SIGNAL(clicked()),this,SLOT(sendstop()));
    connect(ui->forward,SIGNAL(clicked()),this,SLOT(sendforward()));
    connect(ui->backward,SIGNAL(clicked()),this,SLOT(sendbackward()));
    connect(ui->left,SIGNAL(clicked()),this,SLOT(sendleft()));
    connect(ui->right,SIGNAL(clicked()),this,SLOT(sendright()));
    connect(ui->connectrobot,SIGNAL(clicked()),this,SLOT(connectserver()));
    connect(ui->disconnectrobot,SIGNAL(clicked()),this,SLOT(disconnectserver()));

/*     TCP    */
    tcpSocket = new QTcpSocket(this);
    this->serverAddress = "192.168.191.2"; //  IP
    this->serverPort = 50007 ;//  PORT
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readdata()));
}

Widget::~Widget()
{
    delete ui;
    if(tcpSocket->state() == QAbstractSocket::ConnectedState)
        disconnectserver();
}

void Widget::sendforward()
{
    if(tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
       // QByteArray data = "forward";
       // char* str = data.data();
        tcpSocket->write ("forward");
        tcpSocket->waitForBytesWritten(300);
    }
    else
    {
        QMessageBox::information(this,"Error","Please connect server !");
    }
}

void Widget::sendbackward()
{
    if(tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        tcpSocket->write("backward");
        tcpSocket->waitForBytesWritten(300);
    }
    else
    {
        QMessageBox::information(this,"Error","Please connect server !");
    }
}

void Widget::sendleft()
{
    if(tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        tcpSocket->write("left");
        tcpSocket->waitForBytesWritten(300);
    }
    else
    {
        QMessageBox::information(this,"Error","Please connect server !");
    }
}

void Widget::sendright()
{
    if(tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        tcpSocket->write("right");
        tcpSocket->waitForBytesWritten(300);
    }
    else
    {
        QMessageBox::information(this,"Error","Please connect server !");
    }
}

void Widget::sendstop()
{
    if(tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        tcpSocket->write("stop");
        tcpSocket->waitForBytesWritten(300);
    }
    else
    {
        QMessageBox::information(this,"Error","Please connect server !");
    }
}

void Widget::connectserver()
{

    tcpSocket->connectToHost(this->serverAddress,this->serverPort);
    tcpSocket->waitForConnected(1000);
    if(tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
         tcpSocket->write("data");
         tcpSocket->waitForBytesWritten(300);
         QMessageBox::information(this,"Success","connect successfully!");
    }
    else
    {
         QMessageBox::information(this,"Error","connect false!");
    }

}

void Widget::disconnectserver()
{
    if(tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        tcpSocket->write("disconnect");
        tcpSocket->waitForBytesWritten(300);

        tcpSocket->disconnectFromHost();
        tcpSocket->waitForDisconnected(1000);
        QMessageBox::information(this,"Message","disconnect!");
    }
}


void Widget::readdata()
{
/*
    QByteArray receiveDate = tcpSocket->readAll();
    QString temp = receiveDate;
   // ui->text_tem->insertPlainText(temp);
    ui->MPU_state->setText(temp);
*/
    QByteArray dataArray =tcpSocket->readAll();
    const NetData* pData = (const NetData*)(dataArray.data());
    QString strShow = tr("WELCOME! \r\n");
    strShow += tr("Length = %1\r\n").arg(pData->length);
//    strShow += tr("n1 = %1\r\n").arg(pData->n1);
//    strShow += tr("d1 = %1\r\n").arg(pData->d1);
//    strShow += tr("d2 = %1\r\n").arg(pData->d2);
//    strShow += tr("name = %1\r\n").arg(pData->name);
    QString temp = tr(" %1\r").arg(pData->d1);
    ui->dht_tem->setText(temp);
    QString humi = tr(" %1\r").arg(pData->d2);
    ui->dht_hum->setText(humi);
    QString mpu = tr("state = %1\r").arg(pData->name);
    ui->MPU_state->setText(mpu);
    ui->text->insertPlainText(strShow);

}





