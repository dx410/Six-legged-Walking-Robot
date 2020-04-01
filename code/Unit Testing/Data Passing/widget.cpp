#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this); 
       if(!tcpServer->listen(QHostAddress::Any,50007)) 
        {
            qDebug() << tcpServer->errorString(); 
            tcpServer->close();
        }

        
        connect(tcpServer,SIGNAL(newConnection()),this,SLOT(creatConnection()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::creatConnection()
{
    tcpSocket = new QTcpSocket(this); 
    
    tcpSocket = tcpServer->nextPendingConnection();
 
    useConnection(); 
}

void Widget::useConnection()
{
    
    ui->textBrowser->insertPlainText("connection succeed.\n");

    
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(receiveMessage()));

}

void Widget::receiveMessage() 
{
    
    QByteArray receiveDate = tcpSocket->readAll();
    QString temp = receiveDate;
     ui->textBrowser->insertPlainText(temp);
    if (temp=="data")
    {
        NetData ssData;

       ssData.length = sizeof(NetData);  //length of data
        ssData.d1 = 0;
        ssData.d2 = 0;
        test(ssData.d1,ssData.d2);    // data transfer
        char name[32] = "Say Hello.";
        strncpy(ssData.name, name, 32);
        QByteArray dataArray = QByteArray::fromRawData((char*)&ssData, sizeof(NetData));
        this->tcpSocket->write(dataArray);

    }
}

void Widget::test(double &x, double &y) 
{
    QString str1="23.0";
    double val1=str1.toDouble(); //val=23.0
    QString str2="23.0";
    double val2=str2.toDouble(); //val=23.0
    x=val1;
    y=val2;
}
