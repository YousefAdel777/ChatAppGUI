#include "AboutG.h"
#include "ui_AboutG.h"
#include "MemberCard.h"
#include "User.h"
#include <iostream>
QVector<MemberCard*> AboutG::memberCards;
AboutG::AboutG(int GroupId,int OwnerId,string path,string name,string des,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AboutG)
{
    ui->setupUi(this);
    members = 0;
    QPixmap pix(path.c_str());
    ui->Photo->setPixmap(pix);
    ui->Photo->setScaledContents(true);
    ui->desc->setText(des.c_str());
    ui->name->setText(name.c_str());
    a = new AddMembers(GroupId);
    container = new QWidget();
    contactLayout = new QVBoxLayout(container);
    contactLayout->setSpacing(3);
    contactLayout->setContentsMargins(0,0,0,0);
    for(auto card:memberCards){
        contactLayout->addWidget(card);
        ++members;
    }
    auto card = new MemberCard(User::getCurrentUser()->getUserProfileDescription().getImagePath().c_str(),User::getCurrentUser()->getFirstName().c_str()+QString(" ")+User::getCurrentUser()->getLastName().c_str(),"Owner");
    memberCards.push_back(card);
    for(auto card:memberCards){
        contactLayout->addWidget(card);
        ++members;
    }
    contactLayout->addStretch();
    container->adjustSize();
    ui->MembersNo->setText(QString::number(members)+" Members");
    ui->scrollArea_2->widget()->updateGeometry();
    contactLayout->addStretch();
    container->setLayout(contactLayout);
    ui->scrollArea_2->setWidget(container);
    ui->scrollArea_2->setWidgetResizable(true);
    container->adjustSize();
    container->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Maximum);
    ui->MembersNo->setText(QString::number(members)+" Members");
    connect(a,&AddMembers::add,this,[=](){
        for(auto card:memberCards){
            contactLayout->addWidget(card);
            ++members;
        }
        contactLayout->addStretch();
        container->adjustSize();
        ui->MembersNo->setText(QString::number(members)+" Members");
        ui->scrollArea_2->widget()->updateGeometry();
    });
}

AboutG::~AboutG()
{
    delete ui;
}

void AboutG::on_addMember_clicked()
{
    a->show();
}

void AboutG::on_pushButton_3_clicked()
{

}

