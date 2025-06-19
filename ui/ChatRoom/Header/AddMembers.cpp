#include "AddMembers.h"
#include "ui_AddMembers.h"
#include "AddInGroup.h"
#include<QVector>
#include"AboutG.h"
#include "User.h"
#include "ChatRoom.h"
#include "Group.h"
using namespace std;
AddMembers::AddMembers(int id,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddMembers)
{
    ui->setupUi(this);
    GroupId = id;
    container = new QWidget();
    contactLayout = new QVBoxLayout(container);
    contactLayout->setSpacing(3);
    contactLayout->setContentsMargins(0,0,0,0);
    Group * g = static_cast<Group *>(ChatRoomModel::getChatRoomModel(GroupId).value());
    for(auto userId : User::getCurrentUser()->getContacts()){
        if (!g->isMember(userId)) {
            AddInGroup *m = new AddInGroup(userId);
            contactLayout->addWidget(m);
        }
    } 
    contactLayout->addStretch();
    container->setLayout(contactLayout);
    ui->scrollArea->setWidget(container);
    ui->scrollArea->setWidgetResizable(true);
    container->adjustSize();
    container->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Maximum);
}

AddMembers::~AddMembers()
{
    delete ui;
}

void AddMembers::on_added_clicked()
{
    QVector<MemberCard*>members;
    for (int i = 0; i < contactLayout->count(); ++i) {
        QLayoutItem* item = contactLayout->itemAt(i);
        if (!item)
            continue;
        if (QWidget* w = item->widget()) {
            if (AddInGroup* card = qobject_cast<AddInGroup*>(w)) {
                if (card->isChecked) {
                    User user =  User::getUser(card->UserId).value();

                    Group * g = static_cast<Group *>(ChatRoomModel::getChatRoomModel(GroupId).value());
                    members.push_back(new MemberCard(card->UserId, GroupId, card->photo->property("imagepath").toString(),card->name->text(),Group::roleToString(g->getRoleOf(user.getId())).c_str()));
                    g->Add_Member(card->UserId);
                    g->save();
                    //TODO
                    //curGroup.addMemeber(card->UserId);
                }
            }
        }
    }
    clearLayout(contactLayout);
    AboutG::memberCards = members;
    close();
    emit add();
}
void AddMembers::clearLayout(QLayout *layout) {
    for (int i = layout->count() - 1; i >= 0; --i) {
        QLayoutItem *item = layout->itemAt(i);
        if (!item)
            continue;
        if (QWidget *w = item->widget()) {
            if (auto *card = qobject_cast<AddInGroup *>(w)) {
                if (card->isChecked) {
                    layout->takeAt(i);
                }
            }
        }
    }
}
