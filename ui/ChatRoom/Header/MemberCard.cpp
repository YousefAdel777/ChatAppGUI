#include "MemberCard.h"
#include "ui_MemberCard.h"

MemberCard::MemberCard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MemberCard)
{
    ui->setupUi(this);
}
MemberCard::MemberCard(QString path,
                       QString name,
                       QString role,
                       QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MemberCard)
{
    ui->setupUi(this);
    QPixmap p(path);
    if (!p.isNull()) {
        ui->label->setPixmap(p);
    }
    ui->label_2->setText(name);
    ui->pushButton->setText(role);
}
MemberCard::~MemberCard()
{
    delete ui;
}
