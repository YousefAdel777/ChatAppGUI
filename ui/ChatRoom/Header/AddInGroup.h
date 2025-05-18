#ifndef ADDINGROUP_H
#define ADDINGROUP_H

#include <QWidget>
#include<QLabel>
namespace Ui {
class AddInGroup;
}

class AddInGroup : public QWidget
{
    Q_OBJECT

public:
    bool isChecked;
    QLabel *photo,*name;
    explicit AddInGroup(int id,QWidget *parent = nullptr);
    int UserId;
    ~AddInGroup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddInGroup *ui;
};

#endif // ADDINGROUP_H
