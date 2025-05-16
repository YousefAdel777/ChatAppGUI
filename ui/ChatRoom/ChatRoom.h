#ifndef CHATROOM_H
#define CHATROOM_H

#include <QWidget>
#include "container.h"
#include <header.h>
#include <sending.h>
#include "ChatRoomModel.h"
namespace Ui {
class ChatRoom;
}

class ChatRoom : public QWidget
{
    Q_OBJECT

public:
    explicit ChatRoom(int id,QWidget *parent = nullptr);
    int msgId = 0;
    //explicit ChatRoom(User user,QWidget *parent = nullptr);
    ~ChatRoom();
    optional<ChatRoomModel> model;
    void resizeEvent(QResizeEvent *event) override;
    Ui::ChatRoom *ui;
    Container *chat;
    Header *headerBar;
    Sending * sendBar;
};

#endif // CHATROOM_H
