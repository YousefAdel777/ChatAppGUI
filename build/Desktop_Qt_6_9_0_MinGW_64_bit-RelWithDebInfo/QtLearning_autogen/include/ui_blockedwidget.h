/********************************************************************************
** Form generated from reading UI file 'blockedwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKEDWIDGET_H
#define UI_BLOCKEDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlockedWidget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QLabel *label;

    void setupUi(QWidget *BlockedWidget)
    {
        if (BlockedWidget->objectName().isEmpty())
            BlockedWidget->setObjectName("BlockedWidget");
        BlockedWidget->resize(651, 65);
        gridLayout = new QGridLayout(BlockedWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(BlockedWidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 66));
        widget->setMaximumSize(QSize(16777215, 66));
        widget->setStyleSheet(QString::fromUtf8("background-color: #2b2b2b; color: white; padding: 5px;\n"
""));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(400, 0));
        widget_2->setMaximumSize(QSize(400, 16777215));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(102, 0, 205, 44));

        horizontalLayout_2->addWidget(widget_2, 0, Qt::AlignmentFlag::AlignHCenter);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(BlockedWidget);

        QMetaObject::connectSlotsByName(BlockedWidget);
    } // setupUi

    void retranslateUi(QWidget *BlockedWidget)
    {
        BlockedWidget->setWindowTitle(QCoreApplication::translate("BlockedWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("BlockedWidget", "This Contact Blocked You.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BlockedWidget: public Ui_BlockedWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKEDWIDGET_H
