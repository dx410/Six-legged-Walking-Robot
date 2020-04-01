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

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void creatConnection(); //创建一个新连接
    void useConnection(); //使用当前连接
    void receiveMessage(); //接收消息

    void openThreadBtnSlot();
    void closeThreadBtnSlot();
    void finishedThreadBtnSlot();

private:
    Ui::Widget *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

    MyThread *thread1;
};
#endif // WIDGET_H
