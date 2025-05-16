#include "PrivacySettings.h"
#include <QApplication>
#include "About.h"
#include "header.h"
#include "sending.h"
#include "recording.h"
#include "User.h"
#include "ui/Settings/settings.h"
#include "ui/Login/login.h"
#include "ui/StatusWindow/StatusWindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    User::readUsers();
    User::readCurrentUser();

    if (User::getCurrentUser().has_value()) {
        // Settings *settings = new Settings;
        // settings->show();
        StatusWindow *status = new StatusWindow();
        status->show();
    }
    else {
        Login *login = new Login;
        login->show();
    }

    int code = a.exec();

    User::writeCurrentUser();
    User::writeUsers();

    // // header *h = new header();
    // // h->show();
    // // Widget w;
    // // w.show();
    // Recording s;
    // s.show();

    return code;
}
