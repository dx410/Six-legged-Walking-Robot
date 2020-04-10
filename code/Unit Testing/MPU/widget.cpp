#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->start(100);
    wiringPiSetup();
    connect(timer,SIGNAL(timeout()),this,SLOT(read_mpu_data()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::read_mpu_data()
{
    float Acc_x,Acc_y,Acc_z;
        float Ax=0, Ay=0, Az=0;
        fd = wiringPiI2CSetup(gy521_Address);    /*Initializes I2C with device Address*/
        MPU_Init();		                 /* Initializes GY521 */

        while(1)
        {
            /*Read raw value of Accelerometer from gy521*/
            Acc_x = read_raw_data(AcX);
            Acc_y = read_raw_data(AcY);
            Acc_z = read_raw_data(AcZ);


            /* Divide raw value by sensitivity scale factor */
            Ax = Acc_x/16384.0;
            Ay = Acc_y/16384.0;
            Az = Acc_z/16384.0;


            qDebug("\n  Ax=%.3f g\tAy=%.3f g\tAz=%.3f g\n",Ax,Ay,Az);
            QString x = QString::number(Ax);
            QString y = QString::number(Ay);
            QString z = QString::number(Az);
            ui->value->setText("Ax="+x+","+"Ay="+y+","+"Az="+z);

            delay(500);
            if (Acc_x>5000 &&Acc_x<16000){
                qDebug("LEAN FORWARD");
                ui->type->setText("LEAN FORWARD");
            }
            else if (Acc_x<-5000&&Acc_x>-16000){
                qDebug("LEAN back");
                ui->type->setText("LEAN back");
                 }
            else if (Acc_y>5000&&Acc_y<16000){
                qDebug("LEAN LEFT");
                ui->type->setText("LEAN LEFT");
                 }
            else if (Acc_y<-5000&&Acc_y>-16000){
                qDebug("LEAN RIGHT");
                 ui->type->setText("LEAN RIGHT");
                 }

            else if (Acc_x<5000&&Acc_x>-5000){
                qDebug("LEVEL");
                ui->type->setText("LEVEL");
                 }
            else if (Acc_y<5000&&Acc_y>-5000){
                qDebug("LEVEL");
                ui->type->setText("LEVEL");
                 }

        }
       // return 0;

}

void Widget::delay(int mSec)
{
    QEventLoop loop;
    QTimer::singleShot(mSec, &loop, SLOT(quit()));
    loop.exec();
}

void Widget::MPU_Init()
{
    wiringPiI2CWriteReg8(fd, SMPLRT_DIV, 0x07);
    wiringPiI2CWriteReg8(fd, PWR_MGMT_1, 0x01);
    wiringPiI2CWriteReg8(fd, CONFIG,0);
    wiringPiI2CWriteReg8(fd, GYRO_CONFIG, 24);
    wiringPiI2CWriteReg8(fd, INT_ENABLE, 0x01);
}

short Widget::read_raw_data(int addr){
    short high_byte,low_byte,value;
    high_byte = wiringPiI2CReadReg8(fd, addr);
    low_byte = wiringPiI2CReadReg8(fd, addr+1);
    value = (high_byte << 8) | low_byte;
    return value;
}








