#ifndef PRIVACYSETTINGS_H
#define PRIVACYSETTINGS_H

#include <QWidget>
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
    map<long long,unordered_set<long long>> blocked;
    map<long long,unordered_set<long long>> HideOnline;
    map<long long,unordered_set<long long>> HideLastSeen;
    map<long long,unordered_set<long long>> HidePhoto;
    map<long long,unordered_set<long long>> HideAbout;
    map<long long,unordered_set<long long>> HideStatus;


    vector<long long> TmpContacts;
    vector<long long> TmpUsers;
    long long TmpID = 0;


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

    void PrepareMyContactsExcept(vector<long long> Contacts,
                                 unordered_set<long long> Excluded);

    unordered_set<long long> SetMyContactsExcept(vector<ContactWidget*> v);

    void FixButtonsBorder();
};
#endif // PRIVACYSETTINGS_H
