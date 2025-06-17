#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Mainwidget = new ChatWidget(this);
    auto user = User::getCurrentUser().value();
    Status = new StatusWindow(user);
    settings = new Settings();
    connect(Mainwidget,&ChatWidget::statusClicked,this,[=]{
        Mainwidget->setParent(nullptr);
        Status->setParent(this);
        Status->show();
    });
    connect(Status,&StatusWindow::backClicked,this,[=](){
        Mainwidget->setParent(this);
        Status->setParent(nullptr);
        Mainwidget->show();
    });
    connect(Mainwidget,&ChatWidget::settingsClicked,this,[=]{
        Mainwidget->setParent(nullptr);
        settings->setParent(this);
        settings->show();
    });
    connect(settings,&Settings::settingsClosed,this,[=](){
        Mainwidget->setParent(this);
        settings->setParent(nullptr);
        Mainwidget->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
