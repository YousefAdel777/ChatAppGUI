/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *container;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchIn;
    QPushButton *searchBtn;

    void setupUi(QWidget *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName("Search");
        Search->resize(419, 67);
        Search->setMaximumSize(QSize(16777215, 67));
        Search->setStyleSheet(QString::fromUtf8("padding-left: 20px;\n"
"padding-right: 20px;\n"
"background: transparent;"));
        gridLayout_2 = new QGridLayout(Search);
        gridLayout_2->setObjectName("gridLayout_2");
        container = new QVBoxLayout();
        container->setSpacing(0);
        container->setObjectName("container");
        widget = new QWidget(Search);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("background-color: #E1ECE1;\n"
"border-radius: 21px;\n"
"padding-left: 20px;\n"
""));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        searchIn = new QLineEdit(widget);
        searchIn->setObjectName("searchIn");
        searchIn->setMinimumSize(QSize(0, 40));
        searchIn->setMaximumSize(QSize(16777215, 40));
        searchIn->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"border-radius: 20px;\n"
""));

        horizontalLayout->addWidget(searchIn);

        searchBtn = new QPushButton(widget);
        searchBtn->setObjectName("searchBtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchBtn->sizePolicy().hasHeightForWidth());
        searchBtn->setSizePolicy(sizePolicy);
        searchBtn->setMinimumSize(QSize(45, 45));
        searchBtn->setMaximumSize(QSize(45, 45));
        searchBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #D3E8D2;\n"
"border-radius: 21px;\n"
"}\n"
"QPushButton#ExcludeContactsBack:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#ExcludeContactsBack:pressed{\n"
"backGround-color: rgb(186, 223, 184);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        searchBtn->setIcon(icon);
        searchBtn->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(searchBtn, 0, Qt::AlignmentFlag::AlignBottom);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        container->addWidget(widget);


        gridLayout_2->addLayout(container, 0, 0, 1, 1);


        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QWidget *Search)
    {
        Search->setWindowTitle(QCoreApplication::translate("Search", "Search", nullptr));
        searchIn->setText(QString());
        searchIn->setPlaceholderText(QCoreApplication::translate("Search", "Search....", nullptr));
        searchBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
