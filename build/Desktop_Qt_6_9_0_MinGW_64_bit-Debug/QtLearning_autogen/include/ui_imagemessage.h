/********************************************************************************
** Form generated from reading UI file 'imagemessage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEMESSAGE_H
#define UI_IMAGEMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageMessage
{
public:
    QLabel *image;

    void setupUi(QWidget *ImageMessage)
    {
        if (ImageMessage->objectName().isEmpty())
            ImageMessage->setObjectName("ImageMessage");
        ImageMessage->resize(302, 302);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageMessage->sizePolicy().hasHeightForWidth());
        ImageMessage->setSizePolicy(sizePolicy);
        ImageMessage->setAutoFillBackground(false);
        image = new QLabel(ImageMessage);
        image->setObjectName("image");
        image->setGeometry(QRect(110, 140, 63, 20));

        retranslateUi(ImageMessage);

        QMetaObject::connectSlotsByName(ImageMessage);
    } // setupUi

    void retranslateUi(QWidget *ImageMessage)
    {
        ImageMessage->setWindowTitle(QCoreApplication::translate("ImageMessage", "Form", nullptr));
        image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageMessage: public Ui_ImageMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEMESSAGE_H
