/********************************************************************************
** Form generated from reading UI file 'messagepopupmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEPOPUPMENU_H
#define UI_MESSAGEPOPUPMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessagePopUpMenu
{
public:

    void setupUi(QWidget *MessagePopUpMenu)
    {
        if (MessagePopUpMenu->objectName().isEmpty())
            MessagePopUpMenu->setObjectName("MessagePopUpMenu");
        MessagePopUpMenu->resize(400, 300);

        retranslateUi(MessagePopUpMenu);

        QMetaObject::connectSlotsByName(MessagePopUpMenu);
    } // setupUi

    void retranslateUi(QWidget *MessagePopUpMenu)
    {
        MessagePopUpMenu->setWindowTitle(QCoreApplication::translate("MessagePopUpMenu", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessagePopUpMenu: public Ui_MessagePopUpMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEPOPUPMENU_H
