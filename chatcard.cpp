#include "chatcard.h"
#include "ui_chatcard.h"
#include "./utilities.h"
#include <ChatRoomModel.h>
#include <Group.h>
#include <QLayout>

chatcard::chatcard(int ChatRoomid,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chatcard)
    ,ChatRoomId(ChatRoomid)
{
    ui->setupUi(this);
    optional<ChatRoomModel*> opt_m = ChatRoomModel::getChatRoomModel(ChatRoomid);
    ChatRoomModel* m = nullptr;
    if (opt_m.has_value()) {
        m = opt_m.value();
    }
    if (m!=nullptr) {
        if(m->type){
            Group* g = static_cast<Group*>(m);
            setProfilePic(g->getImagePath().data());
            setName(g->getName().data());
        }else{
            setProfilePic(User::getUser(m->getUsers()[User::getCurrentUser()->getId()==m->getUsers()[0]])->getUserProfileDescription().getImagePath().data());
            setName(User::getUser(m->getUsers()[User::getCurrentUser()->getId()==m->getUsers()[0]])->getFirstName().data());
        }
    }
}

void chatcard::mousePressEvent(QMouseEvent *event){
    if(current){
        current->setStyleSheet(defaultStyle.data());
    }
    setStyleSheet(currentStyle.data());
    current = this;
    emit clicked(ChatRoomId);
}

void chatcard::setProfilePic(QString Pic) {
    setRoundImage(ui->ProfilePic, Pic);
}

void chatcard::setName(QString n) {
    ui->name->setText(n);
}

chatcard::~chatcard()
{
    delete ui;
}
