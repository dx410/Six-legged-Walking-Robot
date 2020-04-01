#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    thread1 = new MyThread;

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
    if(temp=="hello")
    {
      openThreadBtnSlot();
      ui->textBrowser->insertPlainText(temp);
    }
    else if(temp=="disconnect")
    {
        closeThreadBtnSlot();
        ui->textBrowser->insertPlainText(temp);
    }

}



void Widget::openThreadBtnSlot()
{
    /*open a thread*/
    thread1->start();
    qDebug()<<"main thread id："<<QThread::currentThreadId();
}

void Widget::closeThreadBtnSlot()
{
    /*close thread*/
    qDebug()<<tr("close thread");
    if(thread1->isRunning())
     {
       thread1->closeThread();
       thread1->quit();
       thread1->wait();
    }
}

void Widget::finishedThreadBtnSlot()
{
    qDebug()<<tr("completed signal finished");
}
