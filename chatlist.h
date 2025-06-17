#ifndef CHATLIST_H
#define CHATLIST_H

#include <QWidget>
#include "./ui/Search/search.h"
#include "chatcard.h"
#include <User.h>
#include <unordered_map>
namespace Ui {
class ChatList;
}

class ChatList : public QWidget
{
    Q_OBJECT

public:
    explicit ChatList(QWidget *parent = nullptr);
    void AddChat(int id);
    void AddChat(chatcard* card);
    void AddChat(User user);
    ~ChatList();

private slots:
    void on_group_clicked();

    void on_ActionList_clicked();

    void on_StatusWidget_clicked();

    void on_newContact_clicked();
signals:
    void ChatCardClicked(int id);
    void StatusClicked();
    void settingsClicked();
    void groupClicked();
private:
    Ui::ChatList *ui;
    Search* searchBar;
    vector<int> SearchResult;
    unordered_map<int,string>data;
};

#endif // CHATLIST_H
