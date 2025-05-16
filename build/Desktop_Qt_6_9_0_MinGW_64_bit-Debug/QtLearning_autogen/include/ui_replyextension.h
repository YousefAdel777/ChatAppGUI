/********************************************************************************
** Form generated from reading UI file 'replyextension.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLYEXTENSION_H
#define UI_REPLYEXTENSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_replyExtension
{
public:

    void setupUi(QWidget *replyExtension)
    {
        if (replyExtension->objectName().isEmpty())
            replyExtension->setObjectName("replyExtension");
        replyExtension->resize(400, 300);

        retranslateUi(replyExtension);

        QMetaObject::connectSlotsByName(replyExtension);
    } // setupUi

    void retranslateUi(QWidget *replyExtension)
    {
        replyExtension->setWindowTitle(QCoreApplication::translate("replyExtension", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class replyExtension: public Ui_replyExtension {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLYEXTENSION_H
