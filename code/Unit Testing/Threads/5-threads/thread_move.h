#ifndef THREAD_MOVE_H
#define THREAD_MOVE_H

#include <QThread>

class MyThread1 : public QThread
{
public:
    MyThread1();
    void closeThread();

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

protected:
    virtual void run();

private:
    volatile bool isStop;       //isStop是易失性变量，需要用volatile进行申明
};

#endif // THREAD_MOVE_H
