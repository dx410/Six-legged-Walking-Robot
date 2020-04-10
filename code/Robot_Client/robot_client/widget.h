#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <qapplication.h>
#include <qfont.h>
#include <QTextEdit>
#include <QMessageBox>
#include <QDebug>
#include <QTcpSocket>
#include <QByteArray>

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
     double d1;
     double d2;
     char name[32];      //  array
    };


private:
    Ui::Widget *ui;
    QTcpSocket *tcpSocket ;
    QString serverAddress;
    int serverPort;

public slots:
    void sendforward();
    void sendbackward();
    void sendleft();
    void sendright();
    void sendstop();
    void connectserver();
    void disconnectserver();

    void readdata();
};
#endif // WIDGET_H
