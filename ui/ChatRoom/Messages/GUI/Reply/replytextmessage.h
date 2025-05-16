#ifndef REPLYTEXTMESSAGE_H
#define REPLYTEXTMESSAGE_H

#include <QWidget>
#include <QResizeEvent>
#include "message.h"
#include "TextMessage.h"
namespace Ui {
class ReplyTextMessage;
}

class ReplyTextMessage : public Message
{
    Q_OBJECT

public:
    explicit ReplyTextMessage(TextMessage* msg,QWidget *parent = nullptr);
    ~ReplyTextMessage();
    void resizeEvent(QResizeEvent *event) override;
    void Adjust() override;
private:
    Ui::ReplyTextMessage *ui;
    int RefId;
    int MinWidth;
    int MinHeight;
};

#endif // REPLYTEXTMESSAGE_H
