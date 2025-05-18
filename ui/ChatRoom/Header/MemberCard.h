#ifndef MEMBERCARD_H
#define MEMBERCARD_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
namespace Ui {
class MemberCard;
}

class MemberCard : public QWidget
{
    Q_OBJECT

public:
    explicit MemberCard(QWidget *parent = nullptr);
    explicit MemberCard(QString path,QString name,QString role,QWidget *parent = nullptr);
    ~MemberCard();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MemberCard *ui;
};

#endif // MEMBERCARD_H
