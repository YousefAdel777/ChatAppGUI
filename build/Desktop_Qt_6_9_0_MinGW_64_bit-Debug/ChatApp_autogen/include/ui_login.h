/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QWidget *loginForm;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *phoneInput;
    QLabel *phoneError;
    QLabel *label_2;
    QLineEdit *passwordInput;
    QLabel *passwordError;
    QLabel *loginError;
    QLabel *label_3;
    QPushButton *signUpBtn;
    QPushButton *loginBtn;
    QWidget *widget_3;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(1280, 720);
        QFont font;
        font.setFamilies({QString::fromUtf8("Product Sans Medium")});
        Login->setFont(font);
        Login->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";"));
        horizontalLayout = new QHBoxLayout(Login);
        horizontalLayout->setObjectName("horizontalLayout");
        widget_2 = new QWidget(Login);
        widget_2->setObjectName("widget_2");

        horizontalLayout->addWidget(widget_2);

        loginForm = new QWidget(Login);
        loginForm->setObjectName("loginForm");
        loginForm->setMaximumSize(QSize(300, 320));
        loginForm->setStyleSheet(QString::fromUtf8("background-color: \"#FBFDF6\";\n"
"border-radius: 20px;\n"
"padding: 0 20px;"));
        verticalLayout = new QVBoxLayout(loginForm);
        verticalLayout->setObjectName("verticalLayout");
        label_4 = new QLabel(loginForm);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(0, 40));
        label_4->setMaximumSize(QSize(16777215, 60));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font1.setBold(true);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-weight: bold;\n"
"padding: 0;\n"
"text-align: center;"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_4);

        label = new QLabel(loginForm);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 30));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(label);

        phoneInput = new QLineEdit(loginForm);
        phoneInput->setObjectName("phoneInput");
        phoneInput->setMaximumSize(QSize(300, 16777215));
        phoneInput->setFont(font);
        phoneInput->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 10px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));

        verticalLayout->addWidget(phoneInput);

        phoneError = new QLabel(loginForm);
        phoneError->setObjectName("phoneError");
        phoneError->setMaximumSize(QSize(16777215, 20));
        phoneError->setFont(font);
        phoneError->setStyleSheet(QString::fromUtf8("color: \"red\";\n"
"padding: 0;\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(phoneError);

        label_2 = new QLabel(loginForm);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 20));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(label_2);

        passwordInput = new QLineEdit(loginForm);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setMaximumSize(QSize(300, 16777215));
        passwordInput->setFont(font);
        passwordInput->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 10px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));
        passwordInput->setEchoMode(QLineEdit::EchoMode::Password);
        passwordInput->setDragEnabled(false);

        verticalLayout->addWidget(passwordInput);

        passwordError = new QLabel(loginForm);
        passwordError->setObjectName("passwordError");
        passwordError->setFont(font);
        passwordError->setStyleSheet(QString::fromUtf8("color: \"red\";\n"
"padding: 0;\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(passwordError);

        loginError = new QLabel(loginForm);
        loginError->setObjectName("loginError");
        loginError->setFont(font);
        loginError->setStyleSheet(QString::fromUtf8("color: \"#ff0000\";\n"
"text-align: \"center\";\n"
"padding: 0;"));
        loginError->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(loginError);

        label_3 = new QLabel(loginForm);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_3);

        signUpBtn = new QPushButton(loginForm);
        signUpBtn->setObjectName("signUpBtn");
        signUpBtn->setFont(font);
        signUpBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        signUpBtn->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        verticalLayout->addWidget(signUpBtn);

        loginBtn = new QPushButton(loginForm);
        loginBtn->setObjectName("loginBtn");
        loginBtn->setMinimumSize(QSize(140, 28));
        loginBtn->setMaximumSize(QSize(100, 50));
        loginBtn->setFont(font1);
        loginBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        loginBtn->setStyleSheet(QString::fromUtf8("border-radius: 12px; \n"
"background-color: \"#D3E8D2\";\n"
"padding: 5px;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(loginBtn, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);


        horizontalLayout->addWidget(loginForm);

        widget_3 = new QWidget(Login);
        widget_3->setObjectName("widget_3");

        horizontalLayout->addWidget(widget_3);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Log In", nullptr));
        label_4->setText(QCoreApplication::translate("Login", "Log In", nullptr));
        label->setText(QCoreApplication::translate("Login", "Phone Number", nullptr));
        phoneInput->setPlaceholderText(QCoreApplication::translate("Login", "Phone Number", nullptr));
        phoneError->setText(QString());
        label_2->setText(QCoreApplication::translate("Login", "Password", nullptr));
        passwordInput->setPlaceholderText(QCoreApplication::translate("Login", "Password", nullptr));
        passwordError->setText(QString());
        loginError->setText(QString());
        label_3->setText(QCoreApplication::translate("Login", "Don't have an account ?", nullptr));
        signUpBtn->setText(QCoreApplication::translate("Login", "Sign Up", nullptr));
        loginBtn->setText(QCoreApplication::translate("Login", "Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
