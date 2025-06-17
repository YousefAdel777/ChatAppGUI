#include <QApplication>
#include "chatlist.h"
#include "mainwindow.h"
#include  "User.h"
#include "Login.h"
#include "StatusWindow/StatusWindow.h"

using namespace std;
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ChatRoomModel::readChatRoomModels();
    User::readUsers();
    User::readCurrentUser();
    optional<User> user = User::getCurrentUser();
    // User::setCurrentUser(User::getUsers()[0]);
    // User user = User::getCurrentUser().value();
    // StatusWindow * w = new StatusWindow(user);
    // w->show();
    // auto model = ChatRoomModel::getChatRoomModel(2);
    // if(!model.has_value()){
    //     model = ChatRoomModel();
    //     model->setName(User::getUser(2)->getFirstName());
    //     vector<int> x = {User::getCurrentUser()->getId(),2};
    //     model->setUsers(x);
    // }
    // MainWindow window;
    // window.show();
    // User::setCurrentUser(User::getUsers()[1]);
    // auto model = ChatRoomModel::getChatRoomModel(2);
    // if(!model.has_value()){
    //     model = ChatRoomModel();
    //     model->setName(User::getUser(2)->getFirstName());
    //     vector<int> x = {User::getCurrentUser()->getId(),2};
    //     model->setUsers(x);
    // }
    if (user.has_value()) {
        MainWindow *window = new MainWindow();
        window->show();
    }
    else {
        Login * login = new Login();
        login->show();
    }
    int code = app.exec();
    User::writeCurrentUser();
    User::writeUsers();
    ChatRoomModel::writeChatRoomModels();
    return code;
}

