/********************************************************************************
** Form generated from reading UI file 'About.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *Name;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *PhoneNumber;
    QWidget *Bio;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *About;
    QWidget *widget_3;
    QLabel *commonGroupSectionn;
    QLabel *GroupIcon;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *CummonGroups;
    QWidget *widget_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(500, 720);
        Form->setStyleSheet(QString::fromUtf8("background-color:rgb(225,225,225);"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(Form);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 480, 700));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 170));
        widget->setMaximumSize(QSize(16777215, 170));
        widget->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-top-right-radius:25px;\n"
"border-top-left-radius:25px;"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 9, 91, 91));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/pfp.png")));
        label->setScaledContents(true);
        horizontalLayoutWidget = new QWidget(widget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 100, 471, 35));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Name = new QLabel(horizontalLayoutWidget);
        Name->setObjectName("Name");
        Name->setStyleSheet(QString::fromUtf8("font-size:15pt;\n"
"color:black;\n"
"font-weight:bold;"));

        horizontalLayout->addWidget(Name, 0, Qt::AlignmentFlag::AlignHCenter);

        horizontalLayoutWidget_2 = new QWidget(widget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(0, 130, 471, 32));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        PhoneNumber = new QLabel(horizontalLayoutWidget_2);
        PhoneNumber->setObjectName("PhoneNumber");
        PhoneNumber->setStyleSheet(QString::fromUtf8("font-size:13pt;\n"
"color:gray;"));

        horizontalLayout_3->addWidget(PhoneNumber, 0, Qt::AlignmentFlag::AlignHCenter);


        verticalLayout_2->addWidget(widget);

        Bio = new QWidget(scrollAreaWidgetContents);
        Bio->setObjectName("Bio");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Bio->sizePolicy().hasHeightForWidth());
        Bio->setSizePolicy(sizePolicy);
        Bio->setMinimumSize(QSize(478, 100));
        Bio->setMaximumSize(QSize(16777215, 100));
        Bio->setStyleSheet(QString::fromUtf8("background-color:white;"));
        label_7 = new QLabel(Bio);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 10, 25, 25));
        label_7->setStyleSheet(QString::fromUtf8("font-size:13pt;\n"
"color:gray;"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/icons/info.png")));
        label_7->setScaledContents(true);
        label_8 = new QLabel(Bio);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(49, 6, 114, 33));
        label_8->setStyleSheet(QString::fromUtf8("font-size:15pt;\n"
"color:black;"));
        About = new QLabel(Bio);
        About->setObjectName("About");
        About->setGeometry(QRect(49, 52, 410, 30));
        About->setMinimumSize(QSize(410, 0));
        About->setMaximumSize(QSize(410, 16777215));
        About->setStyleSheet(QString::fromUtf8("font-size:13pt;\n"
"color:gray;"));
        About->setWordWrap(true);

        verticalLayout_2->addWidget(Bio);

        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName("widget_3");
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setMinimumSize(QSize(478, 100));
        widget_3->setMaximumSize(QSize(478, 100));
        widget_3->setStyleSheet(QString::fromUtf8("background-color:white;"));
        commonGroupSectionn = new QLabel(widget_3);
        commonGroupSectionn->setObjectName("commonGroupSectionn");
        commonGroupSectionn->setGeometry(QRect(48, 10, 201, 33));
        commonGroupSectionn->setStyleSheet(QString::fromUtf8("font-size:14pt;\n"
"color:black;"));
        GroupIcon = new QLabel(widget_3);
        GroupIcon->setObjectName("GroupIcon");
        GroupIcon->setGeometry(QRect(10, 14, 25, 25));
        GroupIcon->setStyleSheet(QString::fromUtf8("font-size:13pt;\n"
"color:gray;"));
        GroupIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/group.png")));
        GroupIcon->setScaledContents(true);
        verticalLayoutWidget_3 = new QWidget(widget_3);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(50, 40, 161, 51));
        CummonGroups = new QVBoxLayout(verticalLayoutWidget_3);
        CummonGroups->setObjectName("CummonGroups");
        CummonGroups->setContentsMargins(0, 0, 0, 0);

        verticalLayout_2->addWidget(widget_3);

        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(0, 70));
        widget_2->setMaximumSize(QSize(16777215, 70));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-bottom-right-radius:25px;\n"
"border-bottom-left-radius:25px;"));
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 10, 151, 48));
        pushButton->setStyleSheet(QString::fromUtf8("font-size: 11pt;\n"
"color: rgb(50,50,50);\n"
"background-color:rgb(230,230,230);\n"
"border-radius: 11px;\n"
"padding:4px;\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon);
        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(70, 10, 151, 48));
        pushButton_3->setMaximumSize(QSize(16777215, 70));
        pushButton_3->setStyleSheet(QString::fromUtf8("font-size: 11pt;\n"
"color:white;\n"
"background-color:#EF4A4A;\n"
"border-radius: 11px;\n"
"padding:4px;\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/block.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon1);

        verticalLayout_2->addWidget(widget_2);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QString());
        Name->setText(QCoreApplication::translate("Form", "Mohamed Ramadan", nullptr));
        PhoneNumber->setText(QCoreApplication::translate("Form", "+20 11 15921626", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("Form", "About", nullptr));
        About->setText(QCoreApplication::translate("Form", "3rboka", nullptr));
        commonGroupSectionn->setText(QCoreApplication::translate("Form", "Common Groups", nullptr));
        GroupIcon->setText(QString());
        pushButton->setText(QCoreApplication::translate("Form", "Delete chat", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Form", "Block", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
