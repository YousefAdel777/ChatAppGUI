/********************************************************************************
** Form generated from reading UI file 'PrivacySettings.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIVACYSETTINGS_H
#define UI_PRIVACYSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *PrivacyWidgets;
    QWidget *MainPrivacyWidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *LastSeenAndOnlineBox;
    QLabel *LastSeenAndOnlineLabel;
    QPushButton *LastSeenAndOnlineCircle;
    QLabel *LastSeenAndOnlineChoice;
    QPushButton *LastSeenAndOnlineButton;
    QGroupBox *ProfilePhotoBox;
    QLabel *ProfilePhotoLabel;
    QPushButton *ProfilePhotoCircle;
    QPushButton *ProfilePhotoButton;
    QLabel *ProfilePhotoChoice;
    QGroupBox *AboutBox;
    QPushButton *AboutButton;
    QLabel *AboutChoice;
    QLabel *AboutLabel;
    QPushButton *AboutCircle;
    QGroupBox *StatusBox;
    QPushButton *StatusButton;
    QLabel *StatusLabel;
    QLabel *StatusChoice;
    QPushButton *StatusCircle;
    QLabel *MainLabel;
    QWidget *LastSeenAndOnlineWidget;
    QPushButton *LastSeenAndOnlineBack;
    QLabel *LastSeenAndOnlineWidgetLabel;
    QLabel *label;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *LastSeenChoiceEveryone;
    QRadioButton *LastSeenChoiceMyContacts;
    QRadioButton *LastSeenChoiceMyContactsExept;
    QRadioButton *LastSeenChoiceNobody;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *OnlineChoiceEveryone;
    QRadioButton *OnlineChoiceSameAsLastSeen;
    QLabel *label_2;
    QWidget *ProfilePhotoWidget;
    QPushButton *ProfilePhotoBack;
    QLabel *ProfilePhotoWidgetLabel;
    QLabel *label_3;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *ProfilePhotoChoiceEveryone;
    QRadioButton *ProfilePhotoChoiceMyContacts;
    QRadioButton *ProfilePhotoChoiceMyContactsExept;
    QRadioButton *ProfilePhotoChoiceNobody;
    QWidget *AboutWidget;
    QPushButton *AboutBack;
    QLabel *AboutWidgetLabel;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *AboutChoiceEveryone;
    QRadioButton *AboutChoiceMyContacts;
    QRadioButton *AboutChoiceMyContactsExept;
    QRadioButton *AboutChoiceNobody;
    QLabel *label_4;
    QWidget *StatusWidget;
    QPushButton *StatusBack;
    QLabel *StatusWidgetLabel;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *StatusChoiceMyContacts;
    QRadioButton *StatusChoiceMyContactsExept;
    QRadioButton *StatusChoiceOnlyShareWith;
    QWidget *ExcludeContactsWidget;
    QPushButton *ExcludeContactsBack;
    QLabel *ExcludeContactsWidgetLabel;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QPushButton *ExcludeContactsBack_2;
    QPushButton *ExcludeContactsSelectAll;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(500, 455);
        Widget->setStyleSheet(QString::fromUtf8("background-color: #E5E5E5;"));
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 601, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        PrivacyWidgets = new QStackedWidget(verticalLayoutWidget);
        PrivacyWidgets->setObjectName("PrivacyWidgets");
        PrivacyWidgets->setEnabled(true);
        QFont font;
        font.setPointSize(9);
        font.setKerning(true);
        PrivacyWidgets->setFont(font);
        PrivacyWidgets->setStyleSheet(QString::fromUtf8("background-color: #FBFDF6;"));
        MainPrivacyWidget = new QWidget();
        MainPrivacyWidget->setObjectName("MainPrivacyWidget");
        verticalLayoutWidget_2 = new QWidget(MainPrivacyWidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 30, 371, 371));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        LastSeenAndOnlineBox = new QGroupBox(verticalLayoutWidget_2);
        LastSeenAndOnlineBox->setObjectName("LastSeenAndOnlineBox");
        LastSeenAndOnlineBox->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"border: 0px;\n"
""));
        LastSeenAndOnlineLabel = new QLabel(LastSeenAndOnlineBox);
        LastSeenAndOnlineLabel->setObjectName("LastSeenAndOnlineLabel");
        LastSeenAndOnlineLabel->setGeometry(QRect(50, 30, 201, 31));
        QFont font1;
        font1.setPointSize(12);
        LastSeenAndOnlineLabel->setFont(font1);
        LastSeenAndOnlineLabel->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));
        LastSeenAndOnlineCircle = new QPushButton(LastSeenAndOnlineBox);
        LastSeenAndOnlineCircle->setObjectName("LastSeenAndOnlineCircle");
        LastSeenAndOnlineCircle->setEnabled(false);
        LastSeenAndOnlineCircle->setGeometry(QRect(260, 40, 30, 30));
        LastSeenAndOnlineCircle->setStyleSheet(QString::fromUtf8("background-color: #AED1AC;\n"
"border-radius: 15px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Arrow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        LastSeenAndOnlineCircle->setIcon(icon);
        LastSeenAndOnlineCircle->setCheckable(false);
        LastSeenAndOnlineCircle->setChecked(false);
        LastSeenAndOnlineChoice = new QLabel(LastSeenAndOnlineBox);
        LastSeenAndOnlineChoice->setObjectName("LastSeenAndOnlineChoice");
        LastSeenAndOnlineChoice->setGeometry(QRect(50, 60, 181, 21));
        LastSeenAndOnlineChoice->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #424941;"));
        LastSeenAndOnlineButton = new QPushButton(LastSeenAndOnlineBox);
        LastSeenAndOnlineButton->setObjectName("LastSeenAndOnlineButton");
        LastSeenAndOnlineButton->setEnabled(true);
        LastSeenAndOnlineButton->setGeometry(QRect(20, 20, 301, 71));
        LastSeenAndOnlineButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #FBFDF6;\n"
"border-radius: 30px;\n"
"}\n"
"QPushButton#LastSeenAndOnlineButton:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#LastSeenAndOnlineButton:pressed{\n"
"backGround-color: rgb(186, 223, 184);\n"
"}"));
        LastSeenAndOnlineButton->setCheckable(true);
        LastSeenAndOnlineButton->setAutoRepeat(false);
        LastSeenAndOnlineButton->setAutoExclusive(false);
        LastSeenAndOnlineButton->setAutoDefault(false);
        LastSeenAndOnlineButton->raise();
        LastSeenAndOnlineLabel->raise();
        LastSeenAndOnlineCircle->raise();
        LastSeenAndOnlineChoice->raise();

        verticalLayout_3->addWidget(LastSeenAndOnlineBox);

        ProfilePhotoBox = new QGroupBox(verticalLayoutWidget_2);
        ProfilePhotoBox->setObjectName("ProfilePhotoBox");
        ProfilePhotoBox->setStyleSheet(QString::fromUtf8("background-color: 0px;\n"
"border: 0px;"));
        ProfilePhotoLabel = new QLabel(ProfilePhotoBox);
        ProfilePhotoLabel->setObjectName("ProfilePhotoLabel");
        ProfilePhotoLabel->setGeometry(QRect(50, 30, 201, 31));
        ProfilePhotoLabel->setFont(font1);
        ProfilePhotoLabel->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));
        ProfilePhotoCircle = new QPushButton(ProfilePhotoBox);
        ProfilePhotoCircle->setObjectName("ProfilePhotoCircle");
        ProfilePhotoCircle->setEnabled(false);
        ProfilePhotoCircle->setGeometry(QRect(260, 40, 30, 30));
        ProfilePhotoCircle->setStyleSheet(QString::fromUtf8("background-color: #AED1AC;\n"
"border-radius: 15px;"));
        ProfilePhotoCircle->setIcon(icon);
        ProfilePhotoCircle->setCheckable(true);
        ProfilePhotoCircle->setChecked(false);
        ProfilePhotoButton = new QPushButton(ProfilePhotoBox);
        ProfilePhotoButton->setObjectName("ProfilePhotoButton");
        ProfilePhotoButton->setGeometry(QRect(20, 20, 301, 71));
        ProfilePhotoButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #FBFDF6;\n"
"border-radius: 30px;\n"
"}\n"
"QPushButton#ProfilePhotoButton:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#ProfilePhotoButton:pressed{\n"
"backGround-color: rgb(186, 223, 184);\n"
"}"));
        ProfilePhotoChoice = new QLabel(ProfilePhotoBox);
        ProfilePhotoChoice->setObjectName("ProfilePhotoChoice");
        ProfilePhotoChoice->setGeometry(QRect(50, 60, 171, 21));
        ProfilePhotoChoice->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #424941;"));
        ProfilePhotoButton->raise();
        ProfilePhotoLabel->raise();
        ProfilePhotoCircle->raise();
        ProfilePhotoChoice->raise();

        verticalLayout_3->addWidget(ProfilePhotoBox);

        AboutBox = new QGroupBox(verticalLayoutWidget_2);
        AboutBox->setObjectName("AboutBox");
        AboutBox->setStyleSheet(QString::fromUtf8("background-color: 0px;\n"
"border: 0px;"));
        AboutButton = new QPushButton(AboutBox);
        AboutButton->setObjectName("AboutButton");
        AboutButton->setGeometry(QRect(20, 20, 301, 71));
        AboutButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #FBFDF6;\n"
"border-radius: 30px;\n"
"}\n"
"QPushButton#AboutButton:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#AboutButton:pressed{\n"
"backGround-color: rgb(186, 223, 184);\n"
"}"));
        AboutChoice = new QLabel(AboutBox);
        AboutChoice->setObjectName("AboutChoice");
        AboutChoice->setGeometry(QRect(50, 60, 181, 21));
        AboutChoice->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #424941;"));
        AboutLabel = new QLabel(AboutBox);
        AboutLabel->setObjectName("AboutLabel");
        AboutLabel->setGeometry(QRect(50, 30, 201, 31));
        AboutLabel->setFont(font1);
        AboutLabel->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));
        AboutCircle = new QPushButton(AboutBox);
        AboutCircle->setObjectName("AboutCircle");
        AboutCircle->setEnabled(false);
        AboutCircle->setGeometry(QRect(260, 40, 30, 30));
        AboutCircle->setStyleSheet(QString::fromUtf8("background-color: #AED1AC;\n"
"border-radius: 15px;"));
        AboutCircle->setIcon(icon);
        AboutCircle->setCheckable(true);
        AboutCircle->setChecked(false);

        verticalLayout_3->addWidget(AboutBox);

        StatusBox = new QGroupBox(verticalLayoutWidget_2);
        StatusBox->setObjectName("StatusBox");
        StatusBox->setEnabled(true);
        StatusBox->setStyleSheet(QString::fromUtf8("background-color: 0px;\n"
"border: 0px;"));
        StatusButton = new QPushButton(StatusBox);
        StatusButton->setObjectName("StatusButton");
        StatusButton->setGeometry(QRect(20, 20, 300, 70));
        StatusButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #FBFDF6;\n"
"border-radius: 30px;\n"
"}\n"
"QPushButton#StatusButton:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#StatusButton:pressed{\n"
"backGround-color: rgb(186, 223, 184);\n"
"}"));
        StatusLabel = new QLabel(StatusBox);
        StatusLabel->setObjectName("StatusLabel");
        StatusLabel->setGeometry(QRect(50, 30, 201, 31));
        StatusLabel->setFont(font1);
        StatusLabel->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));
        StatusChoice = new QLabel(StatusBox);
        StatusChoice->setObjectName("StatusChoice");
        StatusChoice->setGeometry(QRect(50, 60, 181, 21));
        StatusChoice->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #424941;"));
        StatusCircle = new QPushButton(StatusBox);
        StatusCircle->setObjectName("StatusCircle");
        StatusCircle->setEnabled(false);
        StatusCircle->setGeometry(QRect(260, 40, 30, 30));
        StatusCircle->setStyleSheet(QString::fromUtf8("background-color: #AED1AC;\n"
"border-radius: 15px;"));
        StatusCircle->setIcon(icon);
        StatusCircle->setCheckable(true);
        StatusCircle->setChecked(false);

        verticalLayout_3->addWidget(StatusBox);

        MainLabel = new QLabel(MainPrivacyWidget);
        MainLabel->setObjectName("MainLabel");
        MainLabel->setGeometry(QRect(40, 12, 369, 21));
        QFont font2;
        font2.setPointSize(10);
        MainLabel->setFont(font2);
        MainLabel->setStyleSheet(QString::fromUtf8("color: #424941;\n"
"background-color: 0;"));
        PrivacyWidgets->addWidget(MainPrivacyWidget);
        LastSeenAndOnlineWidget = new QWidget();
        LastSeenAndOnlineWidget->setObjectName("LastSeenAndOnlineWidget");
        LastSeenAndOnlineBack = new QPushButton(LastSeenAndOnlineWidget);
        LastSeenAndOnlineBack->setObjectName("LastSeenAndOnlineBack");
        LastSeenAndOnlineBack->setGeometry(QRect(5, 5, 24, 24));
        LastSeenAndOnlineBack->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #FBFDF6;\n"
"border-radius: 12px;\n"
"}\n"
"QPushButton#LastSeenAndOnlineBack:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#LastSeenAndOnlineBack:pressed{\n"
"backGround-color: rgb(186, 223, 184);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/BackArrow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        LastSeenAndOnlineBack->setIcon(icon1);
        LastSeenAndOnlineBack->setIconSize(QSize(27, 27));
        LastSeenAndOnlineWidgetLabel = new QLabel(LastSeenAndOnlineWidget);
        LastSeenAndOnlineWidgetLabel->setObjectName("LastSeenAndOnlineWidgetLabel");
        LastSeenAndOnlineWidgetLabel->setGeometry(QRect(45, 5, 161, 24));
        LastSeenAndOnlineWidgetLabel->setFont(font1);
        LastSeenAndOnlineWidgetLabel->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));
        label = new QLabel(LastSeenAndOnlineWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(9, 44, 171, 16));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: #424941;\n"
"background-color: 0;"));
        verticalLayoutWidget_3 = new QWidget(LastSeenAndOnlineWidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(30, 70, 160, 127));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        LastSeenChoiceEveryone = new QRadioButton(verticalLayoutWidget_3);
        LastSeenChoiceEveryone->setObjectName("LastSeenChoiceEveryone");
        LastSeenChoiceEveryone->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_2->addWidget(LastSeenChoiceEveryone);

        LastSeenChoiceMyContacts = new QRadioButton(verticalLayoutWidget_3);
        LastSeenChoiceMyContacts->setObjectName("LastSeenChoiceMyContacts");
        LastSeenChoiceMyContacts->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_2->addWidget(LastSeenChoiceMyContacts);

        LastSeenChoiceMyContactsExept = new QRadioButton(verticalLayoutWidget_3);
        LastSeenChoiceMyContactsExept->setObjectName("LastSeenChoiceMyContactsExept");
        LastSeenChoiceMyContactsExept->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_2->addWidget(LastSeenChoiceMyContactsExept);

        LastSeenChoiceNobody = new QRadioButton(verticalLayoutWidget_3);
        LastSeenChoiceNobody->setObjectName("LastSeenChoiceNobody");
        LastSeenChoiceNobody->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_2->addWidget(LastSeenChoiceNobody);

        verticalLayoutWidget_4 = new QWidget(LastSeenAndOnlineWidget);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(30, 220, 160, 61));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        OnlineChoiceEveryone = new QRadioButton(verticalLayoutWidget_4);
        OnlineChoiceEveryone->setObjectName("OnlineChoiceEveryone");
        OnlineChoiceEveryone->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_4->addWidget(OnlineChoiceEveryone);

        OnlineChoiceSameAsLastSeen = new QRadioButton(verticalLayoutWidget_4);
        OnlineChoiceSameAsLastSeen->setObjectName("OnlineChoiceSameAsLastSeen");
        OnlineChoiceSameAsLastSeen->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_4->addWidget(OnlineChoiceSameAsLastSeen);

        label_2 = new QLabel(LastSeenAndOnlineWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(9, 193, 181, 16));
        label_2->setStyleSheet(QString::fromUtf8("color: #424941;\n"
"background-color: 0;"));
        PrivacyWidgets->addWidget(LastSeenAndOnlineWidget);
        ProfilePhotoWidget = new QWidget();
        ProfilePhotoWidget->setObjectName("ProfilePhotoWidget");
        ProfilePhotoBack = new QPushButton(ProfilePhotoWidget);
        ProfilePhotoBack->setObjectName("ProfilePhotoBack");
        ProfilePhotoBack->setGeometry(QRect(5, 5, 24, 24));
        ProfilePhotoBack->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        ProfilePhotoBack->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #FBFDF6;\n"
"border-radius: 12px;\n"
"}\n"
"QPushButton#ProfilePhotoBack:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#ProfilePhotoBack:pressed{\n"
"backGround-color: rgb(186, 223, 184);\n"
"}"));
        ProfilePhotoBack->setIcon(icon1);
        ProfilePhotoBack->setIconSize(QSize(27, 27));
        ProfilePhotoWidgetLabel = new QLabel(ProfilePhotoWidget);
        ProfilePhotoWidgetLabel->setObjectName("ProfilePhotoWidgetLabel");
        ProfilePhotoWidgetLabel->setGeometry(QRect(45, 5, 161, 24));
        ProfilePhotoWidgetLabel->setFont(font1);
        ProfilePhotoWidgetLabel->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));
        label_3 = new QLabel(ProfilePhotoWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(9, 44, 181, 16));
        label_3->setStyleSheet(QString::fromUtf8("color: #424941;\n"
"background-color: 0;"));
        verticalLayoutWidget_5 = new QWidget(ProfilePhotoWidget);
        verticalLayoutWidget_5->setObjectName("verticalLayoutWidget_5");
        verticalLayoutWidget_5->setGeometry(QRect(20, 70, 160, 127));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        ProfilePhotoChoiceEveryone = new QRadioButton(verticalLayoutWidget_5);
        ProfilePhotoChoiceEveryone->setObjectName("ProfilePhotoChoiceEveryone");
        ProfilePhotoChoiceEveryone->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_5->addWidget(ProfilePhotoChoiceEveryone);

        ProfilePhotoChoiceMyContacts = new QRadioButton(verticalLayoutWidget_5);
        ProfilePhotoChoiceMyContacts->setObjectName("ProfilePhotoChoiceMyContacts");
        ProfilePhotoChoiceMyContacts->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_5->addWidget(ProfilePhotoChoiceMyContacts);

        ProfilePhotoChoiceMyContactsExept = new QRadioButton(verticalLayoutWidget_5);
        ProfilePhotoChoiceMyContactsExept->setObjectName("ProfilePhotoChoiceMyContactsExept");
        ProfilePhotoChoiceMyContactsExept->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_5->addWidget(ProfilePhotoChoiceMyContactsExept);

        ProfilePhotoChoiceNobody = new QRadioButton(verticalLayoutWidget_5);
        ProfilePhotoChoiceNobody->setObjectName("ProfilePhotoChoiceNobody");
        ProfilePhotoChoiceNobody->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_5->addWidget(ProfilePhotoChoiceNobody);

        PrivacyWidgets->addWidget(ProfilePhotoWidget);
        AboutWidget = new QWidget();
        AboutWidget->setObjectName("AboutWidget");
        AboutBack = new QPushButton(AboutWidget);
        AboutBack->setObjectName("AboutBack");
        AboutBack->setGeometry(QRect(5, 5, 24, 24));
        AboutBack->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #FBFDF6;\n"
"border-radius: 12px;\n"
"}\n"
"QPushButton#AboutBack:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#AboutBack:pressed{\n"
"backGround-color: rgb(186, 223, 184);\n"
"}"));
        AboutBack->setIcon(icon1);
        AboutBack->setIconSize(QSize(27, 27));
        AboutWidgetLabel = new QLabel(AboutWidget);
        AboutWidgetLabel->setObjectName("AboutWidgetLabel");
        AboutWidgetLabel->setGeometry(QRect(45, 5, 91, 24));
        AboutWidgetLabel->setFont(font1);
        AboutWidgetLabel->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));
        verticalLayoutWidget_6 = new QWidget(AboutWidget);
        verticalLayoutWidget_6->setObjectName("verticalLayoutWidget_6");
        verticalLayoutWidget_6->setGeometry(QRect(20, 70, 160, 127));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        AboutChoiceEveryone = new QRadioButton(verticalLayoutWidget_6);
        AboutChoiceEveryone->setObjectName("AboutChoiceEveryone");
        AboutChoiceEveryone->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_6->addWidget(AboutChoiceEveryone);

        AboutChoiceMyContacts = new QRadioButton(verticalLayoutWidget_6);
        AboutChoiceMyContacts->setObjectName("AboutChoiceMyContacts");
        AboutChoiceMyContacts->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_6->addWidget(AboutChoiceMyContacts);

        AboutChoiceMyContactsExept = new QRadioButton(verticalLayoutWidget_6);
        AboutChoiceMyContactsExept->setObjectName("AboutChoiceMyContactsExept");
        AboutChoiceMyContactsExept->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_6->addWidget(AboutChoiceMyContactsExept);

        AboutChoiceNobody = new QRadioButton(verticalLayoutWidget_6);
        AboutChoiceNobody->setObjectName("AboutChoiceNobody");
        AboutChoiceNobody->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_6->addWidget(AboutChoiceNobody);

        label_4 = new QLabel(AboutWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 44, 181, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: #424941;\n"
"background-color: 0;"));
        PrivacyWidgets->addWidget(AboutWidget);
        StatusWidget = new QWidget();
        StatusWidget->setObjectName("StatusWidget");
        StatusBack = new QPushButton(StatusWidget);
        StatusBack->setObjectName("StatusBack");
        StatusBack->setGeometry(QRect(5, 5, 24, 24));
        StatusBack->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #FBFDF6;\n"
"border-radius: 12px;\n"
"}\n"
"QPushButton#StatusBack:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#StatusBack:pressed{\n"
"backGround-color: rgb(186, 223, 184);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/BackArrow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        StatusBack->setIcon(icon2);
        StatusBack->setIconSize(QSize(27, 27));
        StatusWidgetLabel = new QLabel(StatusWidget);
        StatusWidgetLabel->setObjectName("StatusWidgetLabel");
        StatusWidgetLabel->setGeometry(QRect(45, 5, 161, 24));
        StatusWidgetLabel->setFont(font1);
        StatusWidgetLabel->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));
        label_5 = new QLabel(StatusWidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(9, 44, 191, 16));
        label_5->setStyleSheet(QString::fromUtf8("color: #424941;\n"
"background-color: 0;"));
        verticalLayoutWidget_7 = new QWidget(StatusWidget);
        verticalLayoutWidget_7->setObjectName("verticalLayoutWidget_7");
        verticalLayoutWidget_7->setGeometry(QRect(20, 70, 160, 94));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        StatusChoiceMyContacts = new QRadioButton(verticalLayoutWidget_7);
        StatusChoiceMyContacts->setObjectName("StatusChoiceMyContacts");
        StatusChoiceMyContacts->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_7->addWidget(StatusChoiceMyContacts);

        StatusChoiceMyContactsExept = new QRadioButton(verticalLayoutWidget_7);
        StatusChoiceMyContactsExept->setObjectName("StatusChoiceMyContactsExept");
        StatusChoiceMyContactsExept->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_7->addWidget(StatusChoiceMyContactsExept);

        StatusChoiceOnlyShareWith = new QRadioButton(verticalLayoutWidget_7);
        StatusChoiceOnlyShareWith->setObjectName("StatusChoiceOnlyShareWith");
        StatusChoiceOnlyShareWith->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));

        verticalLayout_7->addWidget(StatusChoiceOnlyShareWith);

        PrivacyWidgets->addWidget(StatusWidget);
        ExcludeContactsWidget = new QWidget();
        ExcludeContactsWidget->setObjectName("ExcludeContactsWidget");
        ExcludeContactsBack = new QPushButton(ExcludeContactsWidget);
        ExcludeContactsBack->setObjectName("ExcludeContactsBack");
        ExcludeContactsBack->setGeometry(QRect(10, 10, 24, 24));
        ExcludeContactsBack->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #FBFDF6;\n"
"border-radius: 12px;\n"
"}\n"
"QPushButton#ExcludeContactsBack:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#ExcludeContactsBack:pressed{\n"
"backGround-color: rgb(186, 223, 184);\n"
"}"));
        ExcludeContactsBack->setIcon(icon1);
        ExcludeContactsBack->setIconSize(QSize(27, 27));
        ExcludeContactsWidgetLabel = new QLabel(ExcludeContactsWidget);
        ExcludeContactsWidgetLabel->setObjectName("ExcludeContactsWidgetLabel");
        ExcludeContactsWidgetLabel->setGeometry(QRect(50, 10, 121, 28));
        ExcludeContactsWidgetLabel->setMinimumSize(QSize(0, 0));
        ExcludeContactsWidgetLabel->setFont(font1);
        ExcludeContactsWidgetLabel->setStyleSheet(QString::fromUtf8("background-color: 0;\n"
"color: #0E1F12;"));
        groupBox = new QGroupBox(ExcludeContactsWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(125, 40, 250, 41));
        groupBox->setStyleSheet(QString::fromUtf8("border: none"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(0, 0, 250, 42));
        QFont font3;
        font3.setPointSize(11);
        lineEdit->setFont(font3);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 10px 5px;\n"
"border-radius: 20px;\n"
"font-size: 11pt;\n"
"color: #424941;\n"
"border: none;\n"
""));
        ExcludeContactsBack_2 = new QPushButton(groupBox);
        ExcludeContactsBack_2->setObjectName("ExcludeContactsBack_2");
        ExcludeContactsBack_2->setGeometry(QRect(207, 0, 42, 42));
        ExcludeContactsBack_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #D3E8D2;\n"
"border-radius: 21px;\n"
"}\n"
"QPushButton#ExcludeContactsBack:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#ExcludeContactsBack:pressed{\n"
"backGround-color: rgb(186, 223, 184);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ExcludeContactsBack_2->setIcon(icon3);
        ExcludeContactsBack_2->setIconSize(QSize(20, 20));
        ExcludeContactsSelectAll = new QPushButton(ExcludeContactsWidget);
        ExcludeContactsSelectAll->setObjectName("ExcludeContactsSelectAll");
        ExcludeContactsSelectAll->setGeometry(QRect(420, 10, 41, 41));
        ExcludeContactsSelectAll->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #FBFDF6;\n"
"border-radius: 15px;\n"
"}\n"
"QPushButton#ExcludeContactsSelectAll:hover{\n"
"background-color:rgb(238, 240, 233);\n"
"}\n"
"QPushButton#ExcludeContactsSelectAll:pressed{\n"
"backGround-color: rgb(198, 217, 197);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/SelectAll.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ExcludeContactsSelectAll->setIcon(icon4);
        ExcludeContactsSelectAll->setIconSize(QSize(35, 35));
        scrollArea = new QScrollArea(ExcludeContactsWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(68, 90, 350, 354));
        scrollArea->setMinimumSize(QSize(340, 0));
        scrollArea->setStyleSheet(QString::fromUtf8("border: none"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 350, 354));
        scrollArea->setWidget(scrollAreaWidgetContents);
        PrivacyWidgets->addWidget(ExcludeContactsWidget);

        verticalLayout->addWidget(PrivacyWidgets);


        retranslateUi(Widget);

        PrivacyWidgets->setCurrentIndex(2);
        LastSeenAndOnlineButton->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        LastSeenAndOnlineBox->setTitle(QString());
        LastSeenAndOnlineLabel->setText(QCoreApplication::translate("Widget", "Last seen and online", nullptr));
        LastSeenAndOnlineCircle->setText(QString());
        LastSeenAndOnlineChoice->setText(QCoreApplication::translate("Widget", "Everyone, Everyone", nullptr));
        LastSeenAndOnlineButton->setText(QString());
        ProfilePhotoBox->setTitle(QString());
        ProfilePhotoLabel->setText(QCoreApplication::translate("Widget", "Profile Photo", nullptr));
        ProfilePhotoCircle->setText(QString());
        ProfilePhotoButton->setText(QString());
        ProfilePhotoChoice->setText(QCoreApplication::translate("Widget", "Everyone", nullptr));
        AboutBox->setTitle(QString());
        AboutButton->setText(QString());
        AboutChoice->setText(QCoreApplication::translate("Widget", "Everyone", nullptr));
        AboutLabel->setText(QCoreApplication::translate("Widget", "About", nullptr));
        AboutCircle->setText(QString());
        StatusBox->setTitle(QString());
        StatusButton->setText(QString());
        StatusLabel->setText(QCoreApplication::translate("Widget", "Status", nullptr));
        StatusChoice->setText(QCoreApplication::translate("Widget", "My contacts", nullptr));
        StatusCircle->setText(QString());
        MainLabel->setText(QCoreApplication::translate("Widget", "Who can see your info", nullptr));
        LastSeenAndOnlineBack->setText(QString());
        LastSeenAndOnlineWidgetLabel->setText(QCoreApplication::translate("Widget", "Last seen and online", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Who can see my last seen", nullptr));
        LastSeenChoiceEveryone->setText(QCoreApplication::translate("Widget", "Everyone", nullptr));
        LastSeenChoiceMyContacts->setText(QCoreApplication::translate("Widget", "My contacts", nullptr));
        LastSeenChoiceMyContactsExept->setText(QCoreApplication::translate("Widget", "My contacts except", nullptr));
        LastSeenChoiceNobody->setText(QCoreApplication::translate("Widget", "Nobody", nullptr));
        OnlineChoiceEveryone->setText(QCoreApplication::translate("Widget", "Everyone", nullptr));
        OnlineChoiceSameAsLastSeen->setText(QCoreApplication::translate("Widget", "Same as last seen", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Who can see when I'm online", nullptr));
        ProfilePhotoBack->setText(QString());
        ProfilePhotoWidgetLabel->setText(QCoreApplication::translate("Widget", "Profile photo", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Who can see my profile photo", nullptr));
        ProfilePhotoChoiceEveryone->setText(QCoreApplication::translate("Widget", "Everyone", nullptr));
        ProfilePhotoChoiceMyContacts->setText(QCoreApplication::translate("Widget", "My contacts", nullptr));
        ProfilePhotoChoiceMyContactsExept->setText(QCoreApplication::translate("Widget", "My contacts exept", nullptr));
        ProfilePhotoChoiceNobody->setText(QCoreApplication::translate("Widget", "Nobody", nullptr));
        AboutBack->setText(QString());
        AboutWidgetLabel->setText(QCoreApplication::translate("Widget", "About", nullptr));
        AboutChoiceEveryone->setText(QCoreApplication::translate("Widget", "Everyone", nullptr));
        AboutChoiceMyContacts->setText(QCoreApplication::translate("Widget", "My contacts", nullptr));
        AboutChoiceMyContactsExept->setText(QCoreApplication::translate("Widget", "My contacts exept", nullptr));
        AboutChoiceNobody->setText(QCoreApplication::translate("Widget", "Nobody", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Who can see my profile photo", nullptr));
        StatusBack->setText(QString());
        StatusWidgetLabel->setText(QCoreApplication::translate("Widget", "Status", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "Who can see my status updates", nullptr));
        StatusChoiceMyContacts->setText(QCoreApplication::translate("Widget", "My contacts", nullptr));
        StatusChoiceMyContactsExept->setText(QCoreApplication::translate("Widget", "My contacts exept", nullptr));
        StatusChoiceOnlyShareWith->setText(QCoreApplication::translate("Widget", "Only share with", nullptr));
        ExcludeContactsBack->setText(QString());
        ExcludeContactsWidgetLabel->setText(QCoreApplication::translate("Widget", "Exclude contacts", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "GroupBox", nullptr));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "Search Contact", nullptr));
        ExcludeContactsBack_2->setText(QString());
        ExcludeContactsSelectAll->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIVACYSETTINGS_H
