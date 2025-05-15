#include "sociallinksdialog.h"

#include <QLineEdit>
#include <QPushButton>
#include <QStyle>
#include<QLabel>

#include "ui_SocialLinksDialog.h"
#include "../../Login/login.h"
#include "../../Settings/settings.h"


SocialLinksDialog::SocialLinksDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::SocialLinksDialog) {
    ui->setupUi(this);

    connect(ui->addBtn, &QPushButton::clicked, this, &SocialLinksDialog::handleAdd);
    connect(ui->saveBtn, &QPushButton::clicked, this, &SocialLinksDialog::handleSave);
    optional<User> optionalUser = User::getCurrentUser();
    if (optionalUser.has_value()) {
        User user = optionalUser.value();
        links = user.getUserProfileDescription().getSocialMediaLinks();
        for (int i = 0; i < links.size(); ++i) errors.push_back("");
        initializeLinks();
    }

}

void SocialLinksDialog::handleAdd() {
    if (links.empty()) ui->noLinks->setVisible(false);
    links.push_back("");
    errors.push_back("");
    createLinkInput(links.size(), "");
}

void SocialLinksDialog::handleSave() {
    bool isError = false;
    for (int i = 0; i < links.size(); i++) {
        errors[i] = "";
        QLineEdit *linkInput = ui->linksContainer->findChild<QLineEdit*>("linkInput_" + QString::number(i + 1));
        links[i] = linkInput->text().toStdString();
        if (links[i].empty()) {
            errors[i] = "This field is required";
            isError = true;
        }
        else if (!validateUrl(links[i])) {
            errors[i] = "Invalid URL";
            isError = true;
        }
    }
    if (isError) {
        initializeErrors(errors);
        return;
    };
    optional<User> optionalUser = User::getCurrentUser();
    if (optionalUser.has_value()) {
        optionalUser.value().getUserProfileDescription().setSocialMediaLinks(links);
        User user = optionalUser.value();
        user.getUserProfileDescription().setSocialMediaLinks(links);
        user.save();
        User::setCurrentUser(user);
        handleClose();
    }
}

void SocialLinksDialog::handleClose() {
    this->close();
}

void SocialLinksDialog::initializeLinks() {
    QList<QWidget*> children = ui->linksContainer->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly);
    for (QWidget* child : children) {
        if (child->objectName() != "noLinks") {
            child->deleteLater();
        }
    }
    if (links.empty()) {
        ui->noLinks->setVisible(true);
    }
    else {
        ui->noLinks->setVisible(false);
    }
    for (int i = 0; i < links.size(); ++i) {
        createLinkInput(i + 1, links[i]);
    }
}

void SocialLinksDialog::initializeErrors(vector<string> errors) {
    for (int i = 0; i < errors.size(); ++i) {
        QLabel* label = ui->linksContainer->findChild<QLabel*>("errorLabel_" + QString::number(i + 1));
        label->setText("");
        if (!errors[i].empty()) {
            label->setText(errors[i].data());
        }
    }
}

void SocialLinksDialog::createLinkInput(int count, string link) {
    QLabel *label = new QLabel("Social Media Link " + QString::number(count), ui->linksContainer);
    label->setStyleSheet("padding: 0;\n padding-left: 5px;\n font-family: 'Product Sans Medium';");
    label->setMaximumSize(400, 40);
    label->setMinimumSize(400, 40);

    QLineEdit * lineEdit = new QLineEdit(ui->linksContainer);
    lineEdit->setText(QString::fromStdString(link));
    lineEdit->setPlaceholderText("Social Media Link " + QString::number(count));
    lineEdit->setStyleSheet("background-color: #E1ECE1;\n padding: 10px 5px;\n border-radius: 10px;\n font-size: 14px;\n font-family: 'Product Sans Medium';");
    lineEdit->setObjectName("linkInput_" + QString::number(count));
    lineEdit->setMinimumSize(400, 40);

    QWidget* widget = new QWidget(ui->linksContainer);
    widget->setLayout(new QHBoxLayout());
    widget->setMinimumSize(400, 60);

    QLabel *errorLabel = new QLabel(widget);
    errorLabel->setStyleSheet("color: red;\n padding: 0;\n padding-left: 5px;\n font-family: 'Product Sans Medium';");
    errorLabel->setObjectName("errorLabel_" + QString::number(count));
    errorLabel->setMaximumSize(400, 40);
    errorLabel->setMinimumSize(400, 40);

    QPushButton *deleteBtn = new QPushButton(widget);
    deleteBtn->setIcon(QIcon::fromTheme("edit-delete"));
    deleteBtn->setCursor(Qt::CursorShape::PointingHandCursor);

    connect(deleteBtn, &QPushButton::clicked, this, [this, count] {
        links.erase(links.begin() + (count - 1));
        errors.erase(errors.begin() + (count - 1));
        initializeLinks();
    });

    widget->layout()->addWidget(lineEdit);
    widget->layout()->addWidget(deleteBtn);


    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->linksContainer->layout());
    if (layout) {
        layout->addWidget(wrapCentered(label));
        layout->addWidget(wrapCentered(widget));
        layout->addWidget(wrapCentered(errorLabel));
    }

}

bool SocialLinksDialog::validateUrl(string url) {
    const regex urlRegex(R"(^(https?|ftp):\/\/[^\s/$.?#].[^\s]*$)", regex::icase);
    return regex_match(url, urlRegex);
}

QWidget* SocialLinksDialog::wrapCentered(QWidget * widget) {
    QWidget *container = new QWidget(ui->linksContainer);
    QHBoxLayout *hLayout = new QHBoxLayout(container);
    hLayout->addStretch();
    hLayout->addWidget(widget);
    hLayout->addStretch();
    hLayout->setContentsMargins(0, 0, 0, 0);
    container->setLayout(hLayout);
    return container;
}

SocialLinksDialog::~SocialLinksDialog() {
    delete ui;
}
