#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->start(100);
        connect(timer,SIGNAL(timeout()),this,SLOT(myprocessing()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::delay(double mSec)
{
    QEventLoop loop;
    QTimer::singleShot(mSec, &loop, SLOT(quit()));
    loop.exec();
}

void Widget::myprocessing()
{
    ui->label->setText("tmp");
    delay(3000);
    qDebug()<<"hi"<<endl;
    ui->label->setText("hi");
    qDebug()<<"ha"<<endl;
    delay(3000);
    ui->label->setText("he");
    delay(3000);
}
