#include "mainwindow.h"
#include "PrivacySettings.h"
#include <QApplication>
#include "About.h"
#include "header.h"
#include "sending.h"
#include "recording.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // header *h = new header();
    // h->show();
    // Widget w;
    // w.show();
    Recording s;
    s.show();

    return a.exec();
}
