#include "settings.h"

#include <QPushButton>
#include <QPainter>
#include <QPainterPath>
#include <QFileDialog>
#include <qgraphicseffect.h>

#include "ui_Settings.h"
#include "User.h"
#include "../Login/login.h"
#include "SocialLinksDialog/sociallinksdialog.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent), ui(new Ui::Settings) {
    ui->setupUi(this);
    showProfileInfoForm();

    optional<User> optCurrentUser = User::getCurrentUser();
    connect(ui->closeSettingsBtn, &QPushButton::clicked, this, &Settings::closeSettings);
    connect(ui->addImageBtn, &QPushButton::clicked, this, &Settings::uploadProfileImage);
    connect(ui->logoutBtn, &QPushButton::clicked, this, &Settings::handleLogout);
    connect(ui->deleteAccountBtn, &QPushButton::clicked, this, &Settings::handleDeleteProfile);
    connect(ui->privacyBtn, &QPushButton::clicked, this, &Settings::showPrivacy);
    connect(ui->editBtn, &QPushButton::clicked, this, &Settings::showProfileInfoForm);
    connect(ui->addLinksBtn, &QPushButton::clicked, this, &Settings::openLinksDialog);
    connect(ui->checkPasswordBtn, &QPushButton::clicked, this, &Settings::checkOldPassword);
    connect(ui->saveBtn, &QPushButton::clicked, this, &Settings::handleSave);

    if (optCurrentUser.has_value()) {
        User currentUser = optCurrentUser.value();
        string imagePath = currentUser.getUserProfileDescription().getImagePath();
        profileImagePath = imagePath;
        if (!imagePath.empty()) {
            initializeUserImage(imagePath);
        }
        UserProfileDescription userProfileDescription = currentUser.getUserProfileDescription();
        initializeAbout(currentUser.getUserProfileDescription().getAbout());
        initializeUsername(currentUser.getFirstName() + " " + currentUser.getLastName());
        initializeEditInputs(currentUser);
    }
    ui->newPasswordInput->setEnabled(false);
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(ui->newPasswordInput);
    effect->setOpacity(0.5);
    ui->newPasswordInput->setGraphicsEffect(effect);
}

void Settings::closeSettings() {
    this->close();
}

void Settings::initializeUserImage(string imagePath) {
    QPixmap src(QString::fromStdString(imagePath));

    QSize size = src.size();
    QPixmap dest(size);
    dest.fill(Qt::transparent);

    QPainter painter(&dest);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPainterPath path;
    path.addEllipse(0, 0, size.width(), size.height());
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, src);
    painter.end();

    ui->profileImageLabel->setPixmap(dest.scaled(85, 85));
    ui->profileImageLabel_2->setPixmap(dest.scaled(85, 85));
}

void Settings::handleLogout() {
    User::logout();
    Login *login = new Login;
    login->show();
    this->close();
}

void Settings::handleDeleteProfile() {
    User::getCurrentUser()->deleteAccount();
    Login *login = new Login;
    login->show();
    this->close();
}

void Settings::uploadProfileImage() {
    QString filePath = QFileDialog::getOpenFileName(
        this,
        tr("Select Image"),
        "",
        tr("Image Files (*.png *.jpg)")
    );
    if (filePath.isEmpty()) return;

    // QString destDir = QCoreApplication::applicationDirPath() + "/data/images";
    QString dir = QString::fromStdString("../../src/data/images");
    QDir().mkpath(dir);

    QString fileName = QFileInfo(filePath).fileName();
    QString destPath = dir + "/" + fileName;

    if (!QFile::copy(filePath, destPath)) {
        return;
    }

    string path = destPath.toStdString();
    initializeUserImage(filePath.toStdString());
    optional<User> optUser = User::getCurrentUser();
    if (optUser.has_value()) {
        User currentUser = optUser.value();
        profileImagePath = path;
        currentUser.getUserProfileDescription().setImagePath(path);
    }
}

void Settings::initializeAbout(string about) {
    ui->aboutLabel->setText(about.data());
}

