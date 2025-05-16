#ifndef ReplyVoiceMessage_H
#define ReplyVoiceMessage_H

#include <QWidget>
#include <QResizeEvent>
#include "VoiceMessage.h"
#include "Message.h"
namespace Ui {
class ReplyVoiceMessage;
}

class ReplyVoiceMessage : public Message
{
    Q_OBJECT

public:
    explicit ReplyVoiceMessage(VoiceMessage* msg,QWidget *parent = nullptr);
    ~ReplyVoiceMessage();
    void resizeEvent(QResizeEvent *event) override;
    void Adjust() override;
private:
    Ui::ReplyVoiceMessage *ui;
    int RefId;
    int MinWidth;
    int MinHeight;
};

#endif // ReplyVoiceMessage_H
