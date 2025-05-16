#include "currentselectedcontainer.h"
#include "ui_currentselectedcontainer.h"
#include <photocomponent.h>

CurrentSelectedContainer::CurrentSelectedContainer(bool type,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CurrentSelectedContainer),type(type)
{
    ui->setupUi(this);
    ui->horizontalLayout->setAlignment(Qt::AlignLeft);
}

CurrentSelectedContainer::~CurrentSelectedContainer()
{
    delete ui;
}

void CurrentSelectedContainer::addToContainer(PhotoComponent* widget){
    ui->horizontalLayout->addWidget(widget);
    connect(widget,&PhotoComponent::deleteRequest,this,[=](QWidget *widget){
        ui->horizontalLayout->removeWidget(widget);
        widget->setParent(nullptr);
        delete widget;
        if(!ui->horizontalLayout->count())
            emit becameEmpty();
    });
}

void CurrentSelectedContainer::addToContainer(FilesComponent* widget){
    ui->horizontalLayout->addWidget(widget);
    connect(widget,&FilesComponent::deleteRequest,this,[=](QWidget *widget){
        ui->horizontalLayout->removeWidget(widget);
        widget->setParent(nullptr);
        delete widget;
        if(!ui->horizontalLayout->count())
            emit becameEmpty();
    });
}


QHBoxLayout* CurrentSelectedContainer::getContainer(){
    return ui->horizontalLayout;
}
