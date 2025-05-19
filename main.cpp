#include <QApplication>
#include "chatlist.h"
#include "mainwindow.h"
#include  "User.h"
#include "Login.h"
<<<<<<< HEAD
#include "StatusWindow/StatusWindow.h"
=======
>>>>>>> bfe048e06d81a16234acd884dc2328c822dc9f26
using namespace std;
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ChatRoomModel::readChatRoomModels();
    User::readUsers();
<<<<<<< HEAD
    User::setCurrentUser(User::getUsers()[0]);
    User user = User::getCurrentUser().value();
    StatusWindow * w = new StatusWindow(user);
    w->show();
    // auto model = ChatRoomModel::getChatRoomModel(2);
    // if(!model.has_value()){
    //     model = ChatRoomModel();
    //     model->setName(User::getUser(2)->getFirstName());
    //     vector<int> x = {User::getCurrentUser()->getId(),2};
    //     model->setUsers(x);
    // }
    // MainWindow window;
    // window.show();
=======
    User::setCurrentUser(User::getUsers()[1]);
    auto model = ChatRoomModel::getChatRoomModel(2);
    if(!model.has_value()){
        model = ChatRoomModel();
        model->setName(User::getUser(2)->getFirstName());
        vector<int> x = {User::getCurrentUser()->getId(),2};
        model->setUsers(x);
    }
    MainWindow window;
    window.show();
>>>>>>> bfe048e06d81a16234acd884dc2328c822dc9f26
    if(app.exec()==0)
    {
        User::writeUsers();
        ChatRoomModel::writeChatRoomModels();
        return 0;
    }else{
        return 0;
    }
}

