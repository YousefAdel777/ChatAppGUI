#include "Header.h"
#include "ui_Header.h"
#include "About.h"
#include<QMenu>
#include <QGraphicsDropShadowEffect>
#include <ChatRoom.h>
#include "AboutG.h"
#include "Group.h"

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
    ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
    if (chat->model->type) {
        ui->lastSeen->setVisible(false);
        ui->addContact->setVisible(false);
    }
    else {
        vector<int> usersIds = chat->model->getUsers();
        int userId = -1;
        for (int id : usersIds) {
            if (id != User::getCurrentUser()->getId()) {
                userId = id;
                break;
            }
        }
        optional<User> optUser = User::getUser(userId);
        if (optUser.has_value()) {
            tm time = optUser->getLastSeen();
            ui->lastSeen->setText(QString::fromStdString("Last Seen: " + Date::format(&time)));
        }
        User user = User::getCurrentUser().value();
        if (user.hasContact(userId)) {
            ui->addContact->setVisible(false);
        }
        else {
            connect(ui->addContact, &QPushButton::clicked, this, &Header::on_add_contact_clicked);
        }
    }

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
    ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
    if (chat->model->type) {
        Group* g = dynamic_cast<Group*>(chat->model);
        AboutG * about_g = new AboutG(
            g->getId(),
            User::getCurrentUser()->getId(),
            g->getImagePath(),
            g->getName(),
            g->getDescription()
        );
        about_g->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
        QPoint globalPos = ui->Name->mapToGlobal(QPoint(0, ui->Name->height()));
        about_g->move(globalPos);
        about_g->show();
    }
    else {
        vector<int> usersIds = chat->model->getUsers();
        int userId = -1;
        for (int id : usersIds) {
            if (id != User::getCurrentUser()->getId()) {
                userId = id;
                break;
            }
        }
        Form *a = new Form(userId);
        a->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
        QPoint globalPos = ui->Name->mapToGlobal(QPoint(0, ui->Name->height()));
        a->move(globalPos);
        a->show();
    }
}


void Header::on_LastSeen_clicked()
{
    ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
    if (chat->model->type) return;
    vector<int> usersIds = chat->model->getUsers();
    int userId = -1;
    for (int id : usersIds) {
        if (id != User::getCurrentUser()->getId()) {
            userId = id;
            break;
        }
    }
    Form *a = new Form(userId);
    a->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    QPoint globalPos = ui->Name->mapToGlobal(QPoint(0, ui->Name->height()));
    a->move(globalPos);
    a->show();
}

void Header::on_add_contact_clicked() {
    ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
    if (chat->model->type) return;
    vector<int> usersIds = chat->model->getUsers();
    int userId = -1;
    for (int id : usersIds) {
        if (id != User::getCurrentUser()->getId()) {
            userId = id;
        }
    }
    User user  = User::getCurrentUser().value();
    user.addContact(userId);
    user.save();
    User::setCurrentUser(user);
    ui->addContact->deleteLater();
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

    QAction SearchAction("Search");
    QAction ClearChatAction("Clear Chat");
    if (!chat->model->type) {
        QAction ViewContactAction("View Contact");
        contextMenu.addAction(&ViewContactAction);
        connect(&ViewContactAction, &QAction::triggered, this, [=] {
            on_Name_clicked();
        });
    }
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
        if (!chat->model->type) {
            QAction *BlockAction = new QAction("Block");
            connect(BlockAction, &QAction::triggered, this, [=](){
                User::getCurrentUser()->addBlocked(chat->model->getUsers()[chat->model->getUsers()[0]==User::getCurrentUser()->getId()]);
                User::setCurrentUser(User::getUser(User::getCurrentUser()->getId()).value());
                chat->Update();
            });
            contextMenu.addAction(BlockAction);
        }
    }
    // Connect actions to demo handlers
    auto showMessage = [](const QString &msg) {

    };
    connect(&SearchAction, &QAction::triggered, this, [=](){ showMessage("Copy clicked"); });

    connect(&ClearChatAction, &QAction::triggered, this, [=](){
        chat->chat->clearChat();
    });
    QPoint pos = mapToGlobal(QPoint(geometry().right()-contextMenu.sizeHint().width(),ui->Dots->geometry().bottom()+20));
    contextMenu.exec(pos);
}


