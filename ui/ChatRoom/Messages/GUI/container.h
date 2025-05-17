#ifndef CONTAINER_H
#define CONTAINER_H

#include <QWidget>
#include <unordered_set>
#include <QPushButton>
#include "voicemessage.h"
namespace Ui {
class Container;
}

class Container : public QWidget
{
    Q_OBJECT

public:
    explicit Container(QWidget *parent = nullptr);
    ~Container();
    void resizeEvent(QResizeEvent *event) override;
    void sendMessage(MessageModel msg);
    void clearMessages();
    void showNoResults();
    VoiceMessage* CurrentPlayed;
    QPushButton *cancelReplyButton;
    Message* CurrentReply = nullptr;

private:
    void ShowReply();
    void AddLeft(Message* msg);
    void AddRight(Message* msg);
    void animate();
    int h = 0;
    struct MessageComparator {
        bool operator()(const Message* a, const Message* b) const {
            return *a < *b;
        }
    };
    set<Message*,MessageComparator>messages;
    Ui::Container *ui;
};

#endif // CONTAINER_H
