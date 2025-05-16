#include "About.h"
#include "ui_About.h"
#include "User.h"
#include<iostream>
Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->verticalLayout_2->setAlignment(Qt::AlignTop);
    ui->About->setFixedSize(ui->About->sizeHint());
    ui->Name->setText(User::getCurrentUser()->getFirstName().data());
    ui->PhoneNumber->setText(User::getCurrentUser()->getMobileNumber().data());

    ui->About->setText(User::getCurrentUser()->getUserProfileDescription().getAbout().data());

    ui->Bio->setFixedHeight(ui->About->sizeHint().height()+60);
    ui->widget_3->setFixedHeight(ui->CummonGroups->sizeHint().height()+70);
    ui->widget_2->setGeometry(0,ui->widget_3->geometry().top()+ui->widget_3->height()+1,ui->widget_2->width(),ui->widget_2->height());
}
void Form::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    setFixedHeight(std::min(720,ui->widget_2->geometry().bottom()+20));
 }
Form::~Form()
{
    delete ui;
}
