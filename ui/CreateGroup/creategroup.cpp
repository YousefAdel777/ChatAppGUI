//
// Created by Dell on 5/18/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CreateGroup.h" resolved

#include "creategroup.h"

#include <QFileDialog>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>

#include "Group.h"
#include "ui_CreateGroup.h"


CreateGroup::CreateGroup(QWidget *parent) :
    QDialog(parent), ui(new Ui::CreateGroup) {
    ui->setupUi(this);
    ui->removeImageBtn->setVisible(false);
    connect(ui->removeImageBtn, &QPushButton::clicked, this, &CreateGroup::removeImage);
    connect(ui->addImageBtn, &QPushButton::clicked, this, &CreateGroup::uploadImage);
    connect(ui->addBtn, &QPushButton::clicked, this, &CreateGroup::on_create);
}

void CreateGroup::uploadImage() {
    QString filePath = QFileDialog::getOpenFileName(
        this,
        tr("Select Image"),
        "",
        tr("Image Files (*.png *.jpg)")
    );
    if (filePath.isEmpty()) return;

    QString dir = QString::fromStdString("../../src/data/images/groups");
    QDir().mkpath(dir);

    QString fileName = QFileInfo(filePath).fileName();
    QString destPath = dir + "/" + fileName;

    if (!QFile::copy(filePath, destPath)) {
        return;
    }

    string path = destPath.toStdString();
    setImage(path);
    imagePath = path;
}

void CreateGroup::setImage(string imagePath) {
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

    ui->groupImg->setPixmap(dest.scaled(85, 85));
    ui->removeImageBtn->setVisible(true);
}

void CreateGroup::removeImage() {
    ui->removeImageBtn->setVisible(false);
    imagePath = "";

    ui->groupImg->clear();

    QPixmap defaultImage;
    if (defaultImage.load(":/icons/group.png")) {
        ui->groupImg->setPixmap(defaultImage.scaled(
            85, 85,
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        ));
    }
}

void CreateGroup::on_create() {
    User user = User::getCurrentUser().value();
    ui->nameErr->setText("");
    ui->descErr->setText("");
    bool error = false;
    std::string desc = ui->descIn->text().toStdString();
    std::string name = ui->nameIn->text().toStdString();
    if (name.empty()) {
        ui->nameErr->setText("Group name is required");
        error = true;
    }
    if (desc.empty()) {
        ui->descErr->setText("Group Description is required");
        error = true;
    }
    if (error) return;
    emit groupCreated(Group::createGroup(name, user.getId(), imagePath, desc, true));
}

CreateGroup::~CreateGroup() {
    delete ui;
}
