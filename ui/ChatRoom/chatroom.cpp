#include "chatroom.h"
#include "ui_chatroom.h"
#include "Helper.h"
ChatRoom::ChatRoom(int id,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatRoom), id(id)
{
    ui->setupUi(this);
    chat = new Container(this);
    headerBar = new Header(id, this);
    sendBar = new Sending(this);
    sendBar->setFixedWidth(width());
    headerBar->setFixedWidth(width());
    chat->setFixedSize(width(),height()-sendBar->height()-headerBar->height());
    chat->setGeometry(0,headerBar->geometry().bottom(),chat->width(),chat->height());
    sendBar->setGeometry(0,chat->geometry().bottom(),sendBar->width(),sendBar->height());
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
    connect(headerBar, &Header::searchDone, this, &ChatRoom::handleSearch);
    connect(headerBar, &Header::searchCancel, this, &ChatRoom::handleSearchCancel);
    connect(sendBar, &Sending::messageSent, this, &ChatRoom::addSearchContent);
    model = ChatRoomModel::getChatRoomModel(id);
    if(model.has_value())
    {
        for(auto x:model->getMessages()){
            chat->sendMessage(x);
            msgId = max(msgId,x.getMessageID());
        }
    }else{
        model = ChatRoomModel();
        model->setName(User::getUser(id)->getFirstName());
        vector<int> x = {User::getCurrentUser()->getId(),id};
        model->setUsers(x);
    }
    if(model->getUsers().size()==2){
        if(model->getUsers()[0]!=User::getCurrentUser()->getId()){
            headerBar->getName()->setText(User::getUser(model->getUsers()[0])->getFirstName().data());
        }else{
            headerBar->getName()->setText(User::getUser(model->getUsers()[1])->getFirstName().data());
        }
    }
}

void ChatRoom::handleSearch(std::vector<int> ids) {
    if (resultsCount > 0) {
        chat->deleteSearchResults();
    }
    chat->clearMessages();
    resultsCount = 0;
    optional<ChatRoomModel> chat_room_model = ChatRoomModel::getChatRoomModel(id);
    if (ids.empty()) {
        chat->showNoResults();
        return;
    }
    for (auto x:ids) {
        MessageModel msg = chat_room_model->getMessage(x);
        chat->sendMessage(msg);
        resultsCount += 1;
    }
}

void ChatRoom::handleSearchCancel(string query) {
    if (!query.empty() || resultsCount > 0) {
        chat->deleteSearchResults();
    }
    if (resultsCount == 0) chat->removeNoResultsLabel();
    chat->showMessages();
    resultsCount = 0;
}

void ChatRoom::handleSearchStart() {
    chat->clearMessages();
    for(auto x:model->getMessages()){
        chat->sendMessage(x);
        msgId = max(msgId,x.getMessageID());
    }
}

void ChatRoom::addSearchContent(MessageModel msg) {
    headerBar->addSearchContent(msg);
}

void ChatRoom::resizeEvent(QResizeEvent *event){
    sendBar->setFixedWidth(width());
    headerBar->setFixedWidth(width());
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

ChatRoom::~ChatRoom()
{
    delete ui;
}
