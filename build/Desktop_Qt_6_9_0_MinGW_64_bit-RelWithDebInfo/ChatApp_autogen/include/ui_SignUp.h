/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *signUpForm;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *firstNameInput;
    QLabel *firstNameError;
    QLabel *label_5;
    QLineEdit *lastNameInput;
    QLabel *lastNameError;
    QLabel *label;
    QLineEdit *phoneInput;
    QLabel *phoneError;
    QLabel *label_2;
    QLineEdit *passwordInput;
    QLabel *passwordError;
    QLabel *loginError;
    QLabel *label_3;
    QPushButton *loginBtn;
    QPushButton *signUpBtn;

    void setupUi(QWidget *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName("SignUp");
        SignUp->resize(1280, 720);
        SignUp->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
""));
        horizontalLayout = new QHBoxLayout(SignUp);
        horizontalLayout->setObjectName("horizontalLayout");
        signUpForm = new QWidget(SignUp);
        signUpForm->setObjectName("signUpForm");
        signUpForm->setMaximumSize(QSize(320, 470));
        QFont font;
        font.setFamilies({QString::fromUtf8("Product Sans Medium")});
        signUpForm->setFont(font);
        signUpForm->setStyleSheet(QString::fromUtf8("background-color: \"#FBFDF6\";\n"
"border-radius: 20px;\n"
"padding: 0 20px;"));
        verticalLayout = new QVBoxLayout(signUpForm);
        verticalLayout->setObjectName("verticalLayout");
        label_4 = new QLabel(signUpForm);
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

        label_6 = new QLabel(signUpForm);
        label_6->setObjectName("label_6");
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(label_6);

        firstNameInput = new QLineEdit(signUpForm);
        firstNameInput->setObjectName("firstNameInput");
        firstNameInput->setFont(font);
        firstNameInput->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 8px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));

        verticalLayout->addWidget(firstNameInput);

        firstNameError = new QLabel(signUpForm);
        firstNameError->setObjectName("firstNameError");
        firstNameError->setFont(font);
        firstNameError->setStyleSheet(QString::fromUtf8("color: \"red\";\n"
"padding: 0;\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(firstNameError);

        label_5 = new QLabel(signUpForm);
        label_5->setObjectName("label_5");
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(label_5);

        lastNameInput = new QLineEdit(signUpForm);
        lastNameInput->setObjectName("lastNameInput");
        lastNameInput->setFont(font);
        lastNameInput->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 8px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));

        verticalLayout->addWidget(lastNameInput);

        lastNameError = new QLabel(signUpForm);
        lastNameError->setObjectName("lastNameError");
        lastNameError->setFont(font);
        lastNameError->setStyleSheet(QString::fromUtf8("color: \"red\";\n"
"padding: 0;\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(lastNameError);

        label = new QLabel(signUpForm);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 30));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(label);

        phoneInput = new QLineEdit(signUpForm);
        phoneInput->setObjectName("phoneInput");
        phoneInput->setMaximumSize(QSize(300, 16777210));
        phoneInput->setFont(font);
        phoneInput->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 8px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));

        verticalLayout->addWidget(phoneInput);

        phoneError = new QLabel(signUpForm);
        phoneError->setObjectName("phoneError");
        phoneError->setMaximumSize(QSize(16777215, 20));
        phoneError->setFont(font);
        phoneError->setStyleSheet(QString::fromUtf8("color: \"red\";\n"
"padding: 0;\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(phoneError);

        label_2 = new QLabel(signUpForm);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 20));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("padding: 0;\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(label_2);

        passwordInput = new QLineEdit(signUpForm);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setMaximumSize(QSize(300, 16777215));
        passwordInput->setFont(font);
        passwordInput->setStyleSheet(QString::fromUtf8("background-color: \"#E1ECE1\";\n"
"padding: 8px 5px;\n"
"border-radius: 10px;\n"
"font-size: 14px;"));
        passwordInput->setEchoMode(QLineEdit::EchoMode::Password);
        passwordInput->setDragEnabled(false);

        verticalLayout->addWidget(passwordInput);

        passwordError = new QLabel(signUpForm);
        passwordError->setObjectName("passwordError");
        passwordError->setFont(font);
        passwordError->setStyleSheet(QString::fromUtf8("color: \"red\";\n"
"padding: 0;\n"
"padding-left: 5px;"));
        passwordError->setWordWrap(true);

        verticalLayout->addWidget(passwordError);

        loginError = new QLabel(signUpForm);
        loginError->setObjectName("loginError");
        loginError->setFont(font);
        loginError->setStyleSheet(QString::fromUtf8("color: \"#ff0000\";\n"
"text-align: \"center\";\n"
"padding: 0;"));
        loginError->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(loginError);

        label_3 = new QLabel(signUpForm);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_3);

        loginBtn = new QPushButton(signUpForm);
        loginBtn->setObjectName("loginBtn");
        loginBtn->setFont(font);
        loginBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        loginBtn->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        verticalLayout->addWidget(loginBtn);

        signUpBtn = new QPushButton(signUpForm);
        signUpBtn->setObjectName("signUpBtn");
        signUpBtn->setMinimumSize(QSize(140, 28));
        signUpBtn->setMaximumSize(QSize(100, 45));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font2.setWeight(QFont::DemiBold);
        signUpBtn->setFont(font2);
        signUpBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        signUpBtn->setStyleSheet(QString::fromUtf8("border-radius: 10px; \n"
"background-color: \"#D3E8D2\";\n"
"padding: 5px;\n"
"font-weight: 600;"));

        verticalLayout->addWidget(signUpBtn, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);


        horizontalLayout->addWidget(signUpForm);


        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QWidget *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "SignUp", nullptr));
        label_4->setText(QCoreApplication::translate("SignUp", "Sign Up", nullptr));
        label_6->setText(QCoreApplication::translate("SignUp", "First Name", nullptr));
        firstNameInput->setPlaceholderText(QCoreApplication::translate("SignUp", "First Name", nullptr));
        firstNameError->setText(QString());
        label_5->setText(QCoreApplication::translate("SignUp", "Last Name", nullptr));
        lastNameInput->setPlaceholderText(QCoreApplication::translate("SignUp", "Last Name", nullptr));
        lastNameError->setText(QString());
        label->setText(QCoreApplication::translate("SignUp", "Phone Number", nullptr));
        phoneInput->setPlaceholderText(QCoreApplication::translate("SignUp", "Phone Number", nullptr));
        phoneError->setText(QString());
        label_2->setText(QCoreApplication::translate("SignUp", "Password", nullptr));
        passwordInput->setPlaceholderText(QCoreApplication::translate("SignUp", "Password", nullptr));
        passwordError->setText(QString());
        loginError->setText(QString());
        label_3->setText(QCoreApplication::translate("SignUp", "Already have an account ?", nullptr));
        loginBtn->setText(QCoreApplication::translate("SignUp", "Log In", nullptr));
        signUpBtn->setText(QCoreApplication::translate("SignUp", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
