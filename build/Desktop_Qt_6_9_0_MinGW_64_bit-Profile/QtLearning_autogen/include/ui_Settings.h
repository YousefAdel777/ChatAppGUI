/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *closeSettingsBtn;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *profileImageLabel;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *aboutLabel;
    QPushButton *editBtn;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *logoutBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *deleteAccountBtn;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *privacyBtn;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_5;
    QWidget *profileInfoForm;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_9;
    QWidget *widget_9;
    QLabel *profileImageLabel_2;
    QPushButton *addImageBtn;
    QLabel *label_10;
    QLineEdit *firstNameIn;
    QLabel *firstNameError;
    QLabel *label_11;
    QLineEdit *lastNameIn;
    QLabel *lastNameError;
    QLabel *label_12;
    QLineEdit *phoneNumberInput;
    QLabel *phoneError;
    QLabel *label_13;
    QLineEdit *aboutInput;
    QLabel *aboutError;
    QLabel *label_14;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *oldPasswordInput;
    QPushButton *checkPasswordBtn;
    QLabel *oldPasswordError;
    QLabel *label_15;
    QLineEdit *newPasswordInput;
    QLabel *newPasswordError;
    QLabel *label_2;
    QPushButton *addLinksBtn;
    QPushButton *saveBtn;
    QWidget *privacySettings;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(1290, 736);
        Settings->setAutoFillBackground(false);
        Settings->setStyleSheet(QString::fromUtf8("padding: 0;"));
        horizontalLayout = new QHBoxLayout(Settings);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(Settings);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("background-color: \"#fff\";\n"
"margin: 0;"));
        horizontalLayout_6 = new QHBoxLayout(widget_2);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(10, 720));
        widget->setMaximumSize(QSize(400, 720));
        QFont font;
        font.setFamilies({QString::fromUtf8("Product Sans Medium")});
        widget->setFont(font);
        widget->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"background-color: \"#FBFDF6\";\n"
"padding: 0;"));
        horizontalLayoutWidget = new QWidget(widget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 401, 119));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font-size: 30px;\n"
"padding-left: 20px;"));

        horizontalLayout_2->addWidget(label);

        closeSettingsBtn = new QPushButton(horizontalLayoutWidget);
        closeSettingsBtn->setObjectName("closeSettingsBtn");
        closeSettingsBtn->setMaximumSize(QSize(60, 30));
        closeSettingsBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        closeSettingsBtn->setStyleSheet(QString::fromUtf8("margin-right: 30px;\n"
"background-color: transparent;"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        closeSettingsBtn->setIcon(icon);

        horizontalLayout_2->addWidget(closeSettingsBtn);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(50, 120, 311, 101));
        widget_3->setMinimumSize(QSize(0, 0));
        widget_3->setMaximumSize(QSize(400, 200));
        widget_3->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"background-color: \"#E7F1E6\";\n"
"padding: 50px;"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(12);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        profileImageLabel = new QLabel(widget_3);
        profileImageLabel->setObjectName("profileImageLabel");
        profileImageLabel->setMaximumSize(QSize(90, 16777215));
        profileImageLabel->setStyleSheet(QString::fromUtf8("padding: 0;"));
        profileImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/icons/user.png")));
        profileImageLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(profileImageLabel);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        verticalLayout = new QVBoxLayout(widget_4);
        verticalLayout->setObjectName("verticalLayout");
        nameLabel = new QLabel(widget_4);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setMaximumSize(QSize(150, 16777215));
        nameLabel->setFont(font);
        nameLabel->setStyleSheet(QString::fromUtf8("padding :0;\n"
"font-size: 16px;"));
        nameLabel->setWordWrap(true);

        verticalLayout->addWidget(nameLabel);

        aboutLabel = new QLabel(widget_4);
        aboutLabel->setObjectName("aboutLabel");
        aboutLabel->setMinimumSize(QSize(0, 0));
        aboutLabel->setMaximumSize(QSize(150, 150));
        aboutLabel->setFont(font);
        aboutLabel->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"font-size: 12px;"));
        aboutLabel->setWordWrap(true);

        verticalLayout->addWidget(aboutLabel);


        horizontalLayout_3->addWidget(widget_4);

        editBtn = new QPushButton(widget);
        editBtn->setObjectName("editBtn");
        editBtn->setGeometry(QRect(280, 200, 55, 55));
        editBtn->setMaximumSize(QSize(183, 183));
        editBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        editBtn->setMouseTracking(false);
        editBtn->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"background-color: \"#D3E8D2\";\n"
"padding: 0;"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        editBtn->setIcon(icon1);
        editBtn->setIconSize(QSize(20, 20));
        widget_6 = new QWidget(widget);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(50, 380, 311, 61));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        logoutBtn = new QPushButton(widget_6);
        logoutBtn->setObjectName("logoutBtn");
        logoutBtn->setFont(font);
        logoutBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        logoutBtn->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color: \"#D3E8D2\";\n"
"border: none;\n"
"font-size: 16px;\n"
"border-radius: 16px;"));

        horizontalLayout_5->addWidget(logoutBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout_5->addItem(verticalSpacer);

        deleteAccountBtn = new QPushButton(widget_6);
        deleteAccountBtn->setObjectName("deleteAccountBtn");
        deleteAccountBtn->setFont(font);
        deleteAccountBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deleteAccountBtn->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding: 10px;\n"
"background-color: \"#D3E8D2\";\n"
"border: none;\n"
"font-size: 16px;\n"
"border-radius: 16px;"));

        horizontalLayout_5->addWidget(deleteAccountBtn);

        widget_10 = new QWidget(widget);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(50, 280, 311, 81));
        widget_10->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"background-color: \"#E7F1E6\";"));
        horizontalLayout_8 = new QHBoxLayout(widget_10);
        horizontalLayout_8->setSpacing(20);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_16 = new QLabel(widget_10);
        label_16->setObjectName("label_16");
        label_16->setMaximumSize(QSize(40, 40));
        label_16->setStyleSheet(QString::fromUtf8("padding: 10px;\n"
"background-color: \"#D3E8D2\";\n"
"border-radius: 20px;"));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/icons/icons/padlock.png")));
        label_16->setScaledContents(true);

        horizontalLayout_8->addWidget(label_16);

        label_17 = new QLabel(widget_10);
        label_17->setObjectName("label_17");
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"font-size: 18px;"));
        label_17->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_8->addWidget(label_17);

        privacyBtn = new QPushButton(widget_10);
        privacyBtn->setObjectName("privacyBtn");
        privacyBtn->setMaximumSize(QSize(40, 40));
        privacyBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        privacyBtn->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"background-color: \"#D3E8D2\";"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/arrow-right.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        privacyBtn->setIcon(icon2);

        horizontalLayout_8->addWidget(privacyBtn);


        horizontalLayout_6->addWidget(widget);

        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName("widget_7");
        widget_7->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_7);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget_7);
        scrollArea->setObjectName("scrollArea");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(900, 720));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setStyleSheet(QString::fromUtf8("padding: 0; \n"
"margin: 0;\n"
"border: none;"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 883, 796));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        profileInfoForm = new QWidget(scrollAreaWidgetContents_2);
        profileInfoForm->setObjectName("profileInfoForm");
        profileInfoForm->setStyleSheet(QString::fromUtf8("margin: 0;"));
        verticalLayout_4 = new QVBoxLayout(profileInfoForm);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 20);
        label_9 = new QLabel(profileInfoForm);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(10, 0));
        label_9->setMaximumSize(QSize(16777215, 70));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"font-size: 30px"));
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_9);

        widget_9 = new QWidget(profileInfoForm);
        widget_9->setObjectName("widget_9");
        widget_9->setMinimumSize(QSize(150, 90));
        profileImageLabel_2 = new QLabel(widget_9);
        profileImageLabel_2->setObjectName("profileImageLabel_2");
        profileImageLabel_2->setGeometry(QRect(40, 0, 64, 64));
        profileImageLabel_2->setMaximumSize(QSize(90, 16777215));
        profileImageLabel_2->setStyleSheet(QString::fromUtf8("padding: 0;"));
        profileImageLabel_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/icons/user.png")));
        profileImageLabel_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        addImageBtn = new QPushButton(widget_9);
        addImageBtn->setObjectName("addImageBtn");
        addImageBtn->setGeometry(QRect(80, 40, 30, 30));
        addImageBtn->setMinimumSize(QSize(30, 30));
        addImageBtn->setMaximumSize(QSize(30, 30));
        addImageBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addImageBtn->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"border-radius: 10px;\n"
"background-color: \"#D3E8D2\";"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        addImageBtn->setIcon(icon3);

        verticalLayout_4->addWidget(widget_9, 0, Qt::AlignmentFlag::AlignHCenter);

        label_10 = new QLabel(profileInfoForm);
        label_10->setObjectName("label_10");
        label_10->setMinimumSize(QSize(400, 0));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));

        verticalLayout_4->addWidget(label_10, 0, Qt::AlignmentFlag::AlignHCenter);

        firstNameIn = new QLineEdit(profileInfoForm);
        firstNameIn->setObjectName("firstNameIn");
        firstNameIn->setMinimumSize(QSize(400, 0));
        firstNameIn->setMaximumSize(QSize(16777215, 16777215));
        firstNameIn->setFont(font);
        firstNameIn->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 10px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));

        verticalLayout_4->addWidget(firstNameIn, 0, Qt::AlignmentFlag::AlignHCenter);

        firstNameError = new QLabel(profileInfoForm);
        firstNameError->setObjectName("firstNameError");
        firstNameError->setMinimumSize(QSize(400, 0));
        firstNameError->setFont(font);
        firstNameError->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding-left: 5px;\n"
"color: red;"));

        verticalLayout_4->addWidget(firstNameError, 0, Qt::AlignmentFlag::AlignHCenter);

        label_11 = new QLabel(profileInfoForm);
        label_11->setObjectName("label_11");
        label_11->setMinimumSize(QSize(400, 0));
        label_11->setMaximumSize(QSize(16777215, 16777215));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));

        verticalLayout_4->addWidget(label_11, 0, Qt::AlignmentFlag::AlignHCenter);

        lastNameIn = new QLineEdit(profileInfoForm);
        lastNameIn->setObjectName("lastNameIn");
        lastNameIn->setMinimumSize(QSize(400, 0));
        lastNameIn->setMaximumSize(QSize(16777215, 16777215));
        lastNameIn->setFont(font);
        lastNameIn->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 10px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));

        verticalLayout_4->addWidget(lastNameIn, 0, Qt::AlignmentFlag::AlignHCenter);

        lastNameError = new QLabel(profileInfoForm);
        lastNameError->setObjectName("lastNameError");
        lastNameError->setMinimumSize(QSize(400, 0));
        lastNameError->setFont(font);
        lastNameError->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding-left: 5px;\n"
"color: red;"));

        verticalLayout_4->addWidget(lastNameError, 0, Qt::AlignmentFlag::AlignHCenter);

        label_12 = new QLabel(profileInfoForm);
        label_12->setObjectName("label_12");
        label_12->setMinimumSize(QSize(400, 0));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));

        verticalLayout_4->addWidget(label_12, 0, Qt::AlignmentFlag::AlignHCenter);

        phoneNumberInput = new QLineEdit(profileInfoForm);
        phoneNumberInput->setObjectName("phoneNumberInput");
        phoneNumberInput->setMinimumSize(QSize(400, 0));
        phoneNumberInput->setFont(font);
        phoneNumberInput->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 10px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));

        verticalLayout_4->addWidget(phoneNumberInput, 0, Qt::AlignmentFlag::AlignHCenter);

        phoneError = new QLabel(profileInfoForm);
        phoneError->setObjectName("phoneError");
        phoneError->setMinimumSize(QSize(400, 0));
        phoneError->setFont(font);
        phoneError->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding-left: 5px;\n"
"color: red;"));

        verticalLayout_4->addWidget(phoneError, 0, Qt::AlignmentFlag::AlignHCenter);

        label_13 = new QLabel(profileInfoForm);
        label_13->setObjectName("label_13");
        label_13->setMinimumSize(QSize(400, 0));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));

        verticalLayout_4->addWidget(label_13, 0, Qt::AlignmentFlag::AlignHCenter);

        aboutInput = new QLineEdit(profileInfoForm);
        aboutInput->setObjectName("aboutInput");
        aboutInput->setMinimumSize(QSize(400, 0));
        aboutInput->setFont(font);
        aboutInput->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 10px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));

        verticalLayout_4->addWidget(aboutInput, 0, Qt::AlignmentFlag::AlignHCenter);

        aboutError = new QLabel(profileInfoForm);
        aboutError->setObjectName("aboutError");
        aboutError->setMinimumSize(QSize(400, 0));
        aboutError->setFont(font);
        aboutError->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding-left: 5px;\n"
"color: red;"));

        verticalLayout_4->addWidget(aboutError, 0, Qt::AlignmentFlag::AlignHCenter);

        label_14 = new QLabel(profileInfoForm);
        label_14->setObjectName("label_14");
        label_14->setMinimumSize(QSize(400, 0));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));

        verticalLayout_4->addWidget(label_14, 0, Qt::AlignmentFlag::AlignHCenter);

        widget_8 = new QWidget(profileInfoForm);
        widget_8->setObjectName("widget_8");
        horizontalLayout_7 = new QHBoxLayout(widget_8);
        horizontalLayout_7->setSpacing(20);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        oldPasswordInput = new QLineEdit(widget_8);
        oldPasswordInput->setObjectName("oldPasswordInput");
        oldPasswordInput->setMinimumSize(QSize(320, 0));
        oldPasswordInput->setMaximumSize(QSize(200, 16777215));
        oldPasswordInput->setFont(font);
        oldPasswordInput->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 10px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));
        oldPasswordInput->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_7->addWidget(oldPasswordInput);

        checkPasswordBtn = new QPushButton(widget_8);
        checkPasswordBtn->setObjectName("checkPasswordBtn");
        checkPasswordBtn->setMaximumSize(QSize(70, 16777215));
        checkPasswordBtn->setFont(font);
        checkPasswordBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        checkPasswordBtn->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color: \"#D3E8D2\";\n"
"border: none;\n"
"font-size: 14px;\n"
"border-radius: 16px;"));

        horizontalLayout_7->addWidget(checkPasswordBtn);


        verticalLayout_4->addWidget(widget_8, 0, Qt::AlignmentFlag::AlignHCenter);

        oldPasswordError = new QLabel(profileInfoForm);
        oldPasswordError->setObjectName("oldPasswordError");
        oldPasswordError->setMinimumSize(QSize(400, 0));
        oldPasswordError->setFont(font);
        oldPasswordError->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding-left: 5px;\n"
"color: red;"));

        verticalLayout_4->addWidget(oldPasswordError, 0, Qt::AlignmentFlag::AlignHCenter);

        label_15 = new QLabel(profileInfoForm);
        label_15->setObjectName("label_15");
        label_15->setMinimumSize(QSize(400, 0));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));

        verticalLayout_4->addWidget(label_15, 0, Qt::AlignmentFlag::AlignHCenter);

        newPasswordInput = new QLineEdit(profileInfoForm);
        newPasswordInput->setObjectName("newPasswordInput");
        newPasswordInput->setEnabled(false);
        newPasswordInput->setMinimumSize(QSize(400, 0));
        newPasswordInput->setFont(font);
        newPasswordInput->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 10px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));
        newPasswordInput->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_4->addWidget(newPasswordInput, 0, Qt::AlignmentFlag::AlignHCenter);

        newPasswordError = new QLabel(profileInfoForm);
        newPasswordError->setObjectName("newPasswordError");
        newPasswordError->setMinimumSize(QSize(400, 0));
        newPasswordError->setFont(font);
        newPasswordError->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding-left: 5px;\n"
"color: red;"));
        newPasswordError->setWordWrap(true);

        verticalLayout_4->addWidget(newPasswordError, 0, Qt::AlignmentFlag::AlignHCenter);

        label_2 = new QLabel(profileInfoForm);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(400, 0));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));

        verticalLayout_4->addWidget(label_2, 0, Qt::AlignmentFlag::AlignHCenter);

        addLinksBtn = new QPushButton(profileInfoForm);
        addLinksBtn->setObjectName("addLinksBtn");
        addLinksBtn->setMinimumSize(QSize(400, 0));
        addLinksBtn->setFont(font);
        addLinksBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addLinksBtn->setStyleSheet(QString::fromUtf8("text-align: left;\n"
"padding-left: 10px;\n"
"color: \"#5A9B61\";"));

        verticalLayout_4->addWidget(addLinksBtn, 0, Qt::AlignmentFlag::AlignHCenter);

        saveBtn = new QPushButton(profileInfoForm);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setMinimumSize(QSize(80, 0));
        saveBtn->setFont(font);
        saveBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        saveBtn->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color: \"#D3E8D2\";\n"
"border: none;\n"
"font-size: 14px;\n"
"border-radius: 16px;"));

        verticalLayout_4->addWidget(saveBtn, 0, Qt::AlignmentFlag::AlignHCenter);


        verticalLayout_5->addWidget(profileInfoForm);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_2->addWidget(scrollArea, 0, Qt::AlignmentFlag::AlignHCenter);

        privacySettings = new QWidget(widget_7);
        privacySettings->setObjectName("privacySettings");

        verticalLayout_2->addWidget(privacySettings);


        horizontalLayout_6->addWidget(widget_7);


        horizontalLayout->addWidget(widget_2);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Settings", nullptr));
        label->setText(QCoreApplication::translate("Settings", "Settings", nullptr));
        closeSettingsBtn->setText(QString());
        profileImageLabel->setText(QString());
        nameLabel->setText(QCoreApplication::translate("Settings", "User Name", nullptr));
        aboutLabel->setText(QCoreApplication::translate("Settings", "About User", nullptr));
        editBtn->setText(QString());
        logoutBtn->setText(QCoreApplication::translate("Settings", "Log Out", nullptr));
        deleteAccountBtn->setText(QCoreApplication::translate("Settings", "Delete Account", nullptr));
        label_16->setText(QString());
        label_17->setText(QCoreApplication::translate("Settings", "Privacy", nullptr));
        privacyBtn->setText(QString());
        label_9->setText(QCoreApplication::translate("Settings", "Profile Info", nullptr));
        profileImageLabel_2->setText(QString());
        addImageBtn->setText(QString());
        label_10->setText(QCoreApplication::translate("Settings", "First Name", nullptr));
        firstNameIn->setPlaceholderText(QCoreApplication::translate("Settings", "First Name", nullptr));
        firstNameError->setText(QString());
        label_11->setText(QCoreApplication::translate("Settings", "Last Name", nullptr));
        lastNameIn->setPlaceholderText(QCoreApplication::translate("Settings", "Last Name", nullptr));
        lastNameError->setText(QString());
        label_12->setText(QCoreApplication::translate("Settings", "Phone Number", nullptr));
        phoneNumberInput->setPlaceholderText(QCoreApplication::translate("Settings", "Phone Number", nullptr));
        phoneError->setText(QString());
        label_13->setText(QCoreApplication::translate("Settings", "About", nullptr));
        aboutInput->setPlaceholderText(QCoreApplication::translate("Settings", "About", nullptr));
        aboutError->setText(QString());
        label_14->setText(QCoreApplication::translate("Settings", "Old Password", nullptr));
        oldPasswordInput->setPlaceholderText(QCoreApplication::translate("Settings", "Old Password", nullptr));
        checkPasswordBtn->setText(QCoreApplication::translate("Settings", "Check", nullptr));
        oldPasswordError->setText(QString());
        label_15->setText(QCoreApplication::translate("Settings", "New Password", nullptr));
        newPasswordInput->setPlaceholderText(QCoreApplication::translate("Settings", "New Password", nullptr));
        newPasswordError->setText(QString());
        label_2->setText(QCoreApplication::translate("Settings", "Social Media Links", nullptr));
        addLinksBtn->setText(QCoreApplication::translate("Settings", "Add Links", nullptr));
        saveBtn->setText(QCoreApplication::translate("Settings", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
