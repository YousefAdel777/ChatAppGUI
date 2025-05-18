#include "blockedwidget.h"
#include "ui_blockedwidget.h"

BlockedWidget::BlockedWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BlockedWidget)
{
    ui->setupUi(this);
}

BlockedWidget::~BlockedWidget()
{
    delete ui;
}
