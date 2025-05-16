/********************************************************************************
** Form generated from reading UI file 'replyimagemessage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLYIMAGEMESSAGE_H
#define UI_REPLYIMAGEMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplyImageMessage
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QWidget *ReplyContainer;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *Sender;
    QLabel *Content;

    void setupUi(QWidget *ReplyImageMessage)
    {
        if (ReplyImageMessage->objectName().isEmpty())
            ReplyImageMessage->setObjectName("ReplyImageMessage");
        ReplyImageMessage->resize(237, 62);
        ReplyImageMessage->setMaximumSize(QSize(16777215, 112));
        ReplyImageMessage->setStyleSheet(QString::fromUtf8("background-color:rgb(214, 240, 209);"));
        gridLayout = new QGridLayout(ReplyImageMessage);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(ReplyImageMessage);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(214, 240, 209);"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        ReplyContainer = new QWidget(widget);
        ReplyContainer->setObjectName("ReplyContainer");
        ReplyContainer->setStyleSheet(QString::fromUtf8("\n"
"        border-left: 4px solid rgb(67, 67, 67);\n"
"        padding-left: 8px;   \n"
"		background-color:#EBF3E9;"));
        horizontalLayout_4 = new QHBoxLayout(ReplyContainer);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        Sender = new QLabel(ReplyContainer);
        Sender->setObjectName("Sender");
        Sender->setMaximumSize(QSize(16777215, 30));
        Sender->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"font-size:10pt;\n"
"font-weight:bold;"));

        verticalLayout_2->addWidget(Sender);

        Content = new QLabel(ReplyContainer);
        Content->setObjectName("Content");
        Content->setMaximumSize(QSize(16777215, 100));
        Content->setStyleSheet(QString::fromUtf8("color:rgb(100, 100, 100);\n"
"font-size:8pt;\n"
"font-weight:bold;\n"
""));

        verticalLayout_2->addWidget(Content);


        horizontalLayout_4->addLayout(verticalLayout_2);


        gridLayout_2->addWidget(ReplyContainer, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(ReplyImageMessage);

        QMetaObject::connectSlotsByName(ReplyImageMessage);
    } // setupUi

    void retranslateUi(QWidget *ReplyImageMessage)
    {
        ReplyImageMessage->setWindowTitle(QCoreApplication::translate("ReplyImageMessage", "Form", nullptr));
        Sender->setText(QCoreApplication::translate("ReplyImageMessage", "TextLabel", nullptr));
        Content->setText(QCoreApplication::translate("ReplyImageMessage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplyImageMessage: public Ui_ReplyImageMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLYIMAGEMESSAGE_H
