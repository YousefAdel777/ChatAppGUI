#include "chatroom.h"
#include "ui_chatroom.h"
#include "Helper.h"
ChatRoom::ChatRoom(int id,int user_id,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatRoom)
    ,user_id(user_id)
{
    ui->setupUi(this);
    model = ChatRoomModel::getChatRoomModel(id);
    if(!model.has_value()){
        model = ChatRoomModel();
        model->setName(User::getUser(user_id)->getFirstName());
        vector<int> x = {User::getCurrentUser()->getId(),user_id};
        model->setUsers(x);
    }
    chat = nullptr;
    headerBar=nullptr;
    sendBar = nullptr;
    Update();
}

void ChatRoom::Update(){
    if(chat){
        chat->setParent(nullptr);

        chat->deleteLater();
        chat = nullptr;
    }
    if(headerBar){
        headerBar->setParent(nullptr);
        headerBar->deleteLater();
        headerBar = nullptr;
    }
    if(sendBar)
    {
        sendBar->setParent(nullptr);

        sendBar->deleteLater();
        sendBar = nullptr;
    }
    if(block)
    {
        block->setParent(nullptr);
        block->deleteLater();
        block = nullptr;
    }
    if(blocked)
    {
        blocked->setParent(nullptr);
        blocked->deleteLater();
        blocked = nullptr;
    }
    chat = new Container(this);
    chat->show();
    if(!model.has_value()||model->getUsers().size()>2){
        sendBar = new Sending(this);
    }else{
        int user = model->getUsers()[model->getUsers()[0]==User::getCurrentUser()->getId()];
        if(User::getCurrentUser()->getBlocked().find(user)!=User::getCurrentUser()->getBlocked().end()){
            block = new BlockerWidget(this);
            block->show();
        }
        else if(User::getUser(model->getUsers()[1])->getBlocked().find(User::getCurrentUser()->getId())!=User::getUser(user)->getBlocked().end()){
            blocked = new BlockedWidget(this);
            blocked->show();
        }
        else{
            sendBar = new Sending(this);
            sendBar->show();
        }
    }
    headerBar = new Header(this);
    headerBar->show();
    headerBar->setFixedWidth(width());
    if(sendBar)
    {
        sendBar->setFixedWidth(width());
        chat->setFixedSize(width(),height()-sendBar->height()-headerBar->height());
        sendBar->setGeometry(0,height()-sendBar->height(),sendBar->width(),sendBar->height());
        int h = sendBar->geometry().top();
        chat->setGeometry(0,headerBar->height(),chat->width(),chat->height());
        if(chat->CurrentReply){
            h-=chat->CurrentReply->height();
            chat->CurrentReply->setGeometry(sendBar->geometry().left()+15,h,sendBar->width()-60,chat->CurrentReply->geometry().height());
            chat->cancelReplyButton->setGeometry(chat->CurrentReply->geometry().right()-30,sendBar->geometry().top()-chat->CurrentReply->height(),chat->cancelReplyButton->width(),chat->cancelReplyButton->height());
        }
        if(sendBar->container){
            h-=sendBar->container->height();
            sendBar->container->setGeometry(sendBar->geometry().left(),h,width(),sendBar->container->geometry().height());
        }
        connect(sendBar,&Sending::sizeChanged,this,[=](){
            sendBar->setGeometry(0,height()-sendBar->height(),sendBar->width(),sendBar->height());
            int h = sendBar->geometry().top();
            if(chat->CurrentReply){
                h-=chat->CurrentReply->height();
                chat->CurrentReply->setGeometry(sendBar->geometry().left()+15,h,sendBar->width()-60,chat->CurrentReply->geometry().height());
                chat->cancelReplyButton->setGeometry(chat->CurrentReply->geometry().right()-30,sendBar->geometry().top()-chat->CurrentReply->height(),chat->cancelReplyButton->width(),chat->cancelReplyButton->height());
            }
            if(sendBar->container){
                h-=sendBar->container->height();
                sendBar->container->setGeometry(sendBar->geometry().left(),h,width(),sendBar->container->geometry().height());
            }
        });
    }
    else if(block){
        block->setFixedWidth(width());
        chat->setGeometry(0,headerBar->height(),chat->width(),chat->height());

        chat->setFixedSize(width(),height()-block->height()-headerBar->height());
        block->setGeometry(0,height()-block->height(),block->width(),block->height());
    }else{
        blocked->setFixedWidth(width());
        chat->setGeometry(0,headerBar->height(),chat->width(),chat->height());

        chat->setFixedSize(width(),height()-blocked->height()-headerBar->height());
        blocked->setGeometry(0,height()-blocked->height(),blocked->width(),blocked->height());
    }

    for(auto x:model->getMessages()){
        chat->sendMessage(x);
        msgId = max(msgId,x.getMessageID());
    }
    if(model->getUsers().size()==2){
        if(model->getUsers()[0]!=User::getCurrentUser()->getId()){
            headerBar->getName()->setText(User::getUser(model->getUsers()[0])->getFirstName().data());
        }else{
            headerBar->getName()->setText(User::getUser(model->getUsers()[1])->getFirstName().data());
        }
    }
}

void ChatRoom::resizeEvent(QResizeEvent *event){

    headerBar->setFixedWidth(width());
    if(sendBar)
    {
        sendBar->setFixedWidth(width());
        chat->setFixedSize(width(),height()-sendBar->height()-headerBar->height());
        sendBar->setGeometry(0,height()-sendBar->height(),sendBar->width(),sendBar->height());
        int h = sendBar->geometry().top();
        if(chat->CurrentReply){
            h-=chat->CurrentReply->height();
            chat->CurrentReply->setGeometry(sendBar->geometry().left()+15,h,sendBar->width()-60,chat->CurrentReply->geometry().height());
            chat->cancelReplyButton->setGeometry(chat->CurrentReply->geometry().right()-30,sendBar->geometry().top()-chat->CurrentReply->height(),chat->cancelReplyButton->width(),chat->cancelReplyButton->height());
        }
        if(sendBar->container){
            h-=sendBar->container->height();
            sendBar->container->setGeometry(sendBar->geometry().left(),h,width(),sendBar->container->geometry().height());
        }
    }
    else if(block){
        block->setFixedWidth(width());
        chat->setFixedSize(width(),height()-block->height()-headerBar->height());
        block->setGeometry(0,height()-block->height(),block->width(),block->height());
    }else{
        blocked->setFixedWidth(width());
        chat->setFixedSize(width(),height()-blocked->height()-headerBar->height());
        blocked->setGeometry(0,height()-blocked->height(),blocked->width(),blocked->height());
    }
}

ChatRoom::~ChatRoom()
{
    delete ui;
}
