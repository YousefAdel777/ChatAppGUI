#ifndef ADDMEMBERS_H
#define ADDMEMBERS_H

#include <QWidget>
#include "QVBoxLayout"
#include<vector>
#include "AddInGroup.h"
#include "MemberCard.h"
using namespace std;
namespace Ui {
class AddMembers;
}

class AddMembers : public QWidget
{
    Q_OBJECT

public:
    QWidget *container;
    QVBoxLayout *contactLayout;
    explicit AddMembers(QWidget *parent = nullptr);
    ~AddMembers();
    void clearLayout(QLayout *layout);
public slots:
    void on_added_clicked();
signals:
    void add();
private:
    Ui::AddMembers *ui;
};

#endif // ADDMEMBERS_H
