#include "message.h"
#include <QScrollBar>
#include <QMouseEvent>

#include "ChatRoomModel.h"
using namespace std;
Message:: Message(MessageModel content,Message* Reply,QWidget *parent):
    QWidget(parent),Content(content),Reply(Reply) {
    connect(this,&Message::showMenu,this, &Message::showContextMenu);
}
Message:: Message(Message *Replycontent,QWidget *parent):
    QWidget(parent),Reply(Replycontent) {
}

void Message::Adjust(){

}

void Message::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        emit clicked(this);
    }else{
        emit showMenu(event->pos());
    }
}
void Message::setContent(MessageModel& content){

}

Message::~Message(){
}

bool Message::operator<(const Message &message) const {
    return Content.messageID < message.Content.messageID;
}

bool Message::operator==(const Message& message) const {
    return Content.messageID==message.Content.messageID;
}
