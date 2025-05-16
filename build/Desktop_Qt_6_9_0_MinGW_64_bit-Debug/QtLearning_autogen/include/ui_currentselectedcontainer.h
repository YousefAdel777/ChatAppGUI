/********************************************************************************
** Form generated from reading UI file 'currentselectedcontainer.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENTSELECTEDCONTAINER_H
#define UI_CURRENTSELECTEDCONTAINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurrentSelectedContainer
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *CurrentSelectedContainer)
    {
        if (CurrentSelectedContainer->objectName().isEmpty())
            CurrentSelectedContainer->setObjectName("CurrentSelectedContainer");
        CurrentSelectedContainer->resize(791, 260);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CurrentSelectedContainer->sizePolicy().hasHeightForWidth());
        CurrentSelectedContainer->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(CurrentSelectedContainer);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(CurrentSelectedContainer);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollBar:horizontal {\n"
"    background: transparent;\n"
"    height: 6px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #333;\n"
"    min-width: 20px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: #999;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal,\n"
"QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal,\n"
"QScrollBar::sub-page:horizontal {\n"
"    background: none;\n"
"}\n"
""));
        scrollArea->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 791, 260));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(CurrentSelectedContainer);

        QMetaObject::connectSlotsByName(CurrentSelectedContainer);
    } // setupUi

    void retranslateUi(QWidget *CurrentSelectedContainer)
    {
        CurrentSelectedContainer->setWindowTitle(QCoreApplication::translate("CurrentSelectedContainer", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CurrentSelectedContainer: public Ui_CurrentSelectedContainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTSELECTEDCONTAINER_H
