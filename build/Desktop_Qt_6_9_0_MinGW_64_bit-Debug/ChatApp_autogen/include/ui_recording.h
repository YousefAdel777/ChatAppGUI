/********************************************************************************
** Form generated from reading UI file 'recording.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDING_H
#define UI_RECORDING_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Recording
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *deleteBtn;
    QLabel *Timer;
    QPushButton *pauseBtn;

    void setupUi(QWidget *Recording)
    {
        if (Recording->objectName().isEmpty())
            Recording->setObjectName("Recording");
        Recording->resize(929, 70);
        Recording->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        horizontalLayout_3 = new QHBoxLayout(Recording);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(13, 3, 13, 18);
        widget = new QWidget(Recording);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("background-color:#E1ECE1;\n"
"border-radius:21px;"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        deleteBtn = new QPushButton(widget);
        deleteBtn->setObjectName("deleteBtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deleteBtn->sizePolicy().hasHeightForWidth());
        deleteBtn->setSizePolicy(sizePolicy);
        deleteBtn->setMinimumSize(QSize(46, 46));
        deleteBtn->setMaximumSize(QSize(45, 16777215));
        deleteBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        icon.addFile(QString::fromUtf8(":/icons/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        deleteBtn->setIcon(icon);
        deleteBtn->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(deleteBtn);

        Timer = new QLabel(widget);
        Timer->setObjectName("Timer");
        Timer->setMaximumSize(QSize(16777215, 46));
        Timer->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding-top: 5px;\n"
"border-radius: 20px;\n"
"font-size: 11pt;\n"
"color: #424941;"));

        horizontalLayout->addWidget(Timer);

        pauseBtn = new QPushButton(widget);
        pauseBtn->setObjectName("pauseBtn");
        sizePolicy.setHeightForWidth(pauseBtn->sizePolicy().hasHeightForWidth());
        pauseBtn->setSizePolicy(sizePolicy);
        pauseBtn->setMinimumSize(QSize(45, 45));
        pauseBtn->setMaximumSize(QSize(45, 45));
        pauseBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        icon1.addFile(QString::fromUtf8(":/icons/Arrow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pauseBtn->setIcon(icon1);
        pauseBtn->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(pauseBtn);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(widget);


        retranslateUi(Recording);

        QMetaObject::connectSlotsByName(Recording);
    } // setupUi

    void retranslateUi(QWidget *Recording)
    {
        Recording->setWindowTitle(QCoreApplication::translate("Recording", "Form", nullptr));
        deleteBtn->setText(QString());
        Timer->setText(QCoreApplication::translate("Recording", "TextLabel", nullptr));
        pauseBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Recording: public Ui_Recording {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDING_H
