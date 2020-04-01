#include "mythread.h"
#include <QDebug>
#include <QMutex>

MyThread::MyThread()
{
    isStop = false;
}

void MyThread::closeThread()
{
    isStop = true;
}

void MyThread::run()
{
    while (!isStop)
    {

        qDebug()<<tr("mythread QThread::currentThreadId()==")<<QThread::currentThreadId();
        sleep(3);
    }
         isStop=false;
}
