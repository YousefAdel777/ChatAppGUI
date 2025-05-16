#include "recording.h"
#include "ui_recording.h"
#include <QTimer>
#include <QTime>
#include<QShortcut>
#include <Helper.h>
#include<QFile>
#include <MessageModel.h>
#include <ChatRoom.h>
#include <iostream>
using namespace std;
Recording::Recording(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Recording)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    setFocusPolicy(Qt::StrongFocus);
    elapsedTimer.start();
    timer->start(100);
    accmulatedSum = 0;
    ui->Timer->setText("00:00:00");
    connect(timer, &QTimer::timeout, this, &Recording::updateTimer);
    ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
    recorder = new Recorder(to_string(chat->msgId+1)+".wav");
    recorder->recorder->record();
    del=0;
    auto* returnSc = new QShortcut(QKeySequence(Qt::Key_Return), this);
    connect(returnSc, &QShortcut::activated, this, &Recording::finishRecording);
}
void Recording::updateTimer() {
    qint64 totalSecs = (accmulatedSum+elapsedTimer.elapsed()) / 1000;
    int hours   = static_cast<int>(totalSecs / 3600);
    int minutes = static_cast<int>((totalSecs % 3600) / 60);
    int seconds = static_cast<int>(totalSecs % 60);
    QString text = QString("%1:%2:%3")
                       .arg(hours,   2, 10, QChar('0'))
                       .arg(minutes, 2, 10, QChar('0'))
                       .arg(seconds, 2, 10, QChar('0'));

    ui->Timer->setText(text);
}
Recording::~Recording()
{
    delete ui;
}

void Recording::on_pauseBtn_clicked()
{
    finishRecording();
}

void Recording::finishRecording()
{
    ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
    recorder->recorder->stop();
    MessageModel msg1(++chat->msgId,User::getCurrentUser()->getId(),MessageModel::VOICE,MessageModel::SENT,MessageModel::NORMAL,-1,Helper::getPath(to_string(chat->msgId+1))+".wav",Status());
    if(parentWidget()!=nullptr){
        ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());
        chat->chat->sendMessage(msg1);
    }
    close();
}
void Recording::on_deleteBtn_clicked()
{
    recorder->recorder->stop();
    del = 1;
    close();
}

