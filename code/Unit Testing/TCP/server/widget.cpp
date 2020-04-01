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
        /*
           newConnection()  当有连接到来时发送该信号
        */


}

Widget::~Widget()
{
    delete ui;
}

void Widget::creatConnection() //槽函数:创建连接
{
    /*
      注意: TcpServer类和TcpSocket类使用区别
      我们一般使用TcpServer来监听端口；
      使用TcpSocket来与客户端建立连接并传递数据；
    */
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
    /*
       readyRead(); //当有数据要读的时候，会触发该信号
       有数据可读指的是，客户端发送数据已经存在于服务器端的缓冲区中，只要
       缓冲区中存在数据了，该信号就会被触发
    */
}

void Widget::receiveMessage() //槽函数：接收消息
{
    //读取全部数据； 返回类型为QByteArray
    QByteArray receiveDate = tcpSocket->readAll();
    QString temp = receiveDate;
     ui->textBrowser->insertPlainText(temp);
     /*
        插入纯文本是QString类型，我们用temp接收receiceDate；
     */

}
