/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QListView *listView;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_2;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 797);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 100, 411, 91));
        QFont font;
        font.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font.setPointSize(18);
        font.setWeight(QFont::Medium);
        font.setItalic(false);
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #E7F1E6;\n"
"border: none;\n"
"border-radius: 30px;\n"
"text-align: left;\n"
"padding-left: 80px;\n"
"padding-bottom: 20px;\n"
""));
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(0, -130, 471, 1011));
        listView->setStyleSheet(QString::fromUtf8("background-color: rgb(251, 253, 246);\n"
"border: none;\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setGeometry(QRect(50, 40, 81, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font1.setPointSize(22);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(251, 253, 246);"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 320, 471, 80));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 469, 78));
        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 0, 411, 91));
        pushButton_2->setFont(font);
        pushButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #E7F1E6;\n"
"border: none;\n"
"border-radius: 30px;\n"
"text-align: left;\n"
"padding-left: 80px;\n"
"padding-bottom: 20px;\n"
""));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(53, 215, 121, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font2.setPointSize(14);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(251, 253, 246);\n"
"color: rgb(66, 73, 65);"));
        MainWindow->setCentralWidget(centralwidget);
        listView->raise();
        pushButton->raise();
        label->raise();
        scrollArea->raise();
        label_2->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add status", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Add status", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Visited status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
