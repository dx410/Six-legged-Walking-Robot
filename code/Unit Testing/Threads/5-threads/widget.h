#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QByteArray>
#include <QMessageBox>
#include <thread_move.h>
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

};
#endif // WIDGET_H
