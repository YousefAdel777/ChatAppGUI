//
// Created by Dell on 5/1/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SignUp.h" resolved

#include "signup.h"

#include <QGraphicsDropShadowEffect>
#include <QPushButton>

#include "mainwindow.h"
#include "ui_SignUp.h"
#include "../Login/login.h"
#include "User.h"
#include "../Settings/settings.h"

using namespace std;


SignUp::SignUp(QWidget *parent) :
    QWidget(parent), ui(new Ui::SignUp) {
    ui->setupUi(this);

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(30);
    shadow->setOffset(0, 5);
    shadow->setColor(QColor(0, 0, 0, 50));
    ui->signUpForm->setGraphicsEffect(shadow);

    connect(ui->loginBtn,  &QPushButton::clicked, this, &SignUp::redirectToLogin);
    connect(ui->signUpBtn, &QPushButton::clicked, this, &SignUp::handleSignUp);
}

void SignUp::handleSignUp() {
    ui->phoneError->setText("");
    ui->passwordError->setText("");
    ui->loginError->setText("");
    ui->firstNameError->setText("");
    ui->lastNameError->setText("");

    string mobileNumber = ui->phoneInput->text().toStdString();
    string password = ui->passwordInput->text().toStdString();
    string firstName = ui->firstNameInput->text().toStdString();
    string lastName = ui->lastNameInput->text().toStdString();
    bool error = false;

    if (firstName.empty()) {
        ui->firstNameError->setText("First name is required");
        error = true;
    }
    if (lastName.empty()) {
        ui->lastNameError->setText("Last name is required");
        error = true;
    }
    if (mobileNumber.empty()) {
        ui->phoneError->setText("Phone number is required");
        error = true;
    }
    else if (!User::validateMobileNumber(mobileNumber)) {
        ui->phoneError->setText("Invalid phone number");
        error = true;
    }
    if (password.empty()) {
        ui->passwordError->setText("Password is required");
        error = true;
    }
    else if (!User::validatePassword(password)) {
        ui->passwordError->setText("Password must be at least 8 characters and include uppercase, lowercase, number, and special character");
        error = true;
    }
    if (error) return;
    UserProfileDescription userProfileDescription("", "", {}, true);
    bool success = User::signUp(mobileNumber, firstName, lastName, password, userProfileDescription);
    if (!success) {
        ui->loginError->setText("A user with that phone number exists");
        return;
    }
    MainWindow *main_window = new MainWindow;
    main_window->show();
    this->close();
};

void SignUp::redirectToLogin() {
    Login *login = new Login();
    login->show();
    this->close();
}

SignUp::~SignUp() {
    delete ui;
}
