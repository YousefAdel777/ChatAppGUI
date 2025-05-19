#ifndef CHATROOM_H
#define CHATROOM_H

#include <QWidget>
#include "container.h"
#include <blockerwidget.h>
#include <BlockedWidget.h>
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
    explicit ChatRoom(int id,int user_id =0,QWidget *parent = nullptr);
    int msgId = 0,user_id;
    //explicit ChatRoom(User user,QWidget *parent = nullptr);
    ~ChatRoom();
    optional<ChatRoomModel> model;
    void resizeEvent(QResizeEvent *event) override;
    Ui::ChatRoom *ui;
    void Update();
    BlockedWidget *blocked = nullptr;
    BlockerWidget *block = nullptr;
    Container *chat;
    Header *headerBar;
    Sending * sendBar = nullptr;
};

#endif // CHATROOM_H
