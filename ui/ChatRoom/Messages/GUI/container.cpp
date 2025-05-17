#include "container.h"
#include "ui_container.h"
#include "messagereceived.h"
#include "imagemessage.h"
#include "replyimagemessage.h"
#include "replytextmessage.h"
#include "replyvoicemessage.h"
#include "replydocumentmessage.h"
#include <algorithm>
#include <QScrollBar>
#include <ChatRoom.h>
#include "AttachmentCard.h"
#include <QPropertyAnimation>

#include "messagesent.h"
#include <iostream>
using namespace std;
Container::Container(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Container)
{
    ui->setupUi(this);
    ui->verticalLayout->setAlignment(Qt::AlignTop);
    CurrentPlayed = nullptr;
    cancelReplyButton = nullptr;
}

Container::~Container()
{
    delete ui;
}

void Container::ShowReply(){
    if(parentWidget()){
        ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
        CurrentReply->setParent(parentWidget());
        cancelReplyButton = new QPushButton(parentWidget());
        cancelReplyButton->setStyleSheet("background-color:rgb(70,70,70);border-radius:15;border:0;");
        cancelReplyButton->setIcon(QIcon(":/Resources/delete.png"));
        cancelReplyButton->setIconSize(QSize(20,20));
        cancelReplyButton->setFixedSize(41,31);
        connect(cancelReplyButton,&QPushButton::clicked,this,[=](){
            ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
            CurrentReply->setParent(nullptr);
            delete CurrentReply;
            CurrentReply = nullptr;
            cancelReplyButton->setParent(nullptr);
            delete cancelReplyButton;
            emit chat->sendBar->sizeChanged();
        });
        CurrentReply->setGeometry(chat->sendBar->geometry().left()+15,chat->sendBar->geometry().top()-CurrentReply->height()+10,chat->sendBar->width()-60,CurrentReply->geometry().height());
        cancelReplyButton->setGeometry(CurrentReply->geometry().right()-30,chat->sendBar->geometry().top()-CurrentReply->height()+10,cancelReplyButton->width(),cancelReplyButton->height());
        CurrentReply->show();
        cancelReplyButton->show();
        emit chat->sendBar->sizeChanged();
    }
}
void Container::AddLeft(Message* msg){
    ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
    messages.insert(msg);
    ui->verticalLayout->addWidget(msg,0,Qt::AlignLeft);
    msg->setFixedWidth(min(570,int(width()*0.7)));
    msg->Adjust();
    msg->MessageBubble->pos = h;
    h+=msg->height();
    connect(msg,&Message::MessageDeleted,this,[=](Message* msg){
        if(msg->Content.userID==User::getCurrentUser()->getId()){
            chat->model->removeMessage(msg->Content.messageID);
            ui->verticalLayout->removeWidget(msg);
            msg->setParent(nullptr);
            msg->deleteLater();
        }
        else{
            chat->model->removeMessage(msg->Content.messageID);
            msg->Content.status.setDeletedFor(User::getCurrentUser()->getId());
            chat->model->addMessage(msg->Content);
            ui->verticalLayout->removeWidget(msg);
            msg->setParent(nullptr);
            msg->deleteLater();
        }
    });
}
void Container::AddRight(Message* msg){
    ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
    messages.insert(msg);
    ui->verticalLayout->addWidget(msg,0,Qt::AlignRight);
    msg->setFixedWidth(min(570,int(width()*0.7)));
    msg->Adjust();
    msg->MessageBubble->pos = h;
    h+=msg->height();
    connect(msg,&Message::MessageDeleted,this,[=](Message* msg){
        cout << msg->Content.userID << endl;
        if(msg->Content.userID==User::getCurrentUser()->getId()){
            chat->model->removeMessage(msg->Content.messageID);
            ui->verticalLayout->removeWidget(msg);
            msg->setParent(nullptr);
            msg->deleteLater();
        }
        else{
            chat->model->removeMessage(msg->Content.messageID);
            msg->Content.status.setDeletedFor(User::getCurrentUser()->getId());
            chat->model->addMessage(msg->Content);
            ui->verticalLayout->removeWidget(msg);
            msg->setParent(nullptr);
            msg->deleteLater();
        }
    });
}
void Container::animate(){
    connect(CurrentReply,&Message::clicked,this,[=](Message* msg){
        QPropertyAnimation* anim = new QPropertyAnimation(ui->scrollArea->verticalScrollBar(), "value");
        anim->setDuration(300);
        anim->setStartValue(ui->scrollArea->verticalScrollBar()->value());
        anim->setEndValue(msg->Reply->pos);
        anim->setEasingCurve(QEasingCurve::OutCubic);
        anim->start(QAbstractAnimation::DeleteWhenStopped);
    });
}
void Container::sendMessage(MessageModel msg){
    if(msg.status.CheckDeletedFor(User::getCurrentUser()->getId()))
        return;
    ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
    if(CurrentReply)
    {
        msg.option = MessageModel::REPLY;
        msg.ReplyMessageID = CurrentReply->Reply->Content.getMessageID();
    }else if(msg.option==MessageModel::REPLY){
        auto msg1 = msg;
        msg1.messageID= msg.ReplyMessageID;
        auto x = new Message(msg1,nullptr);
        if(messages.lower_bound(x)==messages.end()){
            msg.option= MessageModel::NORMAL;
        }
        else{
            auto y  = (*messages.lower_bound(x))->MessageBubble;
            if(y->Content.datatype==MessageModel::TEXT){
                TextMessage *msg = dynamic_cast<TextMessage*>(y);
                CurrentReply = new ReplyTextMessage(msg);
            }else if(y->Content.datatype==MessageModel::IMAGE){
                ImageMessage *msg = dynamic_cast<ImageMessage*>(y);
                CurrentReply = new ReplyImageMessage(msg);
            }else if(y->Content.datatype==MessageModel::VOICE){
                VoiceMessage *msg = dynamic_cast<VoiceMessage*>(y);
                CurrentReply = new ReplyVoiceMessage(msg);
            }else{
                AttachmentCard *msg = dynamic_cast<AttachmentCard*>(y);
                CurrentReply = new ReplyDocumentMessage(msg);
            }
        }
        delete x;
    }
    chat->model->addMessage(msg);
    if(msg.datatype==MessageModel::TEXT){
        auto x = new  TextMessage(msg,CurrentReply);
        x->Adjust();
        connect(x,&Message::ReplyRequest,this,[=](Message*msg){
            CurrentReply = new ReplyTextMessage(x);
            ShowReply();
        });
        if(CurrentReply){
            animate();
        }
        if (msg.type==MessageModel::RECEIVED)
        {
            auto message =new  MessageReceived(0,x);
            AddLeft(message);
        }
        else{
            auto message =new  MessageSent(0,x);
            AddRight(message);
        }
    }
    else if(msg.datatype==MessageModel::VOICE){
        auto x = new  VoiceMessage(msg,CurrentReply);
        x->Adjust();
        connect(x,&Message::ReplyRequest,this,[=](Message*msg){
            CurrentReply = new ReplyVoiceMessage(x);
            ShowReply();
        });
        connect(x,&VoiceMessage::voiceStartRequest,this,[=](VoiceMessage *msg){
            if(CurrentPlayed==nullptr){
                CurrentPlayed = msg;
            }else if(msg!=CurrentPlayed){
                CurrentPlayed->player->pause();
                CurrentPlayed->timeLabel->setVisible(0);
                CurrentPlayed->player->setPosition(0);
                CurrentPlayed = msg;
            }
        });
        if(CurrentReply){
            animate();
        }
        if (msg.type==MessageModel::RECEIVED)
        {
            auto message =new  MessageReceived(0,x);
            AddLeft(message);
        }
        else{
            auto message =new  MessageSent(0,x);
            AddRight(message);
        }
    }else if(msg.datatype==MessageModel::IMAGE){
        string s = "";

        auto x = new  ImageMessage(msg,CurrentReply);
        x->Adjust();
        connect(x,&Message::ReplyRequest,this,[=](Message*msg){
            CurrentReply = new ReplyImageMessage(x);
            ShowReply();
        });
        if(CurrentReply){
            animate();
        }
        if (msg.type==MessageModel::RECEIVED)
        {

            auto message =new  MessageReceived(0,x);
            AddLeft(message);
        }
        else{

            auto message =new  MessageSent(0,x);
            AddRight(message);
        }
    }
    else{
        auto x = new  AttachmentCard(msg,CurrentReply);
        x->Adjust();
        connect(x,&Message::ReplyRequest,this,[=](Message*msg){
            CurrentReply = new ReplyDocumentMessage(x);
            ShowReply();
        });
        if(CurrentReply){
            animate();
        }
        if (msg.type==MessageModel::RECEIVED)
        {
            auto message =new  MessageReceived(0,x);
            AddLeft(message);
        }
        else{
            auto message =new  MessageSent(0,x);
            AddRight(message);
        }
    }
    connect(ui->scrollArea->verticalScrollBar(), &QScrollBar::rangeChanged,
            this, [=](int min, int max) {
            QPropertyAnimation* anim = new QPropertyAnimation(ui->scrollArea->verticalScrollBar(), "value");
            anim->setDuration(300);
            anim->setStartValue(ui->scrollArea->verticalScrollBar()->value());
            anim->setEndValue(max);
            anim->setEasingCurve(QEasingCurve::OutCubic);
            anim->start(QAbstractAnimation::DeleteWhenStopped);
            });
    if(cancelReplyButton){
        cancelReplyButton->setParent(nullptr);
        delete cancelReplyButton;
        cancelReplyButton = nullptr;
    }
    CurrentReply =nullptr;
}

void Container::showMessages() {
    ChatRoom* chat = dynamic_cast<ChatRoom*>(parentWidget());
    if (!chat) return;
    for (int i = 0; i < ui->verticalLayout->count(); ++i) {
        QLayoutItem* item = ui->verticalLayout->itemAt(i);
        if (item && item->widget()) {
            item->widget()->setVisible(true);
        }
    }
}

void Container::clearMessages() {
    ChatRoom* chat = dynamic_cast<ChatRoom*>(parentWidget());
    if (!chat) return;
    for (int i = 0; i < ui->verticalLayout->count(); ++i) {
        QLayoutItem* item = ui->verticalLayout->itemAt(i);
        if (item && item->widget()) {
            item->widget()->setVisible(false);
        }
    }
    // while ((item = ui->verticalLayout->takeAt(0))) {
    //     if (item->widget()) {
    //         item->widget()->deleteLater();
    //     }
    //     delete item;
    // }
}

void Container::deleteSearchResults() {
    ChatRoom* chat = dynamic_cast<ChatRoom*>(parentWidget());
    if (!chat) return;
    int i = 0;
    while (i < ui->verticalLayout->count()) {
        QLayoutItem* item = ui->verticalLayout->itemAt(i);
        if (item && item->widget() && item->widget()->isVisible()) {
            cout << "asdasd" << endl;
            item->widget()->deleteLater();
            ui->verticalLayout->removeItem(item);
            delete item;
        } else {
            i++;
        }
    }
}

void Container::showNoResults() {
    ChatRoom* chat = dynamic_cast<ChatRoom*>(parentWidget());
    if (!chat) return;
    if (QLabel* label = findChild<QLabel*>("noResultsLabel")) {
        return;
    }
    QLabel* noResultsLabel = new QLabel(this);
    noResultsLabel->setTextFormat(Qt::RichText);
    noResultsLabel->setObjectName("noResultsLabel");
    noResultsLabel->setText("<b>No messages found</b>");

    noResultsLabel->setAlignment(Qt::AlignCenter);
    noResultsLabel->setStyleSheet(
        "QLabel {"
        "  color: #666;"
        "  font-size: 14px;"
        "  margin: 20px;"
        "}"
    );

    ui->verticalLayout->addWidget(noResultsLabel);
}

void Container::removeNoResultsLabel() {
    if (QLabel* label = findChild<QLabel*>("noResultsLabel")) {
        ui->verticalLayout->removeWidget(label);
        label->deleteLater();
    }
}

void Container::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    h = 0;
    for (int i = 0;i<ui->verticalLayout->count();i++) {
        Message *message = dynamic_cast<Message*>(ui->verticalLayout->itemAt(i)->widget());
        if(message){
            message->setFixedWidth(min(570,int(width()*0.7)));
            message->Adjust();
            message->MessageBubble->pos = h;
            h+=message->height();
        }
    }
}
