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
    Login *login = new Login;
    login->show();
    if(app.exec()==0)
    {
        User::writeUsers();
        ChatRoomModel::writeChatRoomModels();
        return 0;
    }else{
        return 0;
    }
}

