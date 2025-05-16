#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H
#include <QWidget>
#include <QLabel>
#include <message.h>
#include <MessageModel.h>
class TextMessage : public Message {
    Q_OBJECT
public:
    TextMessage(MessageModel msg,Message* Reply=nullptr,QWidget *parent=nullptr);
    ~TextMessage();
     void Adjust() override;
    QWidget *ReadStatusContainer;
    QLabel *textData;
protected:
    void resizeEvent(QResizeEvent *event) override;
private:
    QLabel *ReadStatus;
    int MessageWidth;
};

#endif // VOICEMESSAGEWIDGET_H
