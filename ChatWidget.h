#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include <chatlist.h>
#include <ChatRoom.h>
namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidget(QWidget *parent = nullptr);
    ~ChatWidget();
signals:
    void statusClicked();
private:
    Ui::ChatWidget *ui;
    ChatList * leftSide;
    ChatRoom* chat;
};

#endif // CHATWIDGET_H
