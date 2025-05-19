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
}

MainWindow::~MainWindow()
{
    delete ui;
}
