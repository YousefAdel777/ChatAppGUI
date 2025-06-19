#include "AboutG.h"
#include "ui_AboutG.h"
#include "MemberCard.h"
#include "User.h"
#include <iostream>

#include "Group.h"
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

    memberCards.clear();
    Group * group = static_cast<Group *>(ChatRoomModel::getChatRoomModel(GroupId).value());
    for (int userId : group->getUsers()) {
        User user = User::getUser(userId).value();
        auto card = new MemberCard(
            userId,
            group->getId(),
            user.getUserProfileDescription().getImagePath().c_str(),
            user.getFirstName().c_str()+QString(" ")+user.getLastName().c_str(),
            Group::roleToString(group->getRoleOf(userId)).c_str()
        );
        memberCards.push_back(card);
    }
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
    connect(a,&AddMembers::add,this,[=]{
        for(auto card:memberCards){
            contactLayout->addWidget(card);
            ++members;
        }
        contactLayout->addStretch();
        container->adjustSize();
        ui->MembersNo->setText(QString::number(members)+" Members");
        ui->scrollArea_2->widget()->updateGeometry();
    });
    User currUser = User::getCurrentUser().value();
    if (group->getRoleOf(currUser.getId()) != Group::OWNER) {
        ui->deleteBtn->setVisible(false);
    }
    else {
        connect(ui->deleteBtn, &QPushButton::clicked, this, [=] {
            group->deleteGroup();
            emit groupDeleted(group->getId());
        });
    }
    int currUserId = currUser.getId();
    connect(ui->leaveBtn, &QPushButton::clicked, this, [=] {
        group->Remove_Member(currUserId);
        group->save();
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
