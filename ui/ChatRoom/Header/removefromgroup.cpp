//
// Created by Dell on 5/18/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_RemoveFromGroup.h" resolved

#include "removefromgroup.h"
#include "ui_RemoveFromGroup.h"


RemoveFromGroup::RemoveFromGroup(QWidget *parent) :
    QWidget(parent), ui(new Ui::RemoveFromGroup) {
    ui->setupUi(this);
}



RemoveFromGroup::~RemoveFromGroup() {
    delete ui;
}
