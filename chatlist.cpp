#include "chatlist.h"
#include "ui_chatlist.h"
#include "StatusWindow/StatusWindow.h"
#include <chatcard.h>
#include <AddContact/addcontact.h>
#include "Settings/settings.h"
#include "CreateGroup/creategroup.h"
ChatList::ChatList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatList)
{
    ui->setupUi(this);
    searchBar = new Search(data,SearchResult,this);
    searchBar->setGeometry(0,75,searchBar->width(),67);
    createGroupDialog = new CreateGroup(this);
    addContactDialog = new AddContact(this);
    auto pq = User::getCurrentUser()->getChatRooms();
    ui->ChatContainer->setAlignment(Qt::AlignTop);
    while(!pq.empty()){
        auto card = new chatcard(pq.top());
        connect(card,&chatcard::clicked,this,[=](int id){
            emit ChatCardClicked(id);
        });
        ui->ChatContainer->addWidget(card,0,Qt::AlignHCenter);
        pq.pop();
    }
    connect(ui->newGroup,&QPushButton::clicked,this,&ChatList::on_group_clicked);
}

void ChatList::AddChat(int id)
{

}

void ChatList::AddChat(chatcard *card)
{

}

void ChatList::AddChat(User user){

}

ChatList::~ChatList()
{
    delete ui;
}

void ChatList::on_group_clicked() {
    createGroupDialog = new CreateGroup(this);
    createGroupDialog->setWindowModality(Qt::ApplicationModal);
    connect(createGroupDialog, &CreateGroup::groupCreated, this, &ChatList::handle_chat_created);
    createGroupDialog->exec();
}

void ChatList::on_ActionList_clicked()
{
    emit settingsClicked();
}

void ChatList::on_StatusWidget_clicked()
{
    emit StatusClicked();
}

void ChatList::on_newContact_clicked()
{
    addContactDialog = new AddContact(this);
    addContactDialog->setWindowModality(Qt::ApplicationModal);
    connect(addContactDialog, &AddContact::chatCreated, this, &ChatList::handle_chat_created);
    addContactDialog->exec();
}

void ChatList::handle_chat_created(ChatRoomModel * chat) {
    createGroupDialog->close();
    cout << chat->getId() << endl;
    auto card = new chatcard(chat->getId());
    connect(card,&chatcard::clicked,this,[=](int id){
        emit ChatCardClicked(id);
    });
    ui->ChatContainer->insertWidget(0, card, 0, Qt::AlignHCenter);
}
