#include "replytextmessage.h"
#include "ui_replytextmessage.h"
#include <QGraphicsDropShadowEffect>
#include <User.h>
ReplyTextMessage::ReplyTextMessage(TextMessage* msg,QWidget *parent)
    : Message(msg,parent)
    , ui(new Ui::ReplyTextMessage)
{
    ui->setupUi(this);
    setFixedHeight(64);
    MinWidth = std::max(200,ui->Sender->sizeHint().width());
    ui->Content->setWordWrap(true);
    if(msg->Content.getUserID()==User::getCurrentUser()->getId()){
        ui->Sender->setText("You");
    }else
        ui->Sender->setText(to_string(msg->Content.getUserID()).data());    auto* shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(12);
    shadow->setOffset(1,3);
    shadow->setColor(QColor(0, 0, 0, 150));

    ui->ReplyContainer->setGraphicsEffect(shadow);
    ui->Content->setText(QFontMetrics(ui->Content->font()).elidedText(msg->textData->text(), Qt::ElideRight, width()-30));
}

void ReplyTextMessage::Adjust(){

}

void ReplyTextMessage::resizeEvent(QResizeEvent *event){
    ui->Content->setText(QFontMetrics(ui->Content->font()).elidedText(ui->Content->text(), Qt::ElideRight, width()-30));
}

ReplyTextMessage::~ReplyTextMessage()
{
    delete ui;
}
