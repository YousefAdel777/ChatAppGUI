#include "Header.h"
#include "ui_Header.h"
#include "About.h"
#include<QMenu>
#include <QGraphicsDropShadowEffect>
#include <ChatRoom.h>
Header::Header(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::header)
{
    ui->setupUi(this);
    auto* shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(12);
    shadow->setOffset(1,3);
    shadow->setColor(QColor(0, 0, 0, 150));
    ui->widget_3->setGraphicsEffect(shadow);
}

Header::~Header()
{
    delete ui;
}

QPushButton* Header::getName(){
    return ui->Name;
}
void Header::on_Name_clicked()
{
    Form *a = new Form();
    a->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    QPoint globalPos = ui->Name->mapToGlobal(QPoint(0, ui->Name->height()));
    a->move(globalPos);
    a->show();
}


void Header::on_LastSeen_clicked()
{
    Form *a = new Form();
    a->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    QPoint globalPos = ui->Name->mapToGlobal(QPoint(0, ui->Name->height()));
    a->move(globalPos);
    a->show();
}

void Header::on_Dots_clicked()
{
    ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
    QMenu contextMenu(this);
    contextMenu.setWindowOpacity(0.9);
    contextMenu.setAttribute(Qt::WA_TranslucentBackground);
    contextMenu.setWindowFlags(contextMenu.windowFlags() | Qt::FramelessWindowHint);
    contextMenu.setStyleSheet("QMenu { background-color: rgba(30, 30, 30, 240); "
                              "border-radius: 10px; padding: 8px; } "
                              "QMenu::item { color: white; padding: 8px 15px;font-size: 10pt; } "
                              "QMenu::item:selected { background-color: rgba(255, 255, 255, 40); }");
    QAction ViewContactAction("View Contact");
    QAction SearchAction("Search");
    QAction ClearChatAction("Clear Chat");
    contextMenu.addAction(&ViewContactAction);
    contextMenu.addAction(&SearchAction);
    contextMenu.addAction(&ClearChatAction);
    if(User::getCurrentUser()->getBlocked().find(chat->model->getUsers()[chat->model->getUsers()[0]==User::getCurrentUser()->getId()])
        !=User::getCurrentUser()->getBlocked().end()){
        QAction *BlockAction = new QAction("Unblock");
        connect(BlockAction, &QAction::triggered, this, [=](){
            User::getCurrentUser()->removeBlocked(chat->model->getUsers()[chat->model->getUsers()[0]==User::getCurrentUser()->getId()]);
            User::setCurrentUser(User::getUser(User::getCurrentUser()->getId()).value());

            chat->Update();
        });
        contextMenu.addAction(BlockAction);
    }
    else{
        QAction *BlockAction = new QAction("Block");
        connect(BlockAction, &QAction::triggered, this, [=](){
            User::getCurrentUser()->addBlocked(chat->model->getUsers()[chat->model->getUsers()[0]==User::getCurrentUser()->getId()]);
            User::setCurrentUser(User::getUser(User::getCurrentUser()->getId()).value());
            chat->Update();
        });
        contextMenu.addAction(BlockAction);
    }
    // Connect actions to demo handlers
    auto showMessage = [](const QString &msg) {

    };
    connect(&ViewContactAction, &QAction::triggered, this, [=](){
        on_Name_clicked();
    });
    connect(&SearchAction, &QAction::triggered, this, [=](){ showMessage("Copy clicked"); });

    connect(&ClearChatAction, &QAction::triggered, this, [=](){
        chat->chat->clearChat();
    });
    QPoint pos = mapToGlobal(QPoint(geometry().right()-contextMenu.sizeHint().width(),ui->Dots->geometry().bottom()+20));
    contextMenu.exec(pos);
}


