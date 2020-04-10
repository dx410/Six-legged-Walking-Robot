#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <wiringPi.h>
#include <softPwm.h>
#include <wiringPiI2C.h>
#include <stdlib.h>
#include <QTimer>
#include <QWidget>

#define pwm_left 4
#define pwm_right 1
#define pwm_tilt 6



class MyThread1 : public QThread
{
public:
    MyThread1();
    void closeThread();

public slots:
        void forward();

protected:
    virtual void run();

private:
    volatile bool isStop;       //isStop是易失性变量，需要用volatile进行申明
};


class MyThread2 : public QThread
{
public:
    MyThread2();
    void closeThread();

public slots:
        void backward();

protected:
    virtual void run();

private:
    volatile bool isStop;       //isStop是易失性变量，需要用volatile进行申明
};


class MyThread3 : public QThread
{
public:
    MyThread3();
    void closeThread();

public slots:
        void left();

protected:
    virtual void run();

private:
    volatile bool isStop;       //isStop是易失性变量，需要用volatile进行申明
};


class MyThread4 : public QThread
{
public:
     MyThread4();
    void closeThread();

public slots:
        void right();

protected:
    virtual void run();

private:
    volatile bool isStop;       //isStop是易失性变量，需要用volatile进行申明
};


class MyThread5 : public QThread
{
public:
    MyThread5();
    void closeThread();

public slots:
        void stop();

protected:
    virtual void run();

private:
    volatile bool isStop;       //isStop是易失性变量，需要用volatile进行申明
};


#endif // MYTHREAD_H
