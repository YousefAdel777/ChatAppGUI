#include "filescomponent.h"
#include "ui_filescomponent.h"
#include <QFileInfo>
FilesComponent::FilesComponent(QString path,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FilesComponent),path(path.toStdString())
{
    ui->setupUi(this);
    QFileInfo info(path);
    ui->name->setWordWrap(true);
    ui->name->setText(QFontMetrics(ui->name->font()).elidedText(info.fileName(), Qt::ElideRight, width()-30));
}

FilesComponent::~FilesComponent()
{
    delete ui;
}

std::string FilesComponent::getPath(){
    return path;
}

void FilesComponent::on_Remove_clicked()
{
    emit deleteRequest(this);
}

