#include "chatroommenu.h"
#include "ui_chatroommenu.h"

ChatRoomMenu::ChatRoomMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatRoomMenu)
{
    ui->setupUi(this);
}

ChatRoomMenu::~ChatRoomMenu()
{
    delete ui;
}
