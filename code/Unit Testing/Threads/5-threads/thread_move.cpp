#include "thread_move.h"
#include <QDebug>
#include <QMutex>

MyThread1::MyThread1()
{
    isStop = false;
}

void MyThread1::closeThread()
{
    isStop = true;
}

void MyThread1::run()
{
    while (!isStop)
    {

        qDebug()<<tr("forward");
        sleep(3);
    }
         isStop=false;
}

MyThread2::MyThread2()
{
    isStop = false;
}

void MyThread2::closeThread()
{
    isStop = true;
}

void MyThread2::run()
{
    while (!isStop)
    {

        qDebug()<<tr("backward");
        sleep(3);
    }
         isStop=false;
}

MyThread3::MyThread3()
{
    isStop = false;
}

void MyThread3::closeThread()
{
    isStop = true;
}

void MyThread3::run()
{
    while (!isStop)
    {

        qDebug()<<tr("left");
        sleep(3);
    }
         isStop=false;
}

MyThread4::MyThread4()
{
    isStop = false;
}

void MyThread4::closeThread()
{
    isStop = true;
}

void MyThread4::run()
{
    while (!isStop)
    {

        qDebug()<<tr("right");
        sleep(3);
    }
         isStop=false;
}

MyThread5::MyThread5()
{
    isStop = false;
}

void MyThread5::closeThread()
{
    isStop = true;
}

void MyThread5::run()
{
    while (!isStop)
    {

        qDebug()<<tr("stop");
        sleep(3);
    }
         isStop=false;
}
