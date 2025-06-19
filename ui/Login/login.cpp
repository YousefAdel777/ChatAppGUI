#include "login.h"

#include <QPushButton>
#include <QGraphicsDropShadowEffect>

#include "mainwindow.h"
#include "ui_login.h"
#include "User.h"
#include "../Settings/settings.h"
#include "../SignUp/signup.h"
using namespace std;

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(30);
    shadow->setOffset(0, 5);
    shadow->setColor(QColor(0, 0, 0, 50));
    ui->loginForm->setGraphicsEffect(shadow);

    connect(ui->loginBtn, &QPushButton::clicked, this, &Login::handleLogin);
    connect(ui->signUpBtn, &QPushButton::clicked, this, &Login::redirectToSignUp);
}

void Login::handleLogin() {

    ui->phoneError->setText("");
    ui->passwordError->setText("");
    ui->loginError->setText("");

    string mobileNumber = ui->phoneInput->text().toStdString();
    string password = ui->passwordInput->text().toStdString();
    bool error = false;

    if (mobileNumber.empty()) {
        ui->phoneError->setText("Phone number is required");
        error = true;
    }
    if (!User::validateMobileNumber(mobileNumber)) {
        ui->phoneError->setText("Invalid phone number");
        error = true;
    }
    if (password.empty()) {
        ui->passwordError->setText("Password is required");
        error = true;
    }
    if (error) return;
    if (!User::login(mobileNumber, password)) {
        ui->loginError->setText("Invalid Credentials");
        return;
    }
    MainWindow *main_window = new MainWindow;
    main_window->show();
    this->close();
}

void Login::redirectToSignUp() {
    SignUp * signUp = new SignUp();
    signUp->show();
    this->close();
}

Login::~Login() {
    delete ui;
}
