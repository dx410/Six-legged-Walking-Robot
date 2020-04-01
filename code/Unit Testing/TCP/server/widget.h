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

private slots:
    void creatConnection(); //create new connection
    void useConnection(); //use current connection
    void receiveMessage(); //recieve messages

private:
    Ui::Widget *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
};
#endif // WIDGET_H
