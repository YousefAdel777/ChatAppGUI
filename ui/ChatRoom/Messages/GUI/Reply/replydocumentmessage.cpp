#include "replydocumentmessage.h"
#include "ui_replydocumentmessage.h"
#include <User.h>
#include <QGraphicsDropShadowEffect>
ReplyDocumentMessage::ReplyDocumentMessage(AttachmentCard *msg,QWidget *parent)
    : Message(msg,parent)
    , ui(new Ui::ReplyDocumentMessage)
{
    ui->setupUi(this);
    setFixedHeight(64);
    if(msg->Content.getUserID()==User::getCurrentUser()->getId()){
        ui->Sender->setText("You");
    }else
        ui->Sender->setText(User::getUser(msg->Content.getUserID())->getFirstName().data());
    ui->FileName->setWordWrap(true);
    auto* shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(12);
    shadow->setOffset(1,3);
    shadow->setColor(QColor(0, 0, 0, 150));

    ui->ReplyContainer->setGraphicsEffect(shadow);
    ui->FileName->setText(QFontMetrics(ui->FileName->font()).elidedText(msg->fileName, Qt::ElideRight, width()-30));
}

void ReplyDocumentMessage::Adjust(){

}

void ReplyDocumentMessage::resizeEvent(QResizeEvent *event){
    ui->FileName->setText(QFontMetrics(ui->FileName->font()).elidedText(ui->FileName->text(), Qt::ElideRight, width()-30));
}

ReplyDocumentMessage::~ReplyDocumentMessage()
{
    delete ui;
}
