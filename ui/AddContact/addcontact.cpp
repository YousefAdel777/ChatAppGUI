#include "addcontact.h"

#include <QPushButton>

#include "ui_AddContact.h"
#include "User.h"


AddContact::AddContact(QWidget *parent) :
    QDialog(parent), ui(new Ui::AddContact) {
    ui->setupUi(this);
    connect(ui->addBtn, &QPushButton::clicked, this, &AddContact::on_add);
}

void AddContact::on_add() {
    ui->phoneErr->setText("");
    User currentUser = User::getCurrentUser().value();
    std::string number = ui->phoneIn->text().toStdString();
    if (!User::validateMobileNumber(number)) {
        ui->phoneErr->setText("Invalid phone number");
        return;
    }
    optional<User> user = User::getUser(number);
    if (!user.has_value()) {
        ui->phoneErr->setText("No user with this number found");
        return;
    }
    if (currentUser.hasContact(user->getId())) {
        ui->phoneErr->setText("User already in contacts");
        return;
    }
    currentUser.addContact(user->getId());
    currentUser.save();
    User::setCurrentUser(currentUser);
    ui->phoneIn->setText("");
    vector usersIds = { currentUser.getId(), user->getId() };
    ChatRoomModel * chat = ChatRoomModel::createChat(usersIds);
    emit chatCreated(chat);
}

AddContact::~AddContact() {
    delete ui;
}
