#include "ContactWidget.h"
#include "ui_ContactWidget.h"

ContactWidget::ContactWidget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::ContactWidget)
{
    ui->setupUi(this);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->setMinimumHeight(50);
    this->setMinimumWidth(340);
}

ContactWidget::~ContactWidget()
{
    delete ui;
}

void ContactWidget::setName(const QString &Name)
{
    ui->name->setText(Name);
}

void ContactWidget::setIcon(const QPixmap &Icon)
{
    ui->icon->setPixmap(Icon);
}

bool ContactWidget::CheckBoxIsChecked()
{
    return ui->CheckBox->isChecked();
}

void ContactWidget::CheckCheckBox()
{
    ui->CheckBox->setCheckState(Qt::Checked);
}

void ContactWidget::UnCheckCheckBox()
{
    ui->CheckBox->setCheckState(Qt::Unchecked);
}

void ContactWidget::setId(long long id)
{
    this->id = id;
}

long long ContactWidget::getId()
{
    return this->id;
}
