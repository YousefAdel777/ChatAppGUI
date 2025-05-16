/********************************************************************************
** Form generated from reading UI file 'forwardmessageextension.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORWARDMESSAGEEXTENSION_H
#define UI_FORWARDMESSAGEEXTENSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForwardMessageExtension
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *ForwardMessageExtension)
    {
        if (ForwardMessageExtension->objectName().isEmpty())
            ForwardMessageExtension->setObjectName("ForwardMessageExtension");
        ForwardMessageExtension->resize(400, 300);
        verticalLayoutWidget = new QWidget(ForwardMessageExtension);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("background-color:red;"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(ForwardMessageExtension);

        QMetaObject::connectSlotsByName(ForwardMessageExtension);
    } // setupUi

    void retranslateUi(QWidget *ForwardMessageExtension)
    {
        ForwardMessageExtension->setWindowTitle(QCoreApplication::translate("ForwardMessageExtension", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("ForwardMessageExtension", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForwardMessageExtension: public Ui_ForwardMessageExtension {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORWARDMESSAGEEXTENSION_H
