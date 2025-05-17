/********************************************************************************
** Form generated from reading UI file 'sociallinksdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCIALLINKSDIALOG_H
#define UI_SOCIALLINKSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SocialLinksDialog
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QWidget *linksContainer;
    QVBoxLayout *verticalLayout_3;
    QLabel *noLinks;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addBtn;
    QPushButton *saveBtn;

    void setupUi(QDialog *SocialLinksDialog)
    {
        if (SocialLinksDialog->objectName().isEmpty())
            SocialLinksDialog->setObjectName("SocialLinksDialog");
        SocialLinksDialog->resize(600, 600);
        SocialLinksDialog->setMinimumSize(QSize(0, 600));
        SocialLinksDialog->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"background-color: \"#FBFDF6\";\n"
"padding: 0;"));
        verticalLayout = new QVBoxLayout(SocialLinksDialog);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(SocialLinksDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 600, 600));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 120));
        widget->setMaximumSize(QSize(16777215, 200));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Product Sans Medium")});
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding-left: 5px;\n"
"font-size: 24px;"));

        horizontalLayout->addWidget(label);


        verticalLayout_2->addWidget(widget, 0, Qt::AlignmentFlag::AlignTop);

        linksContainer = new QWidget(scrollAreaWidgetContents);
        linksContainer->setObjectName("linksContainer");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(linksContainer->sizePolicy().hasHeightForWidth());
        linksContainer->setSizePolicy(sizePolicy);
        linksContainer->setMinimumSize(QSize(0, 350));
        verticalLayout_3 = new QVBoxLayout(linksContainer);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetMinAndMaxSize);
        noLinks = new QLabel(linksContainer);
        noLinks->setObjectName("noLinks");
        noLinks->setFont(font);
        noLinks->setStyleSheet(QString::fromUtf8("font-size: 18px;"));
        noLinks->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(noLinks);


        verticalLayout_2->addWidget(linksContainer, 0, Qt::AlignmentFlag::AlignTop);

        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(14);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        addBtn = new QPushButton(widget_3);
        addBtn->setObjectName("addBtn");
        addBtn->setFont(font);
        addBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addBtn->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color: \"#D3E8D2\";\n"
"border: none;\n"
"font-size: 16px;\n"
"border-radius: 16px;"));

        horizontalLayout_3->addWidget(addBtn);

        saveBtn = new QPushButton(widget_3);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setFont(font);
        saveBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        saveBtn->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color: \"#D3E8D2\";\n"
"border: none;\n"
"font-size: 16px;\n"
"border-radius: 16px;"));

        horizontalLayout_3->addWidget(saveBtn);


        horizontalLayout_2->addWidget(widget_3, 0, Qt::AlignmentFlag::AlignRight);


        verticalLayout_2->addWidget(widget_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(SocialLinksDialog);

        QMetaObject::connectSlotsByName(SocialLinksDialog);
    } // setupUi

    void retranslateUi(QDialog *SocialLinksDialog)
    {
        SocialLinksDialog->setWindowTitle(QCoreApplication::translate("SocialLinksDialog", "SocialLinksDialog", nullptr));
        label->setText(QCoreApplication::translate("SocialLinksDialog", "Social Media Links", nullptr));
        noLinks->setText(QCoreApplication::translate("SocialLinksDialog", "Hmm...No Links Found", nullptr));
        addBtn->setText(QCoreApplication::translate("SocialLinksDialog", "Add", nullptr));
        saveBtn->setText(QCoreApplication::translate("SocialLinksDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SocialLinksDialog: public Ui_SocialLinksDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCIALLINKSDIALOG_H
