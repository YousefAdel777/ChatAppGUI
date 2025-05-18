#include "replyvoicemessage.h"
#include "ui_replyvoicemessage.h"
#include <QGraphicsDropShadowEffect>
#include <User.h>
ReplyVoiceMessage::ReplyVoiceMessage(VoiceMessage* msg,QWidget *parent)
    : Message(msg,parent)
    , ui(new Ui::ReplyVoiceMessage)
{
    ui->setupUi(this);
    setFixedHeight(59);
    if(msg->Content.getUserID()==User::getCurrentUser()->getId()){
        ui->Sender->setText("You");
    }else
        ui->Sender->setText(User::getUser(msg->Content.getUserID())->getFirstName().data());
    auto* shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(12);
    shadow->setOffset(1,3);
    shadow->setColor(QColor(0, 0, 0, 150));
    ui->ReplyContainer->setGraphicsEffect(shadow);
    QObject::connect(msg->player, &QMediaPlayer::durationChanged, [=](qint64 duration) {
        auto durationMs = msg->player->duration();
        int minutes = (durationMs / 60000);
        int seconds = (durationMs / 1000) % 60;
        QString timeStr = QString("%1:%2")
                              .arg(minutes, 2, 10, QChar('0'))
                              .arg(seconds, 2, 10, QChar('0'));
        ui->Duration->setText(timeStr);
    });
}

void ReplyVoiceMessage::resizeEvent(QResizeEvent *event){
}

void ReplyVoiceMessage::Adjust(){

}

ReplyVoiceMessage::~ReplyVoiceMessage()
{
    delete ui;
}
