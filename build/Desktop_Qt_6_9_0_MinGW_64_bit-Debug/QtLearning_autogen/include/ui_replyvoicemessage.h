/********************************************************************************
** Form generated from reading UI file 'replyvoicemessage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLYVOICEMESSAGE_H
#define UI_REPLYVOICEMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplyVoiceMessage
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QWidget *ReplyContainer;
    QGridLayout *gridLayout;
    QLabel *Sender;
    QHBoxLayout *horizontalLayout_2;
    QLabel *icon;
    QLabel *Duration;

    void setupUi(QWidget *ReplyVoiceMessage)
    {
        if (ReplyVoiceMessage->objectName().isEmpty())
            ReplyVoiceMessage->setObjectName("ReplyVoiceMessage");
        ReplyVoiceMessage->resize(300, 59);
        ReplyVoiceMessage->setStyleSheet(QString::fromUtf8("background-color:#c1e6b8;"));
        gridLayout_2 = new QGridLayout(ReplyVoiceMessage);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(ReplyVoiceMessage);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(214, 240, 209);"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(5, 5, 5, 5);
        ReplyContainer = new QWidget(widget);
        ReplyContainer->setObjectName("ReplyContainer");
        ReplyContainer->setStyleSheet(QString::fromUtf8("QFrame {\n"
"        border-left: 4px solid rgb(67, 67, 67);\n"
"        padding-left: 8px;   \n"
"background-color:#EBF3E9;\n"
"};"));
        gridLayout = new QGridLayout(ReplyContainer);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Sender = new QLabel(ReplyContainer);
        Sender->setObjectName("Sender");
        Sender->setMaximumSize(QSize(16777215, 30));
        Sender->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"font-size:10pt;\n"
"font-weight:bold;"));

        gridLayout->addWidget(Sender, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        icon = new QLabel(ReplyContainer);
        icon->setObjectName("icon");
        icon->setMaximumSize(QSize(40, 25));
        icon->setStyleSheet(QString::fromUtf8("color:rgb(100, 100, 100);\n"
"font-size:8pt;\n"
"font-weight:bold;"));
        icon->setPixmap(QPixmap(QString::fromUtf8(":/Resources/MIC.png")));
        icon->setScaledContents(true);
        icon->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        horizontalLayout_2->addWidget(icon);

        Duration = new QLabel(ReplyContainer);
        Duration->setObjectName("Duration");
        Duration->setStyleSheet(QString::fromUtf8("color:rgb(100, 100, 100);\n"
"font-size:8pt;\n"
"font-weight:bold;\n"
"border:0;"));

        horizontalLayout_2->addWidget(Duration);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        gridLayout_3->addWidget(ReplyContainer, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(ReplyVoiceMessage);

        QMetaObject::connectSlotsByName(ReplyVoiceMessage);
    } // setupUi

    void retranslateUi(QWidget *ReplyVoiceMessage)
    {
        ReplyVoiceMessage->setWindowTitle(QCoreApplication::translate("ReplyVoiceMessage", "Form", nullptr));
        Sender->setText(QCoreApplication::translate("ReplyVoiceMessage", "TextLabel", nullptr));
        icon->setText(QString());
        Duration->setText(QCoreApplication::translate("ReplyVoiceMessage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplyVoiceMessage: public Ui_ReplyVoiceMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLYVOICEMESSAGE_H
