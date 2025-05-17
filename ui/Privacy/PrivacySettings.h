#ifndef PRIVACYSETTINGS_H
#define PRIVACYSETTINGS_H

#include <QWidget>
#include <User.h>
#include "ContactWidget.h"
#include <QPushButton>
#include <QPainterPath>
#include <QRegion>
#include <map>
#include <unordered_set>
//#include <string.h>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    int LastSeenContactsExeptNum = 0;
    int AboutContactsExeptNum = 0;
    int ProfilePhotoContactsExeptNum = 0;
    int StatusContactsExeptNum = 0;
    int StatusContactsShareWithNum = 0;
    enum Mode{
        Everyone,
        MyContacts,
        MyContactsExept,
        Nobody,
        OnlyShareWith
    }
    LastSeenMode = Everyone,
        OnlineMode = Everyone,
        AboutMode = Everyone,
        ProfilePhotoMode = Everyone,
        StatusMode = MyContacts;

    enum current{
        LastSeenAndOnline,
        ProfilePhoto,
        About,
        Status,
        Main
    }
    CurrentWidget = Main;
    vector<ContactWidget*> ContactWidgets;
    map<int,unordered_set<int>> blocked;
    map<int,unordered_set<int>> HideOnline;
    map<int,unordered_set<int>> HideLastSeen;
    map<int,unordered_set<int>> HidePhoto;
    map<int,unordered_set<int>> HideAbout;
    map<int,unordered_set<int>> HideStatus;

    set<int> TmpContacts = User::getCurrentUser()->getContacts();
    vector<User> Users = User::getUsers();
    vector<int> TmpUsers;
    int TmpID = User::getCurrentUser()->getId();


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    QRegion DrawTheButton(QPainterPath path, QRect rect, int radius);

    void on_LastSeenAndOnlineButton_clicked();

    void on_ProfilePhotoButton_clicked();

    void on_StatusButton_clicked();

    void on_AboutButton_clicked();

    void on_StatusBack_clicked();

    void on_ProfilePhotoBack_clicked();

    void on_LastSeenAndOnlineBack_clicked();

    void on_AboutBack_clicked();

    void on_LastSeenChoiceEveryone_clicked();

    void on_LastSeenChoiceMyContacts_clicked();

    void on_LastSeenChoiceMyContactsExept_clicked();

    void on_ExcludeContactsBack_clicked();

    void on_LastSeenChoiceNobody_clicked();

    void on_OnlineChoiceEveryone_clicked();

    void on_OnlineChoiceSameAsLastSeen_clicked();

    void on_AboutChoiceEveryone_clicked();

    void on_AboutChoiceMyContacts_clicked();

    void on_AboutChoiceMyContactsExept_clicked();

    void on_AboutChoiceNobody_clicked();

    void on_ProfilePhotoChoiceEveryone_clicked();

    void on_ProfilePhotoChoiceMyContacts_clicked();

    void on_ProfilePhotoChoiceMyContactsExept_clicked();

    void on_ProfilePhotoChoiceNobody_clicked();

    void on_StatusChoiceMyContacts_clicked();

    void on_StatusChoiceMyContactsExept_clicked();

    void on_StatusChoiceOnlyShareWith_clicked();

    void on_ExcludeContactsSelectAll_clicked();

private:
    Ui::Widget *ui;

    void PrepareMyContactsExcept(set<int> Contacts,
                                 unordered_set<int> Excluded);

    unordered_set<int> SetMyContactsExcept(vector<ContactWidget*> v);

    void FixButtonsBorder();
};
#endif // PRIVACYSETTINGS_H
