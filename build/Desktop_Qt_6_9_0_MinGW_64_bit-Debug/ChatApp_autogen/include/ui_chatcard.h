/********************************************************************************
** Form generated from reading UI file 'chatcard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATCARD_H
#define UI_CHATCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatcard
{
public:
    QWidget *widget;
    QLabel *ProfilePic;
    QLabel *message;
    QLabel *name;
    QLabel *time;

    void setupUi(QWidget *chatcard)
    {
        if (chatcard->objectName().isEmpty())
            chatcard->setObjectName("chatcard");
        chatcard->resize(491, 100);
        chatcard->setMinimumSize(QSize(491, 100));
        chatcard->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;\n"
"border-radius: 30px;\n"
"text-align: left;\n"
"color: #000;\n"
""));
        widget = new QWidget(chatcard);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 491, 100));
        widget->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;\n"
"border-radius: 30px;\n"
"text-align: left;\n"
"color: #000;\n"
""));
        ProfilePic = new QLabel(widget);
        ProfilePic->setObjectName("ProfilePic");
        ProfilePic->setGeometry(QRect(20, 20, 60, 60));
        ProfilePic->setStyleSheet(QString::fromUtf8("border-image: 20px;"));
        ProfilePic->setPixmap(QPixmap(QString::fromUtf8(":/images/random.jpg")));
        ProfilePic->setScaledContents(true);
        message = new QLabel(widget);
        message->setObjectName("message");
        message->setGeometry(QRect(100, 50, 171, 31));
        name = new QLabel(widget);
        name->setObjectName("name");
        name->setGeometry(QRect(100, 30, 121, 20));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        name->setFont(font);
        time = new QLabel(widget);
        time->setObjectName("time");
        time->setGeometry(QRect(310, 30, 31, 20));

        retranslateUi(chatcard);

        QMetaObject::connectSlotsByName(chatcard);
    } // setupUi

    void retranslateUi(QWidget *chatcard)
    {
        chatcard->setWindowTitle(QCoreApplication::translate("chatcard", "Form", nullptr));
        ProfilePic->setText(QString());
        message->setText(QCoreApplication::translate("chatcard", "This is some long message", nullptr));
        name->setText(QCoreApplication::translate("chatcard", "Ali Abdelhady", nullptr));
        time->setText(QCoreApplication::translate("chatcard", "08:39", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatcard: public Ui_chatcard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATCARD_H
