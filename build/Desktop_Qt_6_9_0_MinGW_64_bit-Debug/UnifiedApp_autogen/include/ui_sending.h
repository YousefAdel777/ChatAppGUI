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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sending
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *attachBtn;
    QTextEdit *textEdit;
    QPushButton *recordBtn;

    void setupUi(QWidget *Sending)
    {
        if (Sending->objectName().isEmpty())
            Sending->setObjectName("Sending");
        Sending->resize(886, 70);
        Sending->setMaximumSize(QSize(16777215, 93));
        Sending->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
""));
        horizontalLayout_2 = new QHBoxLayout(Sending);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        attachBtn = new QPushButton(Sending);
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
        icon.addFile(QString::fromUtf8(":/icons/icons/attach.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        attachBtn->setIcon(icon);
        attachBtn->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(attachBtn, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignBottom);

        textEdit = new QTextEdit(Sending);
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
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

        horizontalLayout->addWidget(textEdit);

        recordBtn = new QPushButton(Sending);
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
        icon1.addFile(QString::fromUtf8(":/icons/icons/mic.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        recordBtn->setIcon(icon1);
        recordBtn->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(recordBtn, 0, Qt::AlignmentFlag::AlignBottom);


        horizontalLayout_2->addLayout(horizontalLayout);


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
