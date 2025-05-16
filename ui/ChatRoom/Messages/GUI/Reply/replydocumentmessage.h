#ifndef REPLYDOCUMENTMESSAGE_H
#define REPLYDOCUMENTMESSAGE_H

#include <QWidget>
#include "AttachmentCard.h"
#include "message.h"
namespace Ui {
class ReplyDocumentMessage;
}

class ReplyDocumentMessage : public Message
{
    Q_OBJECT

public:

    explicit ReplyDocumentMessage(AttachmentCard *msg,QWidget *parent = nullptr);
    void Adjust() override;
    ~ReplyDocumentMessage();
    void resizeEvent(QResizeEvent *event) override;
private:
    Ui::ReplyDocumentMessage *ui;
};

#endif // REPLYDOCUMENTMESSAGE_H
