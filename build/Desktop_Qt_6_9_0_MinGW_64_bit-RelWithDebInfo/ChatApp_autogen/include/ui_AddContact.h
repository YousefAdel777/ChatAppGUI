/********************************************************************************
** Form generated from reading UI file 'addcontact.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCONTACT_H
#define UI_ADDCONTACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddContact
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *phoneIn;
    QLabel *phoneErr;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;

    void setupUi(QWidget *AddContact)
    {
        if (AddContact->objectName().isEmpty())
            AddContact->setObjectName("AddContact");
        AddContact->resize(413, 224);
        AddContact->setStyleSheet(QString::fromUtf8("background-color: white;"));
        verticalLayout = new QVBoxLayout(AddContact);
        verticalLayout->setObjectName("verticalLayout");
        label_3 = new QLabel(AddContact);
        label_3->setObjectName("label_3");
        QFont font;
        font.setBold(true);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
""));

        verticalLayout->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(AddContact);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 50));
        label->setStyleSheet(QString::fromUtf8("padding: 0;"));

        verticalLayout->addWidget(label);

        phoneIn = new QLineEdit(AddContact);
        phoneIn->setObjectName("phoneIn");
        phoneIn->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 8px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));

        verticalLayout->addWidget(phoneIn);

        phoneErr = new QLabel(AddContact);
        phoneErr->setObjectName("phoneErr");
        phoneErr->setStyleSheet(QString::fromUtf8("color: \"red\";\\n\n"
"padding: 0;\\n\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(phoneErr);

        widget = new QWidget(AddContact);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(widget);
        addBtn->setObjectName("addBtn");
        addBtn->setStyleSheet(QString::fromUtf8("border-radius: 10px; \n"
"background-color: \"#D3E8D2\";\n"
"padding: 10px;\n"
"font-weight: 600;"));

        horizontalLayout->addWidget(addBtn);


        verticalLayout->addWidget(widget);


        retranslateUi(AddContact);

        QMetaObject::connectSlotsByName(AddContact);
    } // setupUi

    void retranslateUi(QWidget *AddContact)
    {
        AddContact->setWindowTitle(QCoreApplication::translate("AddContact", "AddContact", nullptr));
        label_3->setText(QCoreApplication::translate("AddContact", "Add Contact", nullptr));
        label->setText(QCoreApplication::translate("AddContact", "Phone Number", nullptr));
        phoneIn->setPlaceholderText(QCoreApplication::translate("AddContact", "Phone Number", nullptr));
        phoneErr->setText(QString());
        addBtn->setText(QCoreApplication::translate("AddContact", "Add Contact", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddContact: public Ui_AddContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONTACT_H
