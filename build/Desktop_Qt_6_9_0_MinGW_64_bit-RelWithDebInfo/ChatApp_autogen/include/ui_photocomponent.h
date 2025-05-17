/********************************************************************************
** Form generated from reading UI file 'photocomponent.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOCOMPONENT_H
#define UI_PHOTOCOMPONENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhotoComponent
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QLabel *name;
    QPushButton *Remove;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *PhotoContainer;

    void setupUi(QWidget *PhotoComponent)
    {
        if (PhotoComponent->objectName().isEmpty())
            PhotoComponent->setObjectName("PhotoComponent");
        PhotoComponent->resize(227, 234);
        gridLayout = new QGridLayout(PhotoComponent);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(3, 3, 3, 3);
        widget = new QWidget(PhotoComponent);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(221, 228));
        widget->setStyleSheet(QString::fromUtf8("background-color:#535353;\n"
"border-radius:15px;\n"
""));
        name = new QLabel(widget);
        name->setObjectName("name");
        name->setGeometry(QRect(10, 190, 201, 30));
        name->setMaximumSize(QSize(16777215, 30));
        name->setStyleSheet(QString::fromUtf8("border:0;\n"
"color:white;\n"
"font-size:9pt;"));
        Remove = new QPushButton(widget);
        Remove->setObjectName("Remove");
        Remove->setGeometry(QRect(180, 0, 41, 31));
        Remove->setStyleSheet(QString::fromUtf8("background-color:rgb(70,70,70);\n"
"border-radius:15;\n"
"border:0;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Remove->setIcon(icon);
        Remove->setIconSize(QSize(20, 20));
        horizontalLayoutWidget = new QWidget(widget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 29, 221, 171));
        PhotoContainer = new QHBoxLayout(horizontalLayoutWidget);
        PhotoContainer->setObjectName("PhotoContainer");
        PhotoContainer->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(PhotoComponent);

        QMetaObject::connectSlotsByName(PhotoComponent);
    } // setupUi

    void retranslateUi(QWidget *PhotoComponent)
    {
        PhotoComponent->setWindowTitle(QCoreApplication::translate("PhotoComponent", "Form", nullptr));
        name->setText(QCoreApplication::translate("PhotoComponent", "myVoice.wav", nullptr));
        Remove->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PhotoComponent: public Ui_PhotoComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOCOMPONENT_H
