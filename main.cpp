#include <QApplication>
#include "ChatRoom.h"
#include "ChatRoomModel.h"
#include "StatusWindow/StatusWindow.h"
#include "mainwindow.h"
#include  "User.h"
#include "Login.h"
#include "Story.h"
#include "ui/Settings/settings.h"
#include "AboutG.h"
using namespace std;
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ChatRoomModel::readChatRoomModels();
   // Login* login = new Login();
    //login->show();
    // User::readUsers();
    // User bruce("11", "1", "Bruce", "Wayne", {}, {}, {}, {});
    // User barbra("?", "2", "Barbra", "Gordan", {}, {}, {}, {});
    // User dick("?", "2", "Dick", "GraySon", {}, {}, {}, {});
    // Story stor1(bruce.getId(), Date::getNow(), "الله اكبر", "", {});
    // Story stor2(barbra.getId(), Date::getNow(), "الله اكبر", "", {});
    // Story stor3(dick.getId(), Date::getNow(), "انطر ابلاكاش", "", {});
    // bruce.addStory(stor1);
    // barbra.addStory(stor2);
    // dick.addStory(stor3);
    // bruce.addContact(barbra.getId());
    // barbra.addContact(bruce.getId());
    // bruce.addContact(dick.getId());
    // dick.addContact(bruce.getId());
    // barbra.save();
    // bruce.save();
    // dick.save();
    // User::setCurrentUser(bruce);
    // User user = User::getCurrentUser().value();
    // StatusWindow *s = new StatusWindow(user);
    // s->show();
    User::readUsers();
    User::readCurrentUser();
    //User::getCurrentUser()->addContact(User::getUser(1)->getId());
    optional<User> optUser = User::getCurrentUser();
    if (!optUser.has_value()) {
       // Login *login = new Login();
        //login->show();
    }
    else {
        // Settings * s = new Settings();
        // s->show();
        AboutG *g = new AboutG(1,1);
        g->show();
        // MainWindow *d = new MainWindow();
        // d->show();
    }
    if(app.exec()==0)
    {
        User::writeCurrentUser();
        // User::writeUsers();
        ChatRoomModel::writeChatRoomModels();
        return 0;
    }else{
        return 0;
    }
}

