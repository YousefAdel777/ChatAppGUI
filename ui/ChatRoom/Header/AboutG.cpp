#include "AboutG.h"
#include "ui_AboutG.h"
#include "MemberCard.h"
QVector<MemberCard*> AboutG::memberCards;
AboutG::AboutG(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AboutG)
{
    ui->setupUi(this);
    members = 0;
    a = new AddMembers();
    container = new QWidget();
    contactLayout = new QVBoxLayout(container);
    contactLayout->setSpacing(3);
    contactLayout->setContentsMargins(0,0,0,0);
    for(auto card:memberCards){
        contactLayout->addWidget(card);
        ++members;
    }
    contactLayout->addStretch();
    container->setLayout(contactLayout);
    ui->scrollArea_2->setWidget(container);
    ui->scrollArea_2->setWidgetResizable(true);
    container->adjustSize();
    container->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Maximum);
    ui->MembersNo->setText(QString::number(members)+" Members");
    connect(a,&AddMembers::add,this,[=](){
        for(auto card:memberCards){
            contactLayout->addWidget(card);
            ++members;
        }
        contactLayout->addStretch();
        container->adjustSize();
        ui->MembersNo->setText(QString::number(members)+" Members");
        ui->scrollArea_2->widget()->updateGeometry();
    });
}

AboutG::~AboutG()
{
    delete ui;
}

void AboutG::on_addMember_clicked()
{
    a->show();
}
