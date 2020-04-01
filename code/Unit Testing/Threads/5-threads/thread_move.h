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
    volatile bool isStop;       
};

class MyThread2 : public QThread
{
public:
    MyThread2();
    void closeThread();

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

protected:
    virtual void run();

private:
    volatile bool isStop;       
};

#endif // THREAD_MOVE_H
