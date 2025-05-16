#include "messagereceived.h"
#include <QTime>
#include "Helper.h"
MessageReceived::MessageReceived(int userId,Message *MessageBubble,QWidget *parent ):
    Message(MessageBubble->Content,MessageBubble->Reply,parent){
    this->MessageBubble = MessageBubble;

    ProfilePhoto = new QLabel(this);
    auto x = QTime(Content.getStatus().getDeliveryTime().tm_hour,Content.getStatus().getDeliveryTime().tm_min,Content.getStatus().getDeliveryTime().tm_sec);

    SentTime = new QLabel(x.toString("hh:mm AP"),this);
    MessageBubble->setParent(this);
    //handle photo
    auto rounded = Helper::getRoundedPixmap("2.png",50);
    ProfilePhoto->setPixmap(rounded);
    ProfilePhoto->setFixedSize(rounded.size());

    // styling
    SentTime->setStyleSheet("font-size:10; color:#424941;");
    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);

    Adjust();
    // Geometry prepare
    ProfilePhoto->setGeometry(QRect(10,SentTime->sizeHint().height(),50,50));
    SentTime->setGeometry(QRect(ProfilePhoto->geometry().right()+10,5,SentTime->sizeHint().width(),SentTime->sizeHint().height()));
    MessageBubble->setGeometry(QRect(ProfilePhoto->geometry().right()+10,SentTime->geometry().bottom()+3,MessageBubble->sizeHint().width(),MessageBubble->sizeHint().height()));
}

void MessageReceived::Adjust(){
    MessageBubble->setFixedWidth(width()-70);
    setFixedHeight(max(80,MessageBubble->height()+20));
}

void MessageReceived::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    Adjust();
}
