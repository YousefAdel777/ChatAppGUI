#include "chatwidget.h"
#include "ui_chatwidget.h"
ChatWidget::ChatWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatWidget)
{
    ui->setupUi(this);
    leftSide = new ChatList();
    ui->container->setAlignment(Qt::AlignLeft);
    ui->container->addWidget(leftSide);
    chat = nullptr;
    connect(leftSide,&ChatList::ChatCardClicked,this,[=](int id){
        cout<<1<<endl;
        if(chat){
            ui->container->removeWidget(chat);
            chat->setParent(nullptr);
            chat->deleteLater();
        }
        chat = new ChatRoom(id,2,this);
        ui->container->addWidget(chat);
        chat->show();
    });
    connect(leftSide,&ChatList::StatusClicked,this,[=]{
        emit statusClicked();
    });
}

ChatWidget::~ChatWidget()
{
    delete ui;
}
