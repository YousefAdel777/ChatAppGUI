/********************************************************************************
** Form generated from reading UI file 'creategroup.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGROUP_H
#define UI_CREATEGROUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateGroup
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QLabel *groupImg;
    QPushButton *addImageBtn;
    QPushButton *removeImageBtn;
    QLabel *label;
    QLineEdit *nameIn;
    QLabel *nameErr;
    QLabel *label_2;
    QLineEdit *descIn;
    QLabel *descErr;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;

    void setupUi(QWidget *CreateGroup)
    {
        if (CreateGroup->objectName().isEmpty())
            CreateGroup->setObjectName("CreateGroup");
        CreateGroup->resize(401, 405);
        CreateGroup->setStyleSheet(QString::fromUtf8("background-color: white;"));
        verticalLayout = new QVBoxLayout(CreateGroup);
        verticalLayout->setObjectName("verticalLayout");
        label_3 = new QLabel(CreateGroup);
        label_3->setObjectName("label_3");
        QFont font;
        font.setBold(true);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
""));

        verticalLayout->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget_2 = new QWidget(CreateGroup);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(0, 90));
        groupImg = new QLabel(widget_2);
        groupImg->setObjectName("groupImg");
        groupImg->setGeometry(QRect(148, 5, 85, 85));
        groupImg->setPixmap(QPixmap(QString::fromUtf8(":/icons/group.png")));
        addImageBtn = new QPushButton(widget_2);
        addImageBtn->setObjectName("addImageBtn");
        addImageBtn->setGeometry(QRect(210, 60, 30, 30));
        addImageBtn->setMaximumSize(QSize(30, 30));
        addImageBtn->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"border-radius: 10px;\n"
"background-color: \"#D3E8D2\";"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        addImageBtn->setIcon(icon);
        addImageBtn->setIconSize(QSize(16, 16));
        removeImageBtn = new QPushButton(widget_2);
        removeImageBtn->setObjectName("removeImageBtn");
        removeImageBtn->setGeometry(QRect(140, 60, 30, 30));
        removeImageBtn->setMinimumSize(QSize(30, 30));
        removeImageBtn->setMaximumSize(QSize(30, 30));
        removeImageBtn->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"border-radius: 10px;\n"
"background-color: \"#D3E8D2\";"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        removeImageBtn->setIcon(icon1);

        verticalLayout->addWidget(widget_2);

        label = new QLabel(CreateGroup);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 50));
        label->setStyleSheet(QString::fromUtf8("padding: 0;"));

        verticalLayout->addWidget(label);

        nameIn = new QLineEdit(CreateGroup);
        nameIn->setObjectName("nameIn");
        nameIn->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 8px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));

        verticalLayout->addWidget(nameIn);

        nameErr = new QLabel(CreateGroup);
        nameErr->setObjectName("nameErr");
        nameErr->setStyleSheet(QString::fromUtf8("color: \"red\";\n"
"padding: 0;\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(nameErr);

        label_2 = new QLabel(CreateGroup);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        descIn = new QLineEdit(CreateGroup);
        descIn->setObjectName("descIn");
        descIn->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 8px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));

        verticalLayout->addWidget(descIn);

        descErr = new QLabel(CreateGroup);
        descErr->setObjectName("descErr");
        descErr->setStyleSheet(QString::fromUtf8("color: \"red\";\n"
"padding: 0;\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(descErr);

        widget = new QWidget(CreateGroup);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(widget);
        addBtn->setObjectName("addBtn");
        addBtn->setStyleSheet(QString::fromUtf8("border-radius: 10px; \n"
"background-color: \"#D3E8D2\";\n"
"padding: 10px;\n"
"font-weight: 600;"));

        horizontalLayout->addWidget(addBtn);


        verticalLayout->addWidget(widget);


        retranslateUi(CreateGroup);

        QMetaObject::connectSlotsByName(CreateGroup);
    } // setupUi

    void retranslateUi(QWidget *CreateGroup)
    {
        CreateGroup->setWindowTitle(QCoreApplication::translate("CreateGroup", "CreateGroup", nullptr));
        label_3->setText(QCoreApplication::translate("CreateGroup", "Create Group", nullptr));
        groupImg->setText(QString());
        addImageBtn->setText(QString());
        removeImageBtn->setText(QString());
        label->setText(QCoreApplication::translate("CreateGroup", "Group Name", nullptr));
        nameIn->setPlaceholderText(QCoreApplication::translate("CreateGroup", "Group Name", nullptr));
        nameErr->setText(QString());
        label_2->setText(QCoreApplication::translate("CreateGroup", "Group Description", nullptr));
        descIn->setPlaceholderText(QCoreApplication::translate("CreateGroup", "Group Description", nullptr));
        descErr->setText(QString());
        addBtn->setText(QCoreApplication::translate("CreateGroup", "Create Group", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGroup: public Ui_CreateGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGROUP_H
