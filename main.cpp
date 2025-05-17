#include <QApplication>
#include "ChatRoom.h"
#include "ChatRoomModel.h"
#include  "User.h"
#include "Login.h"
using namespace std;
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ChatRoomModel::readChatRoomModels();
    User::readUsers();
    // Login *login = new Login;
    // login->show();
    optional<User> o = User::getUser(3);
    User::setCurrentUser(o.value());
    ChatRoomModel::readChatRoomModels();

    optional<User> optUser = User::getCurrentUser();
    if (!optUser.has_value()) {
        Login *login = new Login;
        login->show();
    }
    else {
        ChatRoom *chat = new ChatRoom(1);
        chat->show();
    }
    if(app.exec()==0)
    {
        User::writeUsers();
        ChatRoomModel::writeChatRoomModels();
        return 0;
    }else{
        return 0;
    }
}

