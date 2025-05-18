//
// Created by Dell on 5/18/2025.
//

#ifndef ADDCONTACT_H
#define ADDCONTACT_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class AddContact; }
QT_END_NAMESPACE

class AddContact : public QWidget {
Q_OBJECT

public:
    explicit AddContact(QWidget *parent = nullptr);
    ~AddContact() override;

private slots:
    void on_add();

private:
    Ui::AddContact *ui;
};


#endif //ADDCONTACT_H
