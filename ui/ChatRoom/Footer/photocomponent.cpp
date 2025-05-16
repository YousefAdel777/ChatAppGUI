#include "photocomponent.h"
#include "ui_photocomponent.h"
#include <QFileInfo>

PhotoComponent::PhotoComponent(QString path,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PhotoComponent)
{
    QFileInfo info(path);
    ui->setupUi(this);
    ui->name->setWordWrap(true);
    ui->name->setText(QFontMetrics(ui->name->font()).elidedText(info.fileName(), Qt::ElideRight, width()-30));
    Image = new HighQualityImage(path,170);
    ui->PhotoContainer->addWidget(Image);
}

PhotoComponent::~PhotoComponent()
{
    delete ui;
}

void PhotoComponent::on_Remove_clicked()
{
    emit deleteRequest(this);
}

