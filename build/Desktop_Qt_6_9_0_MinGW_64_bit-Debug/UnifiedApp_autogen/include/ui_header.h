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
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Name;
    QPushButton *LastSeen;
    QLabel *label;
    QWidget *widget;
    QPushButton *Dots;
    QPushButton *Search;

    void setupUi(QWidget *header)
    {
        if (header->objectName().isEmpty())
            header->setObjectName("header");
        header->resize(1080, 100);
        header->setMaximumSize(QSize(16777215, 100));
        header->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-top-right-radius:25px;"));
        gridLayout = new QGridLayout(header);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        widget_2 = new QWidget(header);
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
        Name->setStyleSheet(QString::fromUtf8("font-size:16pt;\n"
"color:black;\n"
"font-family:Roboto;"));

        verticalLayout->addWidget(Name, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        LastSeen = new QPushButton(layoutWidget);
        LastSeen->setObjectName("LastSeen");
        LastSeen->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        LastSeen->setStyleSheet(QString::fromUtf8("font-size:13pt;\n"
"color:gray;\n"
"font-family:Roboto;"));

        verticalLayout->addWidget(LastSeen, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 75, 75));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/icons/pfp.png")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(widget_2, 0, Qt::AlignmentFlag::AlignLeft);

        widget = new QWidget(header);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(120, 0));
        Dots = new QPushButton(widget);
        Dots->setObjectName("Dots");
        Dots->setGeometry(QRect(80, 20, 32, 32));
        Dots->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/3 dots.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Dots->setIcon(icon);
        Dots->setIconSize(QSize(32, 32));
        Search = new QPushButton(widget);
        Search->setObjectName("Search");
        Search->setGeometry(QRect(10, 20, 32, 32));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Search->setIcon(icon1);
        Search->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(widget, 0, Qt::AlignmentFlag::AlignRight);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(header);

        QMetaObject::connectSlotsByName(header);
    } // setupUi

    void retranslateUi(QWidget *header)
    {
        header->setWindowTitle(QCoreApplication::translate("header", "Form", nullptr));
        Name->setText(QCoreApplication::translate("header", "Mohamed Ramdan", nullptr));
        LastSeen->setText(QCoreApplication::translate("header", "Last seen", nullptr));
        label->setText(QString());
        Dots->setText(QString());
        Search->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class header: public Ui_header {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADER_H
