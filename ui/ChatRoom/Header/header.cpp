#include "Header.h"
#include "ui_Header.h"
#include "About.h"
#include<QMenu>
#include <QGraphicsDropShadowEffect>
#include <ChatRoom.h>

#include "Search/search.h"

Header::Header(int id, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::header), id(id)
{
    ui->setupUi(this);
    initializeSearchBar();
    auto* shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(12);
    shadow->setOffset(1,3);
    shadow->setColor(QColor(0, 0, 0, 150));
    ui->widget_3->setGraphicsEffect(shadow);
    ui->closeSearch->setVisible(false);
    connect(ui->Search, &QPushButton::clicked, this, &Header::on_search_clicked);
    connect(ui->closeSearch, &QPushButton::clicked, this, &Header::on_close_search_clicked);
    connect(searchBar, &Search::searchDone, this, &Header::searchDone);
    searchBar->setVisible(false);
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

void Header::on_search_clicked() {
    searchBar->setVisible(true);
    ui->Search->setVisible(false);
    ui->closeSearch->setVisible(true);
}

void Header::initializeSearchBar() {
    unordered_map<int, string> contents;
    optional<ChatRoomModel> chat_room = ChatRoomModel::getChatRoomModel(id);
    for (MessageModel msg : chat_room->getMessages()) {
        contents[msg.getMessageID()] = msg.getContent();
    }
    searchBar = new Search(contents, searchResultsIds);
    ui->searchPlaceholder->addWidget(searchBar);
}

void Header::on_close_search_clicked() {
    ui->Search->setVisible(true);
    searchBar->setVisible(false);
    ui->closeSearch->setVisible(false);
    emit searchCancel();
}

void Header::on_Dots_clicked()
{
    QMenu contextMenu(this);
    contextMenu.setWindowOpacity(0.9);
    contextMenu.setAttribute(Qt::WA_TranslucentBackground);
    contextMenu.setWindowFlags(contextMenu.windowFlags() | Qt::FramelessWindowHint);
    contextMenu.setStyleSheet("QMenu { background-color: rgba(30, 30, 30, 240); "
                              "border-radius: 10px; padding: 8px; } "
                              "QMenu::item { color: white; padding: 8px 15px;font-size: 10pt; } "
                              "QMenu::item:selected { background-color: rgba(255, 255, 255, 40); }");
    QAction ViewContactAction("View Contact", this);
    QAction SearchAction("Search", this);
    QAction BlockAction("Block", this);
    QAction ClearChatAction("Clear Chat", this);
    contextMenu.addAction(&ViewContactAction);
    contextMenu.addAction(&SearchAction);
    contextMenu.addAction(&BlockAction);
    contextMenu.addAction(&ClearChatAction);
    // Connect actions to demo handlers
    auto showMessage = [](const QString &msg) {

    };
    connect(&ViewContactAction, &QAction::triggered, this, [=](){ showMessage("Reply clicked"); });
    connect(&SearchAction, &QAction::triggered, this, [=](){ showMessage("Copy clicked"); });
    connect(&BlockAction, &QAction::triggered, this, [=](){ showMessage("Forward clicked"); });
    connect(&ClearChatAction, &QAction::triggered, this, [=](){ showMessage("Pin clicked"); });
    QPoint pos = mapToGlobal(QPoint(geometry().right()-contextMenu.sizeHint().width(),ui->Dots->geometry().bottom()+20));
    contextMenu.exec(pos);
}


