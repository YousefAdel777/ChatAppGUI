#include "messagesent.h"
#include <QTime>
#include <QVBoxLayout>
#include <iostream>
using namespace std;
#include "Helper.h"
MessageSent::MessageSent(int userId,Message *MessageBubble,QWidget *parent ):
    Message(MessageBubble->Content,MessageBubble->Reply,parent){
    this->MessageBubble = MessageBubble;
    ProfilePhoto = new QLabel(this);
    auto x = QTime(Content.getStatus().getDeliveryTime().tm_hour,Content.getStatus().getDeliveryTime().tm_min,Content.getStatus().getDeliveryTime().tm_sec);
    cout<<Content.getStatus().getDeliveryTime().tm_hour<<endl;
    SentTime = new QLabel(x.toString("hh:mm AP"),this);
    MessageBubble->setParent(this);
    //handle photo
    auto rounded = Helper::getRoundedPixmap("2.png",50);
    ProfilePhoto->setPixmap(rounded);
    ProfilePhoto->setFixedSize(rounded.size());

    // styling
    SentTime->setStyleSheet("font-size:10; color:#424941;");
    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
}

void MessageSent::Adjust(){
    MessageBubble->setFixedWidth(max(width()-70,70));
    MessageBubble->Adjust();
    ProfilePhoto->setGeometry(QRect(width()-60,SentTime->sizeHint().height(),50,50));
    SentTime->setGeometry(QRect(ProfilePhoto->geometry().left()-SentTime->sizeHint().width()-10,5,SentTime->sizeHint().width(),SentTime->sizeHint().height()));
    MessageBubble->setGeometry(QRect(ProfilePhoto->geometry().left()-MessageBubble->width()-10,SentTime->geometry().bottom()+3,MessageBubble->width(),MessageBubble->height()));
    setFixedHeight(max(70,MessageBubble->height()+15));
}

void MessageSent::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    Adjust();
}


MessageSent::~MessageSent(){
}
