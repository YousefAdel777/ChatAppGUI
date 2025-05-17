/********************************************************************************
** Form generated from reading UI file 'header.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADER_H
#define UI_HEADER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_header
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Name;
    QPushButton *LastSeen;
    QLabel *label;
    QHBoxLayout *searchPlaceholder;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *Search;
    QPushButton *Dots;
    QPushButton *closeSearch;

    void setupUi(QWidget *header)
    {
        if (header->objectName().isEmpty())
            header->setObjectName("header");
        header->resize(1080, 100);
        header->setMaximumSize(QSize(16777215, 100));
        header->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"\n"
"border:0;"));
        gridLayout = new QGridLayout(header);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, -1, 0, -1);
        widget_3 = new QWidget(header);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("background-color:rgb(250,250,250);"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(400, 0));
        layoutWidget = new QWidget(widget_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(100, 0, 291, 76));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Name = new QPushButton(layoutWidget);
        Name->setObjectName("Name");
        Name->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Name->setStyleSheet(QString::fromUtf8("font-size:13pt;\n"
"color:black;\n"
"font-family:Roboto;\n"
"border:0;"));

        verticalLayout->addWidget(Name, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        LastSeen = new QPushButton(layoutWidget);
        LastSeen->setObjectName("LastSeen");
        LastSeen->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        LastSeen->setStyleSheet(QString::fromUtf8("font-size:11pt;\n"
"color:gray;\n"
"font-family:Roboto;"));

        verticalLayout->addWidget(LastSeen, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(18, 8, 60, 60));
        label->setMinimumSize(QSize(0, 0));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/pfp.png")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(widget_2, 0, Qt::AlignmentFlag::AlignLeft);

        searchPlaceholder = new QHBoxLayout();
        searchPlaceholder->setObjectName("searchPlaceholder");

        horizontalLayout->addLayout(searchPlaceholder);

        widget = new QWidget(widget_3);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(120, 0));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        Search = new QPushButton(widget);
        Search->setObjectName("Search");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Search->setIcon(icon);
        Search->setIconSize(QSize(25, 32));

        gridLayout_2->addWidget(Search, 0, 1, 1, 1);

        Dots = new QPushButton(widget);
        Dots->setObjectName("Dots");
        Dots->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/3 dots.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Dots->setIcon(icon1);
        Dots->setIconSize(QSize(25, 32));

        gridLayout_2->addWidget(Dots, 0, 2, 1, 1);

        closeSearch = new QPushButton(widget);
        closeSearch->setObjectName("closeSearch");
        closeSearch->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/close.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        closeSearch->setIcon(icon2);
        closeSearch->setIconSize(QSize(26, 24));

        gridLayout_2->addWidget(closeSearch, 0, 0, 1, 1);


        horizontalLayout->addWidget(widget, 0, Qt::AlignmentFlag::AlignRight);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout->addWidget(widget_3, 0, 0, 1, 1);


        retranslateUi(header);

        QMetaObject::connectSlotsByName(header);
    } // setupUi

    void retranslateUi(QWidget *header)
    {
        header->setWindowTitle(QCoreApplication::translate("header", "Form", nullptr));
        Name->setText(QCoreApplication::translate("header", "Mohamed Ramdan", nullptr));
        LastSeen->setText(QCoreApplication::translate("header", "Last seen", nullptr));
        label->setText(QString());
        Search->setText(QString());
        Dots->setText(QString());
        closeSearch->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class header: public Ui_header {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADER_H
