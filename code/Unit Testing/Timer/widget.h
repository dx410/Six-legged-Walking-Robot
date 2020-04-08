#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QtDebug>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void delay(int mSec);
     QTimer *timer;

protected slots:
    void myprocessing();

private:
    Ui::Widget *ui;
};


#endif // WIDGET_H
