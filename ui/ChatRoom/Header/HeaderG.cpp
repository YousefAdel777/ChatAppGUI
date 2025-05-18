#include "HeaderG.h"
#include "ui_HeaderG.h"

HeaderG::HeaderG(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HeaderG)
{
    ui->setupUi(this);
}

HeaderG::~HeaderG()
{
    delete ui;
}
