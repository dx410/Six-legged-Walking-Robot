#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this); //服务器监听类
       if(!tcpServer->listen(QHostAddress::Any,50007)) //服务器监听本机所有IP的50007端口
        {
            qDebug() << tcpServer->errorString(); //Debug出错误信息
            tcpServer->close(); //关闭监听
        }

        //关联信号，当有新到的连接时，执行槽函数
        connect(tcpServer,SIGNAL(newConnection()),this,SLOT(creatConnection()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::creatConnection() //槽函数:创建连接
{
    tcpSocket = new QTcpSocket(this); //socket类
    //获取监听类里到来的 连接套接字
    tcpSocket = tcpServer->nextPendingConnection();
 //   tcpServer->close(); //关闭监听类
    useConnection(); //在这个函数中使用连接套接字
}

void Widget::useConnection()
{
    //当函数执行到这里时，表明连接已经成功
    //在界面textBrowser中插入纯文本，注意：插入的纯文本类型为QString；
    ui->textBrowser->insertPlainText("connection succeed.\n");

    //当缓冲区有数据可读时，执行槽函数
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(receiveMessage()));

}

void Widget::receiveMessage() //槽函数：接收消息
{
    //读取全部数据； 返回类型为QByteArray
    QByteArray receiveDate = tcpSocket->readAll();
    QString temp = receiveDate;
     ui->textBrowser->insertPlainText(temp);
    if (temp=="data")
    {
        NetData ssData;

       ssData.length = sizeof(NetData);
//        ssData.n1 = 1;
     /*
        QString str="23.0";
        double val=str.toDouble(); //val=23.0
        ssData.d1 = val;
        ssData.d2 = 4.0;
     */
        ssData.d1 = 0;
        ssData.d2 = 0;
        test(ssData.d1,ssData.d2);
        char name[32] = "Say Hello.";
        strncpy(ssData.name, name, 32);
        QByteArray dataArray = QByteArray::fromRawData((char*)&ssData, sizeof(NetData));
        this->tcpSocket->write(dataArray);

    }
}

void Widget::test(double &x, double &y)
{
    QString str1="23.0";
    double val1=str1.toDouble(); //val=23.0
    QString str2="23.0";
    double val2=str2.toDouble(); //val=23.0
    x=val1;
    y=val2;
}
