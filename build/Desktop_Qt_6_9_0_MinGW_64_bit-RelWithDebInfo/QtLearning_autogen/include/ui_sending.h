/********************************************************************************
** Form generated from reading UI file 'sending.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDING_H
#define UI_SENDING_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sending
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *container;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *attachBtn;
    QTextEdit *textEdit;
    QPushButton *recordBtn;

    void setupUi(QWidget *Sending)
    {
        if (Sending->objectName().isEmpty())
            Sending->setObjectName("Sending");
        Sending->resize(886, 71);
        Sending->setMaximumSize(QSize(16777215, 93));
        Sending->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        horizontalLayout_2 = new QHBoxLayout(Sending);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(12, 3, 12, 18);
        container = new QVBoxLayout();
        container->setSpacing(0);
        container->setObjectName("container");
        widget = new QWidget(Sending);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("background-color: #E1ECE1;\n"
"border-radius: 21px;\n"
""));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        attachBtn = new QPushButton(widget);
        attachBtn->setObjectName("attachBtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(attachBtn->sizePolicy().hasHeightForWidth());
        attachBtn->setSizePolicy(sizePolicy);
        attachBtn->setMinimumSize(QSize(46, 46));
        attachBtn->setMaximumSize(QSize(45, 16777215));
        attachBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: \"#E1ECE1\";\n"
"border-top-left-radius: 20px;\n"
"border-bottom-left-radius: 20px;\n"
"}\n"
"QPushButton#ExcludeContactsBack:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#ExcludeContactsBack:pressed{\n"
"backGround-color: rgb(186, 223, 184);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/attach.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        attachBtn->setIcon(icon);
        attachBtn->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(attachBtn, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignBottom);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName("textEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMaximumSize(QSize(16777215, 46));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"background-color: \"#E1ECE1\";\n"
"padding-top: 5px;\n"
"border-radius: 20px;\n"
"font-size: 11pt;\n"
"color: #424941;\n"
"}\n"
"QScrollBar:vertical {\n"
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
        textEdit->setFrameShape(QFrame::Shape::NoFrame);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

        horizontalLayout->addWidget(textEdit);

        recordBtn = new QPushButton(widget);
        recordBtn->setObjectName("recordBtn");
        sizePolicy.setHeightForWidth(recordBtn->sizePolicy().hasHeightForWidth());
        recordBtn->setSizePolicy(sizePolicy);
        recordBtn->setMinimumSize(QSize(45, 45));
        recordBtn->setMaximumSize(QSize(45, 45));
        recordBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #D3E8D2;\n"
"border-radius: 21px;\n"
"}\n"
"QPushButton#ExcludeContactsBack:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#ExcludeContactsBack:pressed{\n"
"backGround-color: rgb(186, 223, 184);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/mic.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        recordBtn->setIcon(icon1);
        recordBtn->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(recordBtn, 0, Qt::AlignmentFlag::AlignBottom);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        container->addWidget(widget);


        horizontalLayout_2->addLayout(container);


        retranslateUi(Sending);

        QMetaObject::connectSlotsByName(Sending);
    } // setupUi

    void retranslateUi(QWidget *Sending)
    {
        Sending->setWindowTitle(QCoreApplication::translate("Sending", "Form", nullptr));
        attachBtn->setText(QString());
        textEdit->setPlaceholderText(QCoreApplication::translate("Sending", "Type a message", nullptr));
        recordBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Sending: public Ui_Sending {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDING_H
