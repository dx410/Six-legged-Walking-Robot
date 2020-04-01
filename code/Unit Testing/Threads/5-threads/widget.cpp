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
   
    thread1->start();
    qDebug()<<"thread id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot1()
{
    
    qDebug()<<tr("close thread1");
    if(thread1->isRunning())
     {
       thread1->closeThread();
       thread1->quit();
       thread1->wait();
    }
}

void Widget::openThreadSlot2()
{
    
    thread2->start();
    qDebug()<<"thread id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot2()
{
   
    qDebug()<<tr("close thread2");
    if(thread2->isRunning())
     {
       thread2->closeThread();
       thread2->quit();
       thread2->wait();
    }
}

void Widget::openThreadSlot3()
{
    
    thread3->start();
    qDebug()<<"thread id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot3()
{
    
    qDebug()<<tr("close thread3");
    if(thread3->isRunning())
     {
       thread3->closeThread();
       thread3->quit();
       thread3->wait();
    }
}

void Widget::openThreadSlot4()
{
    
    thread4->start();
    qDebug()<<"thread id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot4()
{
    
    qDebug()<<tr("close thread4");
    if(thread4->isRunning())
     {
       thread4->closeThread();
       thread4->quit();
       thread4->wait();
    }
}

void Widget::openThreadSlot5()
{
   
    thread5->start();
    qDebug()<<"thread id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot5()
{
    
    qDebug()<<tr("close thread5");
    if(thread5->isRunning())
     {
       thread5->closeThread();
       thread5->quit();
       thread5->wait();
    }
}
