#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    thread1 = new MyThread;

    tcpServer = new QTcpServer(this); //服务器监听类
       if(!tcpServer->listen(QHostAddress::Any,50007)) //服务器监听本机所有IP的50007端口
        {
            qDebug() << tcpServer->errorString(); //Debug出错误信息
            tcpServer->close(); //关闭监听
        }

        connect(tcpServer,SIGNAL(newConnection()),this,SLOT(creatConnection()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::creatConnection() //槽函数:创建连接
{

    tcpSocket = new QTcpSocket(this); //socket类

    tcpSocket = tcpServer->nextPendingConnection();
    useConnection(); //在这个函数中使用连接套接字
}

void Widget::useConnection()
{
    ui->textBrowser->insertPlainText("connection succeed.\n");

    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(receiveMessage()));

}

void Widget::receiveMessage() //槽函数：接收消息
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
    /*开启一个线程*/
    thread1->start();
    qDebug()<<"主线程id："<<QThread::currentThreadId();
}

void Widget::closeThreadBtnSlot()
{
    /*关闭多线程*/
    qDebug()<<tr("关闭线程");
    if(thread1->isRunning())
     {
       thread1->closeThread();
       thread1->quit();
       thread1->wait();
    }
}

void Widget::finishedThreadBtnSlot()
{
    qDebug()<<tr("完成信号finished触发");
}
