#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    thread1 = new MyThread1;
    thread2 = new MyThread2;
    thread3 = new MyThread3;
    thread4 = new MyThread4;
    thread5 = new MyThread5;

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
    if(temp=="forward")
    {
      if(thread2->isRunning())
      {
         closeThreadSlot2();
      }
      if(thread3->isRunning())
      {
         closeThreadSlot3();
      }
      if(thread4->isRunning())
      {
         closeThreadSlot4();
      }
      if(thread5->isRunning())
      {
         closeThreadSlot5();
      }
      openThreadSlot1();
      ui->textBrowser->insertPlainText(temp);
    }
    if(temp=="backward")
    {
      if(thread1->isRunning())
      {
         closeThreadSlot1();
      }
      if(thread3->isRunning())
      {
         closeThreadSlot3();
      }
      if(thread4->isRunning())
      {
         closeThreadSlot4();
      }
      if(thread5->isRunning())
      {
         closeThreadSlot5();
      }
      openThreadSlot2();
      ui->textBrowser->insertPlainText(temp);
    }
    if(temp=="left")
    {
      if(thread1->isRunning())
      {
         closeThreadSlot1();
      }
      if(thread2->isRunning())
      {
         closeThreadSlot2();
      }
      if(thread4->isRunning())
      {
         closeThreadSlot4();
      }
      if(thread5->isRunning())
      {
         closeThreadSlot5();
      }
      openThreadSlot3();
      ui->textBrowser->insertPlainText(temp);
    }
    if(temp=="right")
    {
      if(thread1->isRunning())
      {
         closeThreadSlot1();
      }
      if(thread2->isRunning())
      {
         closeThreadSlot2();
      }
      if(thread3->isRunning())
      {
         closeThreadSlot3();
      }
      if(thread5->isRunning())
      {
         closeThreadSlot5();
      }
      openThreadSlot4();
      ui->textBrowser->insertPlainText(temp);
    }
    if(temp=="stop")
    {
      if(thread1->isRunning())
      {
         closeThreadSlot1();
      }
      if(thread2->isRunning())
      {
         closeThreadSlot2();
      }
      if(thread3->isRunning())
      {
         closeThreadSlot3();
      }
      if(thread4->isRunning())
      {
         closeThreadSlot4();
      }
      openThreadSlot5();
      ui->textBrowser->insertPlainText(temp);
    }
    else if(temp=="disconnect")
    {
        if(thread1->isRunning())
        {
           closeThreadSlot1();
        }
        if(thread2->isRunning())
        {
           closeThreadSlot2();
        }
        if(thread3->isRunning())
        {
           closeThreadSlot3();
        }
        if(thread4->isRunning())
        {
           closeThreadSlot4();
        }
        if(thread5->isRunning())
        {
           closeThreadSlot5();
        }
        ui->textBrowser->insertPlainText(temp);
    }

}



void Widget::openThreadSlot1()
{
    /*开启一个线程*/
    thread1->start();
    qDebug()<<"主线程id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot1()
{
    /*关闭多线程*/
    qDebug()<<tr("关闭线程1");
    if(thread1->isRunning())
     {
       thread1->closeThread();
       thread1->quit();
       thread1->wait();
    }
}

void Widget::openThreadSlot2()
{
    /*开启一个线程*/
    thread2->start();
    qDebug()<<"主线程id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot2()
{
    /*关闭多线程*/
    qDebug()<<tr("关闭线程2");
    if(thread2->isRunning())
     {
       thread2->closeThread();
       thread2->quit();
       thread2->wait();
    }
}

void Widget::openThreadSlot3()
{
    /*开启一个线程*/
    thread3->start();
    qDebug()<<"主线程id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot3()
{
    /*关闭多线程*/
    qDebug()<<tr("关闭线程3");
    if(thread3->isRunning())
     {
       thread3->closeThread();
       thread3->quit();
       thread3->wait();
    }
}

void Widget::openThreadSlot4()
{
    /*开启一个线程*/
    thread4->start();
    qDebug()<<"主线程id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot4()
{
    /*关闭多线程*/
    qDebug()<<tr("关闭线程4");
    if(thread4->isRunning())
     {
       thread4->closeThread();
       thread4->quit();
       thread4->wait();
    }
}

void Widget::openThreadSlot5()
{
    /*开启一个线程*/
    thread5->start();
    qDebug()<<"主线程id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot5()
{
    /*关闭多线程*/
    qDebug()<<tr("关闭线程5");
    if(thread5->isRunning())
     {
       thread5->closeThread();
       thread5->quit();
       thread5->wait();
    }
}
