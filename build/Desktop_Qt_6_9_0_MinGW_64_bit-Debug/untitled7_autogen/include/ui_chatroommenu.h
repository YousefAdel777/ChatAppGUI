/********************************************************************************
** Form generated from reading UI file 'chatroommenu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOMMENU_H
#define UI_CHATROOMMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatRoomMenu
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *ViewContact;
    QPushButton *Search;
    QPushButton *Block;
    QPushButton *pushButton;

    void setupUi(QWidget *ChatRoomMenu)
    {
        if (ChatRoomMenu->objectName().isEmpty())
            ChatRoomMenu->setObjectName("ChatRoomMenu");
        ChatRoomMenu->resize(161, 110);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChatRoomMenu->sizePolicy().hasHeightForWidth());
        ChatRoomMenu->setSizePolicy(sizePolicy);
        ChatRoomMenu->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget = new QWidget(ChatRoomMenu);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 161, 118));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ViewContact = new QPushButton(verticalLayoutWidget);
        ViewContact->setObjectName("ViewContact");

        verticalLayout->addWidget(ViewContact);

        Search = new QPushButton(verticalLayoutWidget);
        Search->setObjectName("Search");

        verticalLayout->addWidget(Search);

        Block = new QPushButton(verticalLayoutWidget);
        Block->setObjectName("Block");

        verticalLayout->addWidget(Block);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        retranslateUi(ChatRoomMenu);

        QMetaObject::connectSlotsByName(ChatRoomMenu);
    } // setupUi

    void retranslateUi(QWidget *ChatRoomMenu)
    {
        ChatRoomMenu->setWindowTitle(QCoreApplication::translate("ChatRoomMenu", "Form", nullptr));
        ViewContact->setText(QCoreApplication::translate("ChatRoomMenu", "View Contact", nullptr));
        Search->setText(QCoreApplication::translate("ChatRoomMenu", "Search", nullptr));
        Block->setText(QCoreApplication::translate("ChatRoomMenu", "Block", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatRoomMenu", "Clear Chat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatRoomMenu: public Ui_ChatRoomMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOMMENU_H
