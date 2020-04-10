/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPlainTextEdit *textBrowser;
    QLabel *hum;
    QLabel *type;
    QLabel *tem;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(365, 350);
        textBrowser = new QPlainTextEdit(Widget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(80, 60, 201, 141));
        hum = new QLabel(Widget);
        hum->setObjectName(QStringLiteral("hum"));
        hum->setGeometry(QRect(90, 260, 91, 16));
        type = new QLabel(Widget);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(90, 290, 111, 16));
        tem = new QLabel(Widget);
        tem->setObjectName(QStringLiteral("tem"));
        tem->setGeometry(QRect(90, 230, 101, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        hum->setText(QApplication::translate("Widget", "***", nullptr));
        type->setText(QApplication::translate("Widget", "***", nullptr));
        tem->setText(QApplication::translate("Widget", "***", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
