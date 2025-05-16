//
// Created by dell on 4/30/2025.
//

#ifndef MESSAGERECEIVED_H
#define MESSAGERECEIVED_H

#include <QLabel>
#include <QWidget>
#include "Message.h"
using namespace std;

class MessageReceived : public Message {
    Q_OBJECT
public:
    explicit MessageReceived(int userId,Message *MessageBubble,QWidget *parent = nullptr);
    void Adjust() override;
    void resizeEvent(QResizeEvent *event) override;
private:
    QLabel *ProfilePhoto;
    QLabel *SentTime;
};


#endif //TEXTMESSAGE_H
