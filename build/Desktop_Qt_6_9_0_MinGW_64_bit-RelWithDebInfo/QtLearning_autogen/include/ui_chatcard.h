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
    QLabel *name;

    void setupUi(QWidget *chatcard)
    {
        if (chatcard->objectName().isEmpty())
            chatcard->setObjectName("chatcard");
        chatcard->resize(354, 83);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chatcard->sizePolicy().hasHeightForWidth());
        chatcard->setSizePolicy(sizePolicy);
        chatcard->setMinimumSize(QSize(354, 83));
        chatcard->setMaximumSize(QSize(354, 83));
        chatcard->setStyleSheet(QString::fromUtf8("background-color: #D3E8D2;\n"
"border: none;\n"
"border-radius: 30px;\n"
"text-align: left;\n"
"color: #000;\n"
""));
        widget = new QWidget(chatcard);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 351, 81));
        widget->setMinimumSize(QSize(0, 81));
        widget->setMaximumSize(QSize(16777215, 81));
        widget->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-radius: 30px;\n"
"text-align: left;\n"
"color: #000;\n"
""));
        ProfilePic = new QLabel(widget);
        ProfilePic->setObjectName("ProfilePic");
        ProfilePic->setGeometry(QRect(20, 18, 50, 50));
        ProfilePic->setStyleSheet(QString::fromUtf8("border-image: 20px;"));
        ProfilePic->setPixmap(QPixmap(QString::fromUtf8(":/images/random.jpg")));
        ProfilePic->setScaledContents(true);
        name = new QLabel(widget);
        name->setObjectName("name");
        name->setGeometry(QRect(100, 34, 251, 20));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        name->setFont(font);

        retranslateUi(chatcard);

        QMetaObject::connectSlotsByName(chatcard);
    } // setupUi

    void retranslateUi(QWidget *chatcard)
    {
        chatcard->setWindowTitle(QCoreApplication::translate("chatcard", "Form", nullptr));
        ProfilePic->setText(QString());
        name->setText(QCoreApplication::translate("chatcard", "Ali Abdelhady", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatcard: public Ui_chatcard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATCARD_H
