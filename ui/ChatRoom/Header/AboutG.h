#ifndef ABOUTG_H
#define ABOUTG_H

#include <QWidget>
#include <QVBoxLayout>
#include"MemberCard.h"
#include<QVector>
#include "AddInGroup.h"
#include "AddMembers.h"
using namespace std;
namespace Ui {
class AboutG;
}

class AboutG : public QWidget
{
    Q_OBJECT

public:
    int members;
    AddMembers *a;
    QVBoxLayout *contactLayout;
    QWidget *container;
    static QVector<MemberCard*> memberCards;
    explicit AboutG(int GroupId,int OwnerId,string path,string name,string des,QWidget *parent = nullptr);
    ~AboutG() override;

private slots:
    void on_addMember_clicked();
signals:
    void groupDeleted(int id);
private:
    Ui::AboutG *ui;
};

#endif // ABOUTG_H
