#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("Six-foot Robot");
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
    this->serverAddress = "127.0.0.1"; //  IP
    this->serverPort = 50007 ;//  PORT

}

Widget::~Widget()
{
    if(tcpSocket.state() == QAbstractSocket::ConnectedState)
        disconnectserver();
    delete ui;
}

void Widget::sendforward()
{
    if(tcpSocket.state() == QAbstractSocket::ConnectedState)
    {
       // QByteArray data = "forward";
       // char* str = data.data();
        this->tcpSocket.write ("forward");
        this->tcpSocket.waitForBytesWritten(300);
    }
    else
    {
        QMessageBox::information(this,"Error","Please connect server !");
    }
}

void Widget::sendbackward()
{
    if(tcpSocket.state() == QAbstractSocket::ConnectedState)
    {
        this->tcpSocket.write("backward");
        this->tcpSocket.waitForBytesWritten(300);
    }
    else
    {
        QMessageBox::information(this,"Error","Please connect server !");
    }
}

void Widget::sendleft()
{
    if(tcpSocket.state() == QAbstractSocket::ConnectedState)
    {
        this->tcpSocket.write("left");
        this->tcpSocket.waitForBytesWritten(300);
    }
    else
    {
        QMessageBox::information(this,"Error","Please connect server !");
    }
}

void Widget::sendright()
{
    if(tcpSocket.state() == QAbstractSocket::ConnectedState)
    {
        this->tcpSocket.write("right");
        this->tcpSocket.waitForBytesWritten(300);
    }
    else
    {
        QMessageBox::information(this,"Error","Please connect server !");
    }
}

void Widget::sendstop()
{
    if(tcpSocket.state() == QAbstractSocket::ConnectedState)
    {
        this->tcpSocket.write("stop");
        this->tcpSocket.waitForBytesWritten(300);
    }
    else
    {
        QMessageBox::information(this,"Error","Please connect server !");
    }
}

void Widget::connectserver()
{

    this->tcpSocket.connectToHost(this->serverAddress,this->serverPort);
    this->tcpSocket.waitForConnected(1000);
    if(tcpSocket.state() == QAbstractSocket::ConnectedState)
    {
         QMessageBox::information(this,"Success","connect successfully!");
    }
    else
    {
         QMessageBox::information(this,"Error","connect false!");
    }

}

void Widget::disconnectserver()
{
    if(tcpSocket.state() == QAbstractSocket::ConnectedState)
    {
        this->tcpSocket.write("disconnect");
        this->tcpSocket.waitForBytesWritten(300);

        this->tcpSocket.disconnectFromHost();
        this->tcpSocket.waitForDisconnected(1000);
        QMessageBox::information(this,"Message","disconnect!");
    }
}
