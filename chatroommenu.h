#ifndef CHATROOMMENU_H
#define CHATROOMMENU_H

#include <QWidget>

namespace Ui {
class ChatRoomMenu;
}

class ChatRoomMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ChatRoomMenu(QWidget *parent = nullptr);
    ~ChatRoomMenu();

private:
    Ui::ChatRoomMenu *ui;
};

#endif // CHATROOMMENU_H
