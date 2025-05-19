/********************************************************************************
** Form generated from reading UI file 'blockerwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKERWIDGET_H
#define UI_BLOCKERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlockerWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *BlockerWidget)
    {
        if (BlockerWidget->objectName().isEmpty())
            BlockerWidget->setObjectName("BlockerWidget");
        BlockerWidget->resize(651, 66);
        BlockerWidget->setMinimumSize(QSize(0, 66));
        BlockerWidget->setMaximumSize(QSize(16777215, 66));
        horizontalLayout = new QHBoxLayout(BlockerWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(BlockerWidget);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("background-color: #2b2b2b; color: white; padding: 5px;\n"
""));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(300, 0));
        widget_2->setMaximumSize(QSize(300, 16777215));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 205, 44));
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(161, 8, 151, 30));
        pushButton->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:transparent;\n"
"color:#00ff99;\n"
"font-weight:bold;\n"
"border:0;\n"
"}\n"
"QWidget:hover{\n"
"color: gray;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(widget_2, 0, Qt::AlignmentFlag::AlignHCenter);


        horizontalLayout->addWidget(widget);


        retranslateUi(BlockerWidget);

        QMetaObject::connectSlotsByName(BlockerWidget);
    } // setupUi

    void retranslateUi(QWidget *BlockerWidget)
    {
        BlockerWidget->setWindowTitle(QCoreApplication::translate("BlockerWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("BlockerWidget", "You Blocked This Contact.", nullptr));
        pushButton->setText(QCoreApplication::translate("BlockerWidget", "Click to unblock", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BlockerWidget: public Ui_BlockerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKERWIDGET_H
