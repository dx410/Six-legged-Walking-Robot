#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this); 
       if(!tcpServer->listen(QHostAddress::Any,50007)) //listen to 50007 port
        {
            qDebug() << tcpServer->errorString(); //Debug error
            tcpServer->close(); //close listen
        }

        connect(tcpServer,SIGNAL(newConnection()),this,SLOT(creatConnection()));
        
}

Widget::~Widget()
{
    delete ui;
}

void Widget::creatConnection() 
{
    
    tcpSocket = new QTcpSocket(this); //socket
    tcpSocket = tcpServer->nextPendingConnection();
 //   tcpServer->close(); //close listen
    useConnection(); //use this function to connect socket
}

void Widget::useConnection()
{
    ui->textBrowser->insertPlainText("connection succeed.\n");
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(receiveMessage()));
   //if it is ready to read, recieve messages
}

void Widget::receiveMessage() 
{
    //read all data, the return type is QByteArray
    QByteArray receiveDate = tcpSocket->readAll();
    QString temp = receiveDate;
     ui->textBrowser->insertPlainText(temp);
     /*
        the type of text id QString, we use temp to receice Data；
     */

}
