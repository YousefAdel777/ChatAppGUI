#include "AddInGroup.h"
#include "ui_AddInGroup.h"
#include "User.h"
AddInGroup::AddInGroup(int id,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddInGroup)
{
    ui->setupUi(this);
    isChecked = 0;
    UserId = id;
    QPixmap pix(User::getUser(id)->getUserProfileDescription().getImagePath().c_str());
    ui->label->setPixmap(pix);
    ui->label->setScaledContents(true);
    ui->label_2->setText(QString(User::getUser(id)->getFirstName().c_str())+" "+ QString(User::getUser(id)->getFirstName().c_str()));
    photo = ui->label;
    name = ui->label_2;

}

AddInGroup::~AddInGroup()
{
    delete ui;
}

void AddInGroup::on_pushButton_clicked()
{
    if(!isChecked)
        ui->pushButton->setIcon(QIcon("C:/Users/ELKAYAN/OneDrive/Documents/ChatAppGUI/icons/check.png"));
    else
        ui->pushButton->setIcon(QIcon());
    isChecked^=1;
}

