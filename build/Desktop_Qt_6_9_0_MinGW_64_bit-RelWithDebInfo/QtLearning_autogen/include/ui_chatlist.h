/********************************************************************************
** Form generated from reading UI file 'chatlist.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLIST_H
#define UI_CHATLIST_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatList
{
public:
    QWidget *widget;
    QGroupBox *groupBox;
    QPushButton *StatusWidget;
    QPushButton *newContact;
    QPushButton *ActionList;
    QLineEdit *lineEdit_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *ChatContainer;

    void setupUi(QWidget *ChatList)
    {
        if (ChatList->objectName().isEmpty())
            ChatList->setObjectName("ChatList");
        ChatList->resize(442, 720);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChatList->sizePolicy().hasHeightForWidth());
        ChatList->setSizePolicy(sizePolicy);
        ChatList->setMinimumSize(QSize(442, 720));
        ChatList->setMaximumSize(QSize(442, 720));
        ChatList->setStyleSheet(QString::fromUtf8("background-color:#FBFDF6;"));
        widget = new QWidget(ChatList);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 491, 81));
        widget->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(280, 20, 151, 80));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: \"transparent\";\n"
"border: none;"));
        StatusWidget = new QPushButton(groupBox);
        StatusWidget->setObjectName("StatusWidget");
        StatusWidget->setGeometry(QRect(10, 0, 41, 41));
        StatusWidget->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        StatusWidget->setMouseTracking(true);
        StatusWidget->setStyleSheet(QString::fromUtf8("background-color: \"transparent\";\n"
"border: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/status (2).png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        StatusWidget->setIcon(icon);
        StatusWidget->setIconSize(QSize(20, 20));
        newContact = new QPushButton(groupBox);
        newContact->setObjectName("newContact");
        newContact->setGeometry(QRect(60, 0, 51, 41));
        newContact->setStyleSheet(QString::fromUtf8("background-color: \"transparent\";\n"
"border: none;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/message.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        newContact->setIcon(icon1);
        newContact->setIconSize(QSize(20, 25));
        ActionList = new QPushButton(groupBox);
        ActionList->setObjectName("ActionList");
        ActionList->setGeometry(QRect(110, 0, 51, 41));
        ActionList->setStyleSheet(QString::fromUtf8("background-color: \"transparent\";\n"
"border: none;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/more.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ActionList->setIcon(icon2);
        ActionList->setIconSize(QSize(20, 25));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(10, 20, 241, 41));
        QFont font;
        font.setBold(true);
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: black;\n"
"font-size: 26px;\n"
"background-color: \"transparent\";\n"
"style: \"bold\";"));
        lineEdit_2->setReadOnly(true);
        scrollArea = new QScrollArea(ChatList);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 149, 441, 571));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        scrollArea->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 441, 571));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 20, 441, 551));
        ChatContainer = new QVBoxLayout(verticalLayoutWidget);
        ChatContainer->setObjectName("ChatContainer");
        ChatContainer->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(ChatList);

        QMetaObject::connectSlotsByName(ChatList);
    } // setupUi

    void retranslateUi(QWidget *ChatList)
    {
        ChatList->setWindowTitle(QCoreApplication::translate("ChatList", "Form", nullptr));
        groupBox->setTitle(QString());
        StatusWidget->setText(QString());
        newContact->setText(QString());
        ActionList->setText(QString());
        lineEdit_2->setText(QCoreApplication::translate("ChatList", "WhatsApp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatList: public Ui_ChatList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLIST_H
