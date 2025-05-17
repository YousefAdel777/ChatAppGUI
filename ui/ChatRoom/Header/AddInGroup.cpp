#include "AddInGroup.h"
#include "ui_AddInGroup.h"

AddInGroup::AddInGroup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddInGroup)
{
    ui->setupUi(this);
    isChecked = 0;
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

