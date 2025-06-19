#include "MemberCard.h"

#include "Group.h"
#include "ui_MemberCard.h"
#include "User.h"

MemberCard::MemberCard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MemberCard)
{
    ui->setupUi(this);
}
MemberCard::MemberCard(int userId, int groupId, QString path,
                       QString name,
                       QString role,
                       QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MemberCard), userId(userId), groupId(groupId)
{
    ui->setupUi(this);
    QPixmap p(path);
    if (!p.isNull()) {
        ui->label->setPixmap(p);
    }
    ui->label_2->setText(name);
    ui->pushButton->setText(role);
    Group * g = static_cast<Group *>(ChatRoomModel::getChatRoomModel(groupId).value());
    int currUserId = User::getCurrentUser()->getId();
    if (userId == User::getCurrentUser()->getId() || (g->getRoleOf(currUserId) != Group::OWNER && g->getRoleOf(currUserId) != Group::ADMIN)) {
        ui->removeBtn->setVisible(false);
    }
    else {
        connect(ui->removeBtn, &QPushButton::clicked, this, &MemberCard::on_remove);
    }
}
MemberCard::~MemberCard()
{
    delete ui;
}

void MemberCard::on_remove() {
    Group * g = static_cast<Group *>(ChatRoomModel::getChatRoomModel(groupId).value());
    int currUserId = User::getCurrentUser()->getId();
    if (g->getRoleOf(currUserId) != Group::OWNER && g->getRoleOf(currUserId) != Group::ADMIN) {
        return;
    }
    if (g->getRoleOf(currUserId) == Group::ADMIN && g->getRoleOf(userId) == Group::ADMIN) {
        return;
    }
    g->Remove_Member(userId);
    this->deleteLater();
}

void MemberCard::on_pushButton_clicked()
{
    if(ui->pushButton->text()=="Owner") return;
    Group * g = static_cast<Group *>(ChatRoomModel::getChatRoomModel(groupId).value());
    int currUserId = User::getCurrentUser()->getId();
    if (currUserId == userId || (g->getRoleOf(currUserId) != Group::OWNER && g->getRoleOf(currUserId) != Group::ADMIN)) {
        return;
    }
    if (g->getRoleOf(userId) == Group::MEMBER) {
        ui->pushButton->setText("Admin");
        g->Change_Member_Role(userId, Group::ADMIN);
    }
    else {
        if (g->getRoleOf(currUserId) == Group::OWNER) {
            ui->pushButton->setText("Member");
            g->Change_Member_Role(userId, Group::MEMBER);
        }
    }
    g->save();
}

