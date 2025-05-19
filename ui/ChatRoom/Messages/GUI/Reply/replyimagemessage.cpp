#include "replyimagemessage.h"
#include "ui_replyimagemessage.h"
#include <QGraphicsDropShadowEffect>
#include <User.h>
ReplyImageMessage::ReplyImageMessage(ImageMessage* msg,QWidget *parent)
    : Message(msg,parent)
    , ui(new Ui::ReplyImageMessage)
{
    ui->setupUi(this);
    setFixedHeight(62);
    image = new HighQualityImage(msg->Image->getPath().data(),40);
    setMinimumWidth(230);
    if(msg->Content.getUserID()==User::getCurrentUser()->getId()){
        ui->Sender->setText("You");
    }else
        ui->Sender->setText(User::getUser(msg->Content.getUserID())->getFirstName().data());
    MinWidth = std::max(200,ui->Sender->sizeHint().width());
    ui->horizontalLayout_4->addWidget(image);
    ui->Content->setWordWrap(true);
    auto* shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(12);
    shadow->setOffset(1,3);
    shadow->setColor(QColor(0, 0, 0, 150));
    ui->ReplyContainer->setGraphicsEffect(shadow);
    if(msg->Content.getPrompt().size())
        ui->Content->setText(QFontMetrics(ui->Content->font()).elidedText(msg->label->textData->text(), Qt::ElideRight, width()-110));
}

void ReplyImageMessage::Adjust(){

}

void ReplyImageMessage::resizeEvent(QResizeEvent *event){
    ui->Content->setText(QFontMetrics(ui->Content->font()).elidedText(ui->Content->text(), Qt::ElideRight, width()-110));
}

ReplyImageMessage::~ReplyImageMessage()
{
    delete ui;
}
