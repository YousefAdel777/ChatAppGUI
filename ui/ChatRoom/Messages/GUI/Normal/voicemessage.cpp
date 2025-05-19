#ifndef VOICEMESSAGE_CPP
#define VOICEMESSAGE_CPP
#include "VoiceMessage.h"
#include <QPainter>
#include <User.h>
#include "Helper.h"
using namespace std;
VoiceMessage::VoiceMessage(MessageModel msg,Message* Reply,QWidget *parent):
    Message(msg,Reply,parent){
    // init
    int h = 0;
    if(msg.option==MessageModel::REPLY)
       h = Reply->height()+5;
    setFixedHeight(75+h);
    auto layout  = new QHBoxLayout;
    player = new QMediaPlayer(this);
    waveform = new WaveformSlider();
    timeLabel = new QLabel("00:00");
    output = new QAudioOutput();
    auto layout1 = new QVBoxLayout(this);
    layout1->setAlignment(Qt::AlignTop);
    layout1->setContentsMargins(0,0,0,0);
    MessageBubble = new QWidget();
    playBtn = new QPushButton;
    layout1->setSpacing(0);
    // player init
    player->setSource(QUrl::fromLocalFile(msg.getContent().data()));
    output->setVolume(0.5);
    timeLabel->setVisible(false);
    player->setAudioOutput(output);
    connect(player, &QMediaPlayer::positionChanged, this, [=](qint64 pos) {
        QTime time(0, 0);
        time = time.addMSecs(int(pos));
        timeLabel->setText(time.toString("mm:ss"));
    });
    connect(player, &QMediaPlayer::mediaStatusChanged, this, [=](qint64 pos) {
        if(player->mediaStatus()==QMediaPlayer::EndOfMedia){
            player->play();
            playBtn->click();
            player->setPosition(0);
        }
    });

    //button init
    playBtn->setIcon(QIcon(":/Resources/play.png"));
    playBtn->setIconSize(QSize(22, 22));
    playBtn->setFixedSize(22, 22);
    playBtn->setFlat(true);
    connect(playBtn, &QPushButton::clicked, this, [=]() {
        if (player->playbackState() == QMediaPlayer::PlayingState) {
            player->pause();
            timeLabel->setVisible(0);
            playBtn->setIcon(QIcon(":/Resources/play.png"));
        } else {
            player->play();
            timeLabel->setVisible(1);
            playBtn->setIcon(QIcon(":/Resources/pause.png"));
            emit voiceStartRequest(this);
        }
    });

    //waveform init
    waveform->setPlayer(player);
    waveform->setSegments(Helper::getPCM(msg.getContent()));;

    layout->addWidget(playBtn);
    layout->addWidget(waveform, 1);
    layout->addWidget(timeLabel);
    layout1->addWidget(MessageBubble);
    MessageBubble->setFixedHeight(55);
    MessageBubble->setLayout(layout);
    if (msg.getUserID()==User::getCurrentUser()->getId())
    {
        ReadStatus = new QLabel(this);
        ReadStatus->setFixedSize(15,15);
        ReadStatusContainer = new QWidget(this);
        QVBoxLayout *ReadStatusLayout = new QVBoxLayout();
        ReadStatusLayout->addWidget(ReadStatus,0,Qt::AlignCenter);
        ReadStatusContainer->setLayout(ReadStatusLayout);
        string s = "border-image:url(:/Resources/";
        s+=((msg.status.getSeen())?"Read.png":"3.png");
        s+=") 5 stretch stretch; border-radius:7.5;";
        ReadStatus->setStyleSheet(s.data());
        ReadStatusContainer->setStyleSheet("background-color: #D3E8D2; border-radius:15");
    }
    if(msg.option==MessageModel::REPLY)
    {
        layout1->insertWidget(0,Reply);
        MessageBubble->setStyleSheet("background-color:rgb(214, 240, 209); padding-right:10px; padding-left:10px; border-bottom-left-radius:15px; border-bottom-right-radius:15px; font-size:12; color:#424941;");
    }else{
        if(msg.type==MessageModel::SENT){
            MessageBubble->setStyleSheet("background-color:rgb(214, 240, 209); padding-right:10px; padding-left:10px; border-bottom-left-radius:15px; border-top-left-radius:15px; border-bottom-right-radius:15px; font-size:12; color:#424941;");
        }else{
            MessageBubble->setStyleSheet("background-color:rgb(214, 240, 209); padding-right:10px; padding-left:10px; border-bottom-left-radius:15px; border-top-right-radius:15px; border-bottom-right-radius:15px; font-size:12; color:#424941;");
        }
    }
}

void VoiceMessage::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QRectF rect = MessageBubble->geometry();
    QBrush brush(QColor("#c1e6b8"));
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect, 15, 15);
}


void VoiceMessage::Adjust(){
    setFixedWidth(min(max(width(),70),300));
    MessageBubble->setFixedWidth(min(max(width(),70),300));
    if (Content.getUserID()==User::getCurrentUser()->getId())
        ReadStatusContainer->setGeometry(QRect(min(max(width(),70),300)-30,height()-38,30,30));
}

void VoiceMessage::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    Adjust();
}

#endif
