/********************************************************************************
** Form generated from reading UI file 'ContactWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTWIDGET_H
#define UI_CONTACTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactWidget
{
public:
    QLabel *name;
    QCheckBox *CheckBox;
    QLabel *icon;
    QWidget *widget;

    void setupUi(QWidget *ContactWidget)
    {
        if (ContactWidget->objectName().isEmpty())
            ContactWidget->setObjectName("ContactWidget");
        ContactWidget->resize(340, 50);
        ContactWidget->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"background-color: red;"));
        name = new QLabel(ContactWidget);
        name->setObjectName("name");
        name->setGeometry(QRect(90, 12, 201, 26));
        QFont font;
        font.setPointSize(15);
        name->setFont(font);
        name->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;"));
        CheckBox = new QCheckBox(ContactWidget);
        CheckBox->setObjectName("CheckBox");
        CheckBox->setGeometry(QRect(305, 10, 30, 30));
        QFont font1;
        font1.setPointSize(9);
        CheckBox->setFont(font1);
        CheckBox->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"	background-color:white;\n"
"}\n"
"QCheckBox#CheckBox:indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"	border: 2px solid;\n"
"	border-radius: 12px;\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #4CAF50;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white;\n"
"}\n"
"\n"
"QCheckBox::indicator:indeterminate {\n"
"    background-color: #FFA726;\n"
"}"));
        CheckBox->setIconSize(QSize(40, 40));
        icon = new QLabel(ContactWidget);
        icon->setObjectName("icon");
        icon->setGeometry(QRect(10, 5, 40, 40));
        icon->setStyleSheet(QString::fromUtf8("background-color: white;"));
        icon->setPixmap(QPixmap(QString::fromUtf8(":/icons/icons/pfp.png")));
        icon->setScaledContents(true);
        widget = new QWidget(ContactWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 340, 50));
        widget->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 20px;"));
        widget->raise();
        name->raise();
        CheckBox->raise();
        icon->raise();

        retranslateUi(ContactWidget);

        QMetaObject::connectSlotsByName(ContactWidget);
    } // setupUi

    void retranslateUi(QWidget *ContactWidget)
    {
        ContactWidget->setWindowTitle(QCoreApplication::translate("ContactWidget", "Form", nullptr));
        name->setText(QCoreApplication::translate("ContactWidget", "Metwally", nullptr));
        CheckBox->setText(QString());
        icon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ContactWidget: public Ui_ContactWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTWIDGET_H
