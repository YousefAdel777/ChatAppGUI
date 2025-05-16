#ifndef MESSAGESENT_H
#define MESSAGESENT_H
#include <QLabel>
#include <QWidget>
#include "Message.h"
using namespace std;
class MessageSent : public Message {
    Q_OBJECT
public:
    explicit MessageSent(int userId,Message *MessageBubble,QWidget *parent = nullptr);
    void Adjust() override;
    void resizeEvent(QResizeEvent *event) override;
    QWidget *ReadStatusContainer;
    ~MessageSent();
    QLabel *ProfilePhoto;
    QLabel *SentTime;
    QLabel *ReadStatus;
};


#endif // MESSAGESENT_H
