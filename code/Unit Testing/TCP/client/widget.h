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

private:
    Ui::Widget *ui;
    QTcpSocket tcpSocket ;
    QString serverAddress;
    int serverPort;

private slots:
    void sendforward();
    void sendbackward();
    void sendleft();
    void sendright();
    void sendstop();
    void connectserver();
    void disconnectserver();


};
#endif // WIDGET_H
