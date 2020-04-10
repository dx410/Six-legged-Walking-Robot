#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <wiringPiI2C.h>
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <QTimer>
#include <QtDebug>


#define gy521_Address 0x68

#define PWR_MGMT_1   0x6B
#define SMPLRT_DIV   0x19
#define CONFIG       0x1A
#define GYRO_CONFIG  0x1B
#define INT_ENABLE   0x38
#define AcX 0x3B
#define AcY 0x3D
#define AcZ 0x3F

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
    QTimer *timer;
    void MPU_Init();
    short read_raw_data(int addr);
    void delay(int mSec);


public slots:
     void read_mpu_data();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
