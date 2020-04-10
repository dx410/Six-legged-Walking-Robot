#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QByteArray>
#include <QMessageBox>
#include <mythread.h>
#include <QMutex>
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <QString>

/*         MPU          */
#define gy521_Address 0x68
#define PWR_MGMT_1   0x6B
#define SMPLRT_DIV   0x19
#define CONFIG       0x1A
#define GYRO_CONFIG  0x1B
#define INT_ENABLE   0x38
#define AcX 0x3B
#define AcY 0x3D
#define AcZ 0x3F

/*         dht11         */
#define HIGH_TIME 32
typedef unsigned char uint8;
typedef unsigned int  uint16;
typedef unsigned long uint32;


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int fd;
    QTimer *timer1;
//    QTimer *timer2;

    void MPU_Init();
    short read_raw_data(int addr);
    void Delay(int mSec);

    void dht11_init();
    uint8 read_dht11_dat();
     struct NetData
    {
     unsigned int length;
 //    unsigned int n1;
     double d1;
     double d2;
     char name[32]; //这里数组可以，注意如果是指针指向堆空间，堆里数据要自己copy
    };

public slots:
     void read_mpu_data();

     void data_display(double &x, double &y);

private slots:
    void creatConnection(); //创建一个新连接
    void useConnection(); //使用当前连接
    void receiveMessage(); //接收消息

    void openThreadSlot1();
    void closeThreadSlot1();
    void openThreadSlot2();
    void closeThreadSlot2();
    void openThreadSlot3();
    void closeThreadSlot3();
    void openThreadSlot4();
    void closeThreadSlot4();
    void openThreadSlot5();
    void closeThreadSlot5();

private:
    Ui::Widget *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

    MyThread1 *thread1;
    MyThread2 *thread2;
    MyThread3 *thread3;
    MyThread4 *thread4;
    MyThread5 *thread5;

    int pinNumber =3;  //use gpio1 to read data
    uint32 databuf;
//    volatile bool dht_read;

};
#endif // WIDGET_H
