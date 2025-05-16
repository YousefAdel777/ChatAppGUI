/********************************************************************************
** Form generated from reading UI file 'formskldjf.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSKLDJF_H
#define UI_FORMSKLDJF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Formskldjf
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *Formskldjf)
    {
        if (Formskldjf->objectName().isEmpty())
            Formskldjf->setObjectName("Formskldjf");
        Formskldjf->resize(400, 300);
        Formskldjf->setStyleSheet(QString::fromUtf8("color:black;"));
        horizontalLayoutWidget = new QWidget(Formskldjf);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(70, 100, 161, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton, 0, Qt::AlignmentFlag::AlignLeft);


        retranslateUi(Formskldjf);

        QMetaObject::connectSlotsByName(Formskldjf);
    } // setupUi

    void retranslateUi(QWidget *Formskldjf)
    {
        Formskldjf->setWindowTitle(QCoreApplication::translate("Formskldjf", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Formskldjf", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Formskldjf: public Ui_Formskldjf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSKLDJF_H
