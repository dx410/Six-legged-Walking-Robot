/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QPushButton *stop;
    QPushButton *forward;
    QPushButton *backward;
    QPushButton *right;
    QPushButton *left;
    QPushButton *connectrobot;
    QPushButton *disconnectrobot;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *MPU_state;
    QPlainTextEdit *text;
    QLabel *dht_tem;
    QLabel *dht_hum;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(381, 360);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 180, 351, 121));
        stop = new QPushButton(groupBox);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setGeometry(QRect(50, 40, 50, 50));
        forward = new QPushButton(groupBox);
        forward->setObjectName(QString::fromUtf8("forward"));
        forward->setGeometry(QRect(240, 10, 45, 45));
        backward = new QPushButton(groupBox);
        backward->setObjectName(QString::fromUtf8("backward"));
        backward->setGeometry(QRect(240, 60, 45, 45));
        right = new QPushButton(groupBox);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(290, 60, 45, 45));
        left = new QPushButton(groupBox);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(190, 60, 45, 45));
        connectrobot = new QPushButton(Widget);
        connectrobot->setObjectName(QString::fromUtf8("connectrobot"));
        connectrobot->setGeometry(QRect(60, 320, 75, 23));
        disconnectrobot = new QPushButton(Widget);
        disconnectrobot->setObjectName(QString::fromUtf8("disconnectrobot"));
        disconnectrobot->setGeometry(QRect(220, 320, 75, 23));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 10, 351, 161));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 81, 21));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 71, 16));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 100, 91, 16));
        MPU_state = new QLabel(groupBox_2);
        MPU_state->setObjectName(QString::fromUtf8("MPU_state"));
        MPU_state->setGeometry(QRect(110, 100, 161, 16));
        text = new QPlainTextEdit(groupBox_2);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(50, 130, 251, 21));
        dht_tem = new QLabel(groupBox_2);
        dht_tem->setObjectName(QString::fromUtf8("dht_tem"));
        dht_tem->setGeometry(QRect(110, 20, 71, 16));
        dht_hum = new QLabel(groupBox_2);
        dht_hum->setObjectName(QString::fromUtf8("dht_hum"));
        dht_hum->setGeometry(QRect(110, 60, 81, 16));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 20, 31, 16));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(140, 60, 31, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "Robot Control", nullptr));
        stop->setText(QCoreApplication::translate("Widget", "stop", nullptr));
        forward->setText(QCoreApplication::translate("Widget", "\342\206\221", nullptr));
        backward->setText(QCoreApplication::translate("Widget", "\342\206\223", nullptr));
        right->setText(QCoreApplication::translate("Widget", "\342\206\222", nullptr));
        left->setText(QCoreApplication::translate("Widget", "\342\206\220", nullptr));
        connectrobot->setText(QCoreApplication::translate("Widget", "connect", nullptr));
        disconnectrobot->setText(QCoreApplication::translate("Widget", "disconnect", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "Sensor Data", nullptr));
        label->setText(QCoreApplication::translate("Widget", "temperature:", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "humidity:", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Acclerometer:", nullptr));
        MPU_state->setText(QCoreApplication::translate("Widget", "***", nullptr));
        dht_tem->setText(QCoreApplication::translate("Widget", "***", nullptr));
        dht_hum->setText(QCoreApplication::translate("Widget", "***", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\342\204\203", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
