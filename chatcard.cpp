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
    ChatRoomModel m =ChatRoomModel::getChatRoomModel(ChatRoomid).value();
    if(ChatRoomModel::getChatRoomModel(ChatRoomid).value().type){
        Group* g = dynamic_cast<Group*>(&m);
        setProfilePic(g->getImagePath().data());
        setName(g->getName().data());
    }else{
        setProfilePic(User::getUser(m.getUsers()[User::getCurrentUser()->getId()==m.getUsers()[0]])->getUserProfileDescription().getImagePath().data());
        setName(User::getUser(m.getUsers()[User::getCurrentUser()->getId()==m.getUsers()[0]])->getFirstName().data());
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
