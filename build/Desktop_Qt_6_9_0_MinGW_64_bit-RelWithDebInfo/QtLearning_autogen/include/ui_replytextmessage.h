/********************************************************************************
** Form generated from reading UI file 'replytextmessage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLYTEXTMESSAGE_H
#define UI_REPLYTEXTMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplyTextMessage
{
public:
    QGridLayout *containerLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *ReplyContainer;
    QGridLayout *gridLayout;
    QLabel *Sender;
    QLabel *Content;

    void setupUi(QWidget *ReplyTextMessage)
    {
        if (ReplyTextMessage->objectName().isEmpty())
            ReplyTextMessage->setObjectName("ReplyTextMessage");
        ReplyTextMessage->resize(365, 64);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ReplyTextMessage->sizePolicy().hasHeightForWidth());
        ReplyTextMessage->setSizePolicy(sizePolicy);
        ReplyTextMessage->setMaximumSize(QSize(16777215, 150));
        ReplyTextMessage->setStyleSheet(QString::fromUtf8("background-color:#c1e6b8;"));
        containerLayout = new QGridLayout(ReplyTextMessage);
        containerLayout->setObjectName("containerLayout");
        containerLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(ReplyTextMessage);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(214, 240, 209);\n"
"border-top-left-radius: 15px;"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        ReplyContainer = new QWidget(widget);
        ReplyContainer->setObjectName("ReplyContainer");
        ReplyContainer->setStyleSheet(QString::fromUtf8("QWidget#ReplyContainer {\n"
"border-radius:0;\n"
"    border-left: 4px solid rgb(67, 67, 67);\n"
"    background-color: #EBF3E9;\n"
"}\n"
"\n"
"QWidget#ReplyContainer QLabel {\n"
"    background: transparent; \n"
"    padding-left: 8px;\n"
"    /* important: so labels don\342\200\231t paint over */\n"
"    color: black;\n"
"}\n"
"\n"
"QWidget#ReplyContainer:hover {\n"
"    background-color: white;\n"
"}\n"
"\n"
"QWidget#ReplyContainer:hover QLabel {\n"
"    /* labels stay transparent, text turns white */\n"
"    color: white;\n"
"}\n"
""));
        gridLayout = new QGridLayout(ReplyContainer);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Sender = new QLabel(ReplyContainer);
        Sender->setObjectName("Sender");
        Sender->setMaximumSize(QSize(16777215, 30));
        Sender->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"font-size:10pt;\n"
"border-radius:15px;\n"
"border-top-right-radius:1px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(Sender, 0, 0, 1, 1);

        Content = new QLabel(ReplyContainer);
        Content->setObjectName("Content");
        Content->setMinimumSize(QSize(0, 30));
        Content->setStyleSheet(QString::fromUtf8("color:rgb(100, 100, 100);\n"
"font-size:8pt;\n"
"border-radius:0;\n"
"font-weight:bold;"));

        gridLayout->addWidget(Content, 1, 0, 1, 1);


        verticalLayout->addWidget(ReplyContainer);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        containerLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(ReplyTextMessage);

        QMetaObject::connectSlotsByName(ReplyTextMessage);
    } // setupUi

    void retranslateUi(QWidget *ReplyTextMessage)
    {
        ReplyTextMessage->setWindowTitle(QCoreApplication::translate("ReplyTextMessage", "Form", nullptr));
        Sender->setText(QCoreApplication::translate("ReplyTextMessage", "TextLabel", nullptr));
        Content->setText(QCoreApplication::translate("ReplyTextMessage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplyTextMessage: public Ui_ReplyTextMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLYTEXTMESSAGE_H
