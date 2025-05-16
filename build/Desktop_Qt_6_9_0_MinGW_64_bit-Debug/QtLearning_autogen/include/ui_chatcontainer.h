/********************************************************************************
** Form generated from reading UI file 'chatcontainer.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATCONTAINER_H
#define UI_CHATCONTAINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatContainer
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *ChatContainer)
    {
        if (ChatContainer->objectName().isEmpty())
            ChatContainer->setObjectName("ChatContainer");
        ChatContainer->resize(500, 300);
        gridLayout = new QGridLayout(ChatContainer);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(ChatContainer);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8(" QScrollBar:vertical {\n"
"        background: transparent;\n"
"        width: 6px;\n"
"        margin: 0px;\n"
"    }\n"
"QScrollBar::handle:vertical {\n"
"    background: #333;\n"
"    min-height: 20px;\n"
"    border-radius: 3px;\n"
"}\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #999;\n"
"}\n"
"    QScrollBar::add-line:vertical,\n"
"    QScrollBar::sub-line:vertical {\n"
"        height: 0px;\n"
"    }\n"
"    QScrollBar::add-page:vertical,\n"
"    QScrollBar::sub-page:vertical {\n"
"        background: none;\n"
"    }"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 498, 298));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(ChatContainer);

        QMetaObject::connectSlotsByName(ChatContainer);
    } // setupUi

    void retranslateUi(QWidget *ChatContainer)
    {
        ChatContainer->setWindowTitle(QCoreApplication::translate("ChatContainer", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatContainer: public Ui_ChatContainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATCONTAINER_H
