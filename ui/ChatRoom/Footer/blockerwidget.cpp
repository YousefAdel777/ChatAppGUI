#include "blockerwidget.h"
#include "ui_blockerwidget.h"
#include <ChatRoom.h>
#include <User.h>
BlockerWidget::BlockerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BlockerWidget)
{
    ui->setupUi(this);

}

BlockerWidget::~BlockerWidget()
{
    delete ui;
}

void BlockerWidget::on_pushButton_clicked()
{
    ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
    User::getCurrentUser()->removeBlocked(chat->model->getUsers()[chat->model->getUsers()[0]==User::getCurrentUser()->getId()]);
    User::setCurrentUser(User::getUser(User::getCurrentUser()->getId()).value());
    chat->Update();
}

