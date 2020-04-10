#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    thread1 = new MyThread1;
    thread2 = new MyThread2;
    thread3 = new MyThread3;
    thread4 = new MyThread4;
    thread5 = new MyThread5;

    tcpServer = new QTcpServer(this); //服务器监听类
       if(!tcpServer->listen(QHostAddress::Any,50007)) //服务器监听本机所有IP的50007端口
        {
            qDebug() << tcpServer->errorString(); //Debug出错误信息
            tcpServer->close(); //关闭监听
        }

        connect(tcpServer,SIGNAL(newConnection()),this,SLOT(creatConnection()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::creatConnection() //槽函数:创建连接
{

    tcpSocket = new QTcpSocket(this); //socket类

    tcpSocket = tcpServer->nextPendingConnection();
    useConnection(); //在这个函数中使用连接套接字
}

void Widget::useConnection()
{
    ui->textBrowser->insertPlainText("connection succeed.\n");

    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(receiveMessage()));

}

void Widget::receiveMessage() //槽函数：接收消息
{

    QByteArray receiveDate = tcpSocket->readAll();
    QString temp = receiveDate;
    if(temp=="forward")
    {
      if(thread2->isRunning())
      {
         closeThreadSlot2();
      }
      if(thread3->isRunning())
      {
         closeThreadSlot3();
      }
      if(thread4->isRunning())
      {
         closeThreadSlot4();
      }
      if(thread5->isRunning())
      {
         closeThreadSlot5();
      }
      openThreadSlot1();
      ui->textBrowser->insertPlainText(temp);
    }
    else if(temp=="backward")
    {
      if(thread1->isRunning())
      {
         closeThreadSlot1();
      }
      if(thread3->isRunning())
      {
         closeThreadSlot3();
      }
      if(thread4->isRunning())
      {
         closeThreadSlot4();
      }
      if(thread5->isRunning())
      {
         closeThreadSlot5();
      }
      openThreadSlot2();
      ui->textBrowser->insertPlainText(temp);
    }
    else if(temp=="left")
    {
      if(thread1->isRunning())
      {
         closeThreadSlot1();
      }
      if(thread2->isRunning())
      {
         closeThreadSlot2();
      }
      if(thread4->isRunning())
      {
         closeThreadSlot4();
      }
      if(thread5->isRunning())
      {
         closeThreadSlot5();
      }
      openThreadSlot3();
      ui->textBrowser->insertPlainText(temp);
    }
    else if(temp=="right")
    {
      if(thread1->isRunning())
      {
         closeThreadSlot1();
      }
      if(thread2->isRunning())
      {
         closeThreadSlot2();
      }
      if(thread3->isRunning())
      {
         closeThreadSlot3();
      }
      if(thread5->isRunning())
      {
         closeThreadSlot5();
      }
      openThreadSlot4();
      ui->textBrowser->insertPlainText(temp);
    }
    else if(temp=="stop")
    {
      if(thread1->isRunning())
      {
         closeThreadSlot1();
      }
      if(thread2->isRunning())
      {
         closeThreadSlot2();
      }
      if(thread3->isRunning())
      {
         closeThreadSlot3();
      }
      if(thread4->isRunning())
      {
         closeThreadSlot4();
      }
      openThreadSlot5();
      ui->textBrowser->insertPlainText(temp);
    }
    else if(temp=="disconnect")
    {
        if(thread1->isRunning())
        {
           closeThreadSlot1();
        }
        if(thread2->isRunning())
        {
           closeThreadSlot2();
        }
        if(thread3->isRunning())
        {
           closeThreadSlot3();
        }
        if(thread4->isRunning())
        {
           closeThreadSlot4();
        }
        if(thread5->isRunning())
        {
           closeThreadSlot5();
        }
        ui->textBrowser->insertPlainText(temp);
    }
    if(temp=="data")
    {
      timer1 = new QTimer(this);
      timer1->start(100);
//      timer2 = new QTimer(this);
//      timer2->start(100);
      wiringPiSetup();
      connect(timer1,SIGNAL(timeout()),this,SLOT(read_mpu_data()));
//      connect(timer2,SIGNAL(timeout()),this,SLOT(data_display(double &x, double &y)));

    }

}


/*          Movement Thread            */
void Widget::openThreadSlot1()
{
    /*开启一个线程*/
    thread1->start();
    qDebug()<<"主线程id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot1()
{
    /*关闭多线程*/
    qDebug()<<tr("关闭线程1");
    if(thread1->isRunning())
     {
       thread1->closeThread();
       thread1->quit();
       thread1->wait();
    }
}

void Widget::openThreadSlot2()
{
    /*开启一个线程*/
    thread2->start();
    qDebug()<<"主线程id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot2()
{
    /*关闭多线程*/
    qDebug()<<tr("关闭线程2");
    if(thread2->isRunning())
     {
       thread2->closeThread();
       thread2->quit();
       thread2->wait();
    }
}

void Widget::openThreadSlot3()
{
    /*开启一个线程*/
    thread3->start();
    qDebug()<<"主线程id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot3()
{
    /*关闭多线程*/
    qDebug()<<tr("关闭线程3");
    if(thread3->isRunning())
     {
       thread3->closeThread();
       thread3->quit();
       thread3->wait();
    }
}

void Widget::openThreadSlot4()
{
    /*开启一个线程*/
    thread4->start();
    qDebug()<<"主线程id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot4()
{
    /*关闭多线程*/
    qDebug()<<tr("关闭线程4");
    if(thread4->isRunning())
     {
       thread4->closeThread();
       thread4->quit();
       thread4->wait();
    }
}

void Widget::openThreadSlot5()
{
    /*开启一个线程*/
    thread5->start();
    qDebug()<<"主线程id："<<QThread::currentThreadId();
}

void Widget::closeThreadSlot5()
{
    /*关闭多线程*/
    qDebug()<<tr("关闭线程5");
    if(thread5->isRunning())
     {
       thread5->closeThread();
       thread5->quit();
       thread5->wait();
    }
}

void Widget::Delay(int mSec)
{
    QEventLoop loop;
    QTimer::singleShot(mSec, &loop, SLOT(quit()));
    loop.exec();
}

/*           MPU            */
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
/*
            char *a;
            QByteArray ba=x.toLatin1();
            a=ba.data();

            ui->value->setText("Ax="+x+","+"Ay="+y+","+"Az="+z);
            this->tcpSocket->write(a);
*/
            Delay(500);
            NetData ssData;
            if (Acc_x>5000 &&Acc_x<16000 ){
                qDebug("LEAN RIGHT");
                ui->type->setText("LEAN RIGHT");

                ssData.length = sizeof(NetData);
                ssData.d1=0;
                ssData.d2=0;
                data_display(ssData.d1,ssData.d2);
                char name[32] = "LEAN RIGHT";
                strncpy(ssData.name, name, 32);
                QByteArray dataArray = QByteArray::fromRawData((char*)&ssData, sizeof(NetData));
                this->tcpSocket->write(dataArray);
            }
            else if (Acc_x<-5000&&Acc_x>-16000){
                qDebug("LEAN LEFT");
                ui->type->setText("LEAN LEFT");

                ssData.length = sizeof(NetData);
                ssData.d1=0;
                ssData.d2=0;
                data_display(ssData.d1,ssData.d2);
                char name[32] = "LEAN LEFT";
                strncpy(ssData.name, name, 32);
                QByteArray dataArray = QByteArray::fromRawData((char*)&ssData, sizeof(NetData));
                this->tcpSocket->write(dataArray);
                 }
            else if (Acc_y>5000&&Acc_y<16000){
                qDebug("LEAN FORWARD");
                ui->type->setText("LEAN FORWARD");

                ssData.length = sizeof(NetData);
                ssData.d1=0;
                ssData.d2=0;
                data_display(ssData.d1,ssData.d2);
                char name[32] = "LEAN FORWARD";
                strncpy(ssData.name, name, 32);
                QByteArray dataArray = QByteArray::fromRawData((char*)&ssData, sizeof(NetData));
                this->tcpSocket->write(dataArray);
                 }
            else if (Acc_y<-5000&&Acc_y>-16000){
                qDebug("LEAN BACK");
                 ui->type->setText("LEAN BACK");

                 ssData.length = sizeof(NetData);
                 ssData.d1=0;
                 ssData.d2=0;
                 data_display(ssData.d1,ssData.d2);
                 char name[32] = "LEAN BACK";
                 strncpy(ssData.name, name, 32);
                 QByteArray dataArray = QByteArray::fromRawData((char*)&ssData, sizeof(NetData));
                 this->tcpSocket->write(dataArray);
                 }

            else if (Acc_x<5000&&Acc_x>-5000){
                qDebug("LEVEL");
                ui->type->setText("LEVEL");

                ssData.length = sizeof(NetData);
                ssData.d1=0;
                ssData.d2=0;
                data_display(ssData.d1,ssData.d2);
                char name[32] = "LEVEL";
                strncpy(ssData.name, name, 32);
                QByteArray dataArray = QByteArray::fromRawData((char*)&ssData, sizeof(NetData));
                this->tcpSocket->write(dataArray);
                 }
            else if (Acc_y<5000&&Acc_y>-5000){
                qDebug("LEVEL");
                ui->type->setText("LEVEL");

                ssData.length = sizeof(NetData);
                ssData.d1=0;
                ssData.d2=0;
                data_display(ssData.d1,ssData.d2);
                char name[32] = "LEVEL";
                strncpy(ssData.name, name, 32);
                QByteArray dataArray = QByteArray::fromRawData((char*)&ssData, sizeof(NetData));
                this->tcpSocket->write(dataArray);
                 }

        }
       // return 0;

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


/*         DHT11            */
void Widget::dht11_init()
{
    qDebug()<<tr("Use GPIO1 to read data!\n");

    if (-1 == wiringPiSetup()) {
    qDebug()<<tr("Setup wiringPi failed!");
    return;
    }

    pinMode(pinNumber, OUTPUT); // set mode to output
    digitalWrite(pinNumber, 1); // output a high level

    qDebug()<<tr("Enter OS-------\n");

//    qtimer->start(100);
}

uint8 Widget::read_dht11_dat()
{
    uint8 crc;
    uint8 i;

    pinMode(pinNumber,OUTPUT); // set mode to output
    digitalWrite(pinNumber, 0); // output a high level
    delay(25);
    digitalWrite(pinNumber, 1); // output a low level
    pinMode(pinNumber, INPUT); // set mode to input
    pullUpDnControl(pinNumber,PUD_UP);

    delayMicroseconds(27);
    if(digitalRead(pinNumber)==0) //SENSOR ANS
    {
        while(!digitalRead(pinNumber)); //wait to high

        for(i=0;i<32;i++)
        {
            while(digitalRead(pinNumber)); //data clock start
            while(!digitalRead(pinNumber)); //data start
            delayMicroseconds(HIGH_TIME);
            databuf*=2;
            if(digitalRead(pinNumber)==1) //1
            {
                databuf++;
            }
        }
        for(i=0;i<8;i++)
        {
            while(digitalRead(pinNumber)); //data clock start
            while(!digitalRead(pinNumber)); //data start
            delayMicroseconds(HIGH_TIME);
            crc*=2;
            if(digitalRead(pinNumber)==1) //1
            {
                crc++;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void Widget::data_display(double &x, double &y)
{
    pinMode(pinNumber,OUTPUT); // set mode to output
    digitalWrite(pinNumber, 1);// output a high level
    //dht_read = false;
    Delay(3000);
    if(read_dht11_dat())
    {
        QString tmp = QString::number((databuf>>8)&0xff, 10);
        QString rh = QString::number((databuf>>24)&0xff, 10);
        ui->tem->setText(tmp);
        ui->hum->setText(rh);

//        NetData ssData;
        double val1=tmp.toDouble();
        double val2=rh.toDouble();
        x = val1;
        y = val2;
//        dht_read = true;
//        printf("Congratulations ! Sensor data read ok!\n");
//        printf("RH:%d.%d\n",(databuf>>24)&0xff,(databuf>>16)&0xff);
//        printf("TMP:%d.%d\n",(databuf>>8)&0xff,databuf&0xff);
        databuf=0;
    }
    else
    {
//        ui->lb_tmpdisplay->setText("Sorry! Sensor dosent ans!");
//        printf("Sorry! Sensor dosent ans!\n");
        databuf=0;
    }
}