void Settings::initializeUsername(string username) {
    ui->nameLabel->setText(username.data());
}

void Settings::showPrivacy() {
    ui->profileInfoForm->setVisible(false);
    ui->privacySettings->setVisible(true);
}

void Settings::showProfileInfoForm() {
    ui->profileInfoForm->setVisible(true);
    ui->privacySettings->setVisible(false);
}

void Settings::initializeEditInputs(User &user) {
    ui->firstNameIn->setText(user.getFirstName().data());
    ui->lastNameIn->setText(user.getLastName().data());
    ui->phoneNumberInput->setText(user.getMobileNumber().data());
    ui->aboutInput->setText(user.getUserProfileDescription().getAbout().data());
}

bool Settings::checkOldPassword() {
    ui->oldPasswordError->setText("");
    ui->newPasswordInput->setEnabled(false);
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(ui->newPasswordInput);
    effect->setOpacity(0.5);
    ui->newPasswordInput->setGraphicsEffect(effect);
    string oldPassword = ui->oldPasswordInput->text().toStdString();
    if (oldPassword.empty()) {
        ui->oldPasswordError->setText("Old password is required");
        return false;
    };
    optional<User> optUser = User::getCurrentUser();
    if (!optUser.has_value()) return false;
    User user = optUser.value();
    bool isValid = bcrypt::validatePassword(oldPassword, user.getPassword());
    if (!isValid) {
        ui->oldPasswordError->setText("Wrong password");
    }
    else {
        ui->newPasswordInput->setEnabled(true);
        QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(ui->newPasswordInput);
        effect->setOpacity(1);
        ui->newPasswordInput->setGraphicsEffect(effect);
    }
    return isValid;
}

void Settings::openLinksDialog() {
    SocialLinksDialog *linksDialog = new SocialLinksDialog();
    linksDialog->show();
}

void Settings::handleSave() {
    optional<User> optUser = User::getCurrentUser();
    if (!optUser.has_value()) return;
    User user = optUser.value();
    bool isError = false;

    ui->firstNameError->setText("");
    ui->lastNameError->setText("");
    ui->phoneError->setText("");
    ui->oldPasswordError->setText("");
    ui->newPasswordError->setText("");

    string firstName = ui->firstNameIn->text().toStdString();
    string lastName = ui->lastNameIn->text().toStdString();
    string mobileNumber = ui->phoneNumberInput->text().toStdString();
    string about = ui->aboutInput->text().toStdString();
    string oldPassword = ui->oldPasswordInput->text().toStdString();
    string newPassword = ui->newPasswordInput->text().toStdString();

    if (firstName.empty()) {
        ui->firstNameError->setText("First name is required");
        isError = true;
    }
    if (lastName.empty()) {
        ui->lastNameError->setText("Last name is required");
        isError = true;
    }
    else if (mobileNumber.empty()) {
        ui->phoneError->setText("Phone number is required");
        isError = true;
    }
    else if (!User::validateMobileNumber(mobileNumber)) {
        ui->phoneError->setText("Invalid phone number");
        isError = true;
    }
    if (isError) return;
    user.setFirstName(firstName);
    user.setLastName(lastName);
    user.setMobileNumber(mobileNumber);
    user.getUserProfileDescription().setAbout(about);
    user.getUserProfileDescription().setImagePath(profileImagePath);
    if (!newPassword.empty()) {
        if (User::validatePassword(newPassword)) {
            user.setPassword(bcrypt::generateHash(newPassword));
        }
        else {
            ui->newPasswordError->setText("Password must be at least 8 characters and include uppercase, lowercase, number, and special character");
        }
    }
    user.save();
    User::setCurrentUser(user);
    initializeAbout(about);
    initializeUsername(user.getFirstName() + " " + user.getLastName());

    ui->newPasswordInput->setEnabled(false);
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(ui->newPasswordInput);
    effect->setOpacity(1);
    ui->newPasswordInput->setText("");
}

Settings::~Settings() {
    delete ui;
}
