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
    CreateGroup * dialog = new CreateGroup(this);
    dialog->setWindowModality(Qt::ApplicationModal);
    dialog->exec();
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
    AddContact * dialog = new AddContact(this);
    dialog->setWindowModality(Qt::ApplicationModal);
    dialog->exec();
}
