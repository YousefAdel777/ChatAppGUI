/********************************************************************************
** Form generated from reading UI file 'testws.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWS_H
#define UI_TESTWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWs
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *chatBox;
    QLabel *ChatId;
    QLineEdit *chatIdEdit;
    QLabel *label;
    QLineEdit *messageEdit;
    QPushButton *sendButton;

    void setupUi(QWidget *TestWs)
    {
        if (TestWs->objectName().isEmpty())
            TestWs->setObjectName("TestWs");
        TestWs->resize(800, 561);
        verticalLayout = new QVBoxLayout(TestWs);
        verticalLayout->setObjectName("verticalLayout");
        chatBox = new QTextEdit(TestWs);
        chatBox->setObjectName("chatBox");

        verticalLayout->addWidget(chatBox);

        ChatId = new QLabel(TestWs);
        ChatId->setObjectName("ChatId");

        verticalLayout->addWidget(ChatId);

        chatIdEdit = new QLineEdit(TestWs);
        chatIdEdit->setObjectName("chatIdEdit");

        verticalLayout->addWidget(chatIdEdit);

        label = new QLabel(TestWs);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        messageEdit = new QLineEdit(TestWs);
        messageEdit->setObjectName("messageEdit");

        verticalLayout->addWidget(messageEdit);

        sendButton = new QPushButton(TestWs);
        sendButton->setObjectName("sendButton");

        verticalLayout->addWidget(sendButton);


        retranslateUi(TestWs);

        QMetaObject::connectSlotsByName(TestWs);
    } // setupUi

    void retranslateUi(QWidget *TestWs)
    {
        TestWs->setWindowTitle(QCoreApplication::translate("TestWs", "TestWs", nullptr));
        ChatId->setText(QCoreApplication::translate("TestWs", "Chat Id", nullptr));
        label->setText(QCoreApplication::translate("TestWs", "Message ", nullptr));
        sendButton->setText(QCoreApplication::translate("TestWs", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestWs: public Ui_TestWs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWS_H
