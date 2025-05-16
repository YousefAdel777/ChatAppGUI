/********************************************************************************
** Form generated from reading UI file 'mediamessage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAMESSAGE_H
#define UI_MEDIAMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MediaMessage
{
public:

    void setupUi(QWidget *MediaMessage)
    {
        if (MediaMessage->objectName().isEmpty())
            MediaMessage->setObjectName("MediaMessage");
        MediaMessage->resize(400, 300);

        retranslateUi(MediaMessage);

        QMetaObject::connectSlotsByName(MediaMessage);
    } // setupUi

    void retranslateUi(QWidget *MediaMessage)
    {
        MediaMessage->setWindowTitle(QCoreApplication::translate("MediaMessage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MediaMessage: public Ui_MediaMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAMESSAGE_H
