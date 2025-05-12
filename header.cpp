#include "header.h"
#include "ui_header.h"
#include "About.h"
#include<QMenu>
header::header(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::header)
{
    ui->setupUi(this);
}

header::~header()
{
    delete ui;
}

void header::on_Name_clicked()
{
    Form *a = new Form();
    a->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    QPoint globalPos = ui->Name->mapToGlobal(QPoint(0, ui->Name->height()));
    a->move(globalPos);
    a->show();
}


void header::on_LastSeen_clicked()
{
    Form *a = new Form();
    a->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    QPoint globalPos = ui->Name->mapToGlobal(QPoint(0, ui->Name->height()));
    a->move(globalPos);
    a->show();
}

void header::on_Dots_clicked()
{
    QMenu contextMenu(this);
    contextMenu.setWindowOpacity(0.9);
    contextMenu.setAttribute(Qt::WA_TranslucentBackground);
    contextMenu.setWindowFlags(contextMenu.windowFlags() | Qt::FramelessWindowHint);
    contextMenu.setStyleSheet("QMenu { background-color: rgba(30, 30, 30, 240); "
                              "border-radius: 10px; padding: 8px; } "
                              "QMenu::item { color: white; padding: 8px 15px;font-size: 14pt; } "
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
    QPoint pos = QPoint(geometry().right()-contextMenu.sizeHint().width(),geometry().bottom());
    contextMenu.exec(pos);

}


