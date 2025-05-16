/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(118, 75);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        Form->setMaximumSize(QSize(600, 16777215));
        Form->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(Form);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(50, 50));
        label->setMaximumSize(QSize(50, 50));
        label->setStyleSheet(QString::fromUtf8("border-radius: 25px; \n"
"border: 2px solid #ccc;\n"
"border-image: url(:/2.png) 0 0 0 0 stretch stretch;\n"
""));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label->setMargin(0);

        horizontalLayout->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        label_2 = new QLabel(Form);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMaximumSize(QSize(50, 50));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 10pt; \n"
"color: gray;\n"
"background-color:transparent;"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(Form);
        label_3->setObjectName("label_3");
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMaximumSize(QSize(400, 16777215));
        label_3->setStyleSheet(QString::fromUtf8("color:#505050 ;\n"
" background-color: #e0f7e9;  \n"
"border-top-right-radius: 50%;\n"
" border-bottom-left-radius: 15px;\n"
" border-bottom-right-radius: 15px; \n"
" font-size: 10pt;\n"
"padding-left:10;\n"
"\n"
"padding-right:10;"));
        label_3->setWordWrap(true);

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("Form", "00:00", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
