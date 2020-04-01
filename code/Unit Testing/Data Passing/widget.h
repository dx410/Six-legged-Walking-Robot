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
     char name[32]; 
    };
    void test(double &x, double &y);

private slots:
    void creatConnection(); 
    void useConnection(); 
    void receiveMessage(); 


private:
    Ui::Widget *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
};
#endif // WIDGET_H
