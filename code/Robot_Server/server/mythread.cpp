#include "mythread.h"
#include <QDebug>
#include <QMutex>
#include <QTimer>

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
    wiringPiSetup();
    softPwmCreate(pwm_tilt,15,100);
    softPwmCreate(pwm_left,15,100);
    softPwmCreate(pwm_right,15,100);
    while (!isStop)
    {
        qDebug()<<tr("forward");
        forward();
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
    wiringPiSetup();
    softPwmCreate(pwm_tilt,15,100);
    softPwmCreate(pwm_left,15,100);
    softPwmCreate(pwm_right,15,100);
    while (!isStop)
    {

        qDebug()<<tr("backward");
        backward();
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
    wiringPiSetup();
    softPwmCreate(pwm_tilt,15,100);
    softPwmCreate(pwm_left,15,100);
    softPwmCreate(pwm_right,15,100);
    while (!isStop)
    {

        qDebug()<<tr("left");
        left();
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

    wiringPiSetup();
    softPwmCreate(pwm_tilt,15,100);
    softPwmCreate(pwm_left,15,100);
    softPwmCreate(pwm_right,15,100);
    while (!isStop)
    {

        qDebug()<<tr("right");
        right();
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

    wiringPiSetup();
    softPwmCreate(pwm_tilt,15,100);
    softPwmCreate(pwm_left,15,100);
    softPwmCreate(pwm_right,15,100);

    while (!isStop)
    {

        qDebug()<<tr("stop");
     //  sleep(3);
        stop();
    }
         isStop=false;
}

void MyThread1::forward()
{
    softPwmWrite(pwm_tilt,18);
    QThread::msleep(300);
    softPwmWrite(pwm_left,10);
    QThread::msleep(300);
    softPwmWrite(pwm_tilt,12);
    QThread::msleep(300);
    softPwmWrite(pwm_right,20);
    QThread::msleep(300);
    softPwmWrite(pwm_tilt,15);
    QThread::msleep(300);
    softPwmWrite(pwm_left,15);
   // QThread::msleep(500);
    softPwmWrite(pwm_right,15);
    QThread::msleep(500);

}

void MyThread2::backward()
{
    softPwmWrite(pwm_tilt,18);
    QThread::msleep(300);
    softPwmWrite(pwm_left,20);
    QThread::msleep(300);
    softPwmWrite(pwm_tilt,12);
    QThread::msleep(300);
    softPwmWrite(pwm_right,10);
    QThread::msleep(300);
    softPwmWrite(pwm_tilt,15);
    QThread::msleep(300);
    softPwmWrite(pwm_left,15);
    //QThread::msleep(500);
    softPwmWrite(pwm_right,15);
    QThread::msleep(500);

}

void MyThread3::left()
{
    softPwmWrite(pwm_tilt,18);
    QThread::msleep(300);
    softPwmWrite(pwm_left,20);
    QThread::msleep(300);
    softPwmWrite(pwm_tilt,12);
    QThread::msleep(300);
    softPwmWrite(pwm_right,20);
    QThread::msleep(300);
    softPwmWrite(pwm_tilt,15);
    QThread::msleep(300);
    softPwmWrite(pwm_left,15);
   // QThread::msleep(500);
    softPwmWrite(pwm_right,15);
    QThread::msleep(500);

}

void MyThread4::right()
{
    softPwmWrite(pwm_tilt,18);
    QThread::msleep(300);
    softPwmWrite(pwm_left,10);
    QThread::msleep(300);
    softPwmWrite(pwm_tilt,12);
    QThread::msleep(300);
    softPwmWrite(pwm_right,10);
    QThread::msleep(300);
    softPwmWrite(pwm_tilt,15);
    QThread::msleep(300);
    softPwmWrite(pwm_left,15);
    //QThread::msleep(500);
    softPwmWrite(pwm_right,15);
    QThread::msleep(500);

}


void MyThread5::stop()
{
    softPwmWrite(pwm_tilt,15);
  //  QThread::msleep(800);
    softPwmWrite(pwm_left,15);
  //  QThread::msleep(800);
    softPwmWrite(pwm_right,15);
  //  QThread::msleep(800);

}







