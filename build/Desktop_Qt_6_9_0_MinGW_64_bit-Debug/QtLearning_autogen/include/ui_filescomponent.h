/********************************************************************************
** Form generated from reading UI file 'filescomponent.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESCOMPONENT_H
#define UI_FILESCOMPONENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilesComponent
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QLabel *name;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *FilesComponent)
    {
        if (FilesComponent->objectName().isEmpty())
            FilesComponent->setObjectName("FilesComponent");
        FilesComponent->resize(227, 234);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FilesComponent->sizePolicy().hasHeightForWidth());
        FilesComponent->setSizePolicy(sizePolicy);
        FilesComponent->setMinimumSize(QSize(227, 234));
        FilesComponent->setMaximumSize(QSize(227, 234));
        FilesComponent->setStyleSheet(QString::fromUtf8("background-color:white;"));
        gridLayout = new QGridLayout(FilesComponent);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(3, 3, 3, 3);
        widget = new QWidget(FilesComponent);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("background-color:#535353;\n"
"border-radius:15px;\n"
"border:3px solid rgb(50,50,50);"));
        name = new QLabel(widget);
        name->setObjectName("name");
        name->setGeometry(QRect(10, 190, 201, 30));
        name->setMaximumSize(QSize(16777215, 30));
        name->setStyleSheet(QString::fromUtf8("border:0;\n"
"color:white;\n"
"font-size:9pt;"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 50, 100, 100));
        label->setMaximumSize(QSize(100, 100));
        label->setStyleSheet(QString::fromUtf8("border:0;"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Resources/FileBig.png")));
        label->setScaledContents(true);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 0, 41, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(70,70,70);\n"
"border-radius:15;\n"
"border:0;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(20, 20));

        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(FilesComponent);

        QMetaObject::connectSlotsByName(FilesComponent);
    } // setupUi

    void retranslateUi(QWidget *FilesComponent)
    {
        FilesComponent->setWindowTitle(QCoreApplication::translate("FilesComponent", "Form", nullptr));
        name->setText(QCoreApplication::translate("FilesComponent", "myVoice.wav", nullptr));
        label->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FilesComponent: public Ui_FilesComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESCOMPONENT_H
