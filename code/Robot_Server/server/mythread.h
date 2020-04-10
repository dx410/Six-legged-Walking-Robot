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
    volatile bool isStop;       
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
    volatile bool isStop;       
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
    volatile bool isStop;       
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
    volatile bool isStop;       
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
    volatile bool isStop;       
};


#endif // MYTHREAD_H
