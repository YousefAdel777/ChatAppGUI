#include "mainwindow.h"
#include "PrivacySettings.h"
#include <QApplication>
#include "About.h"
#include "header.h"
#include<QFontDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Form *t = new Form();
    // t->show();
    // QFontDatabase::addApplicationFont(":/static/Roboto-Condensed-SemiBold.ttf");
    // header *h = new header();
    // h->show();
    Widget w;
    w.show();
    return a.exec();
    return a.exec();
}
