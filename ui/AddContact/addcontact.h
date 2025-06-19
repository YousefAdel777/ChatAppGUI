#ifndef ADDCONTACT_H
#define ADDCONTACT_H

#include <QWidget>
#include <QDialog>

#include "ChatRoomModel.h"


QT_BEGIN_NAMESPACE
namespace Ui { class AddContact; }
QT_END_NAMESPACE

class AddContact : public QDialog {
Q_OBJECT

public:
    explicit AddContact(QWidget *parent = nullptr);
    ~AddContact() override;

private slots:
    void on_add();

signals:
    void chatCreated(ChatRoomModel * chat);

private:
    Ui::AddContact *ui;
};


#endif //ADDCONTACT_H
