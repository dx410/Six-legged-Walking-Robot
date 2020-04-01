#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QByteArray>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    struct NetData
    {
     unsigned int length;
//     unsigned int n1;
     double d1;
     double d2;
     char name[32]; //这里数组可以，注意如果是指针指向堆空间，堆里数据要自己copy
    };
    void test(double &x, double &y);

private slots:
    void creatConnection(); //创建一个新连接
    void useConnection(); //使用当前连接
    void receiveMessage(); //接收消息


private:
    Ui::Widget *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
};
#endif // WIDGET_H
