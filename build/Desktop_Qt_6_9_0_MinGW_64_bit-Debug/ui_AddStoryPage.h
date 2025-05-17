/********************************************************************************
** Form generated from reading UI file 'addStoryPage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTORYPAGE_H
#define UI_ADDSTORYPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddStoryPage
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *AddStoryPage)
    {
        if (AddStoryPage->objectName().isEmpty())
            AddStoryPage->setObjectName("AddStoryPage");
        AddStoryPage->resize(420, 640);
        AddStoryPage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(AddStoryPage);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 7, 420, 72));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(28);
        horizontalLayout->setObjectName("horizontalLayout");
        toolButton = new QToolButton(widget);
        toolButton->setObjectName("toolButton");
        toolButton->setMinimumSize(QSize(0, 0));
        toolButton->setMaximumSize(QSize(150, 96));
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	font: 48pt \"Bell MT\";\n"
"    background-color: #EAF3EB;\n"
"    border: none;\n"
"    border-radius: 25px;\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    color: black;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/DELL/Downloads/T.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(16, 16));
        toolButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName("toolButton_2");
        toolButton_2->setMinimumSize(QSize(0, 0));
        toolButton_2->setMaximumSize(QSize(150, 96));
        toolButton_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	font: 48pt \"Bell MT\";\n"
"    background-color: #EAF3EB;\n"
"    border: none;\n"
"    border-radius: 25px;\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    color: black;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/DELL/Downloads/image-gallery.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(20, 20));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_2);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 220, 150, 150));
        label->setPixmap(QPixmap(QString::fromUtf8(":/assets/assets/art.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 381, 420, 48));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bell MT")});
        font.setPointSize(35);
        font.setBold(false);
        label_2->setFont(font);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(AddStoryPage);

        QMetaObject::connectSlotsByName(AddStoryPage);
    } // setupUi

    void retranslateUi(QDialog *AddStoryPage)
    {
        AddStoryPage->setWindowTitle(QCoreApplication::translate("AddStoryPage", "MainWindow", nullptr));
        toolButton->setText(QCoreApplication::translate("AddStoryPage", "Text", nullptr));
        toolButton_2->setText(QCoreApplication::translate("AddStoryPage", "Media", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("AddStoryPage", "Create and express", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStoryPage: public Ui_AddStoryPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTORYPAGE_H
