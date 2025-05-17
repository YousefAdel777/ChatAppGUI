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
    explicit AboutG(QWidget *parent = nullptr);
    ~AboutG();

private slots:
    void on_addMember_clicked();
private:
    Ui::AboutG *ui;
};

#endif // ABOUTG_H
