/********************************************************************************
** Form generated from reading UI file 'container.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTAINER_H
#define UI_CONTAINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Container
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *Container)
    {
        if (Container->objectName().isEmpty())
            Container->setObjectName("Container");
        Container->resize(560, 400);
        gridLayout = new QGridLayout(Container);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(Container);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 560, 400));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Container);

        QMetaObject::connectSlotsByName(Container);
    } // setupUi

    void retranslateUi(QWidget *Container)
    {
        Container->setWindowTitle(QCoreApplication::translate("Container", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Container: public Ui_Container {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTAINER_H
