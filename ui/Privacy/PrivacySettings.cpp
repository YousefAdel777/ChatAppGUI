#include "PrivacySettings.h"
#include "./ui_PrivacySettings.h"
using namespace std;

QRegion Widget::DrawTheButton(QPainterPath path, QRect rect, int radius)
{
    path.moveTo(rect.topLeft() + QPoint(radius, 0));
    path.lineTo(rect.topRight() - QPoint(radius, 0));
    path.quadTo(rect.topRight(), rect.topRight() + QPoint(0, radius));
    path.lineTo(rect.bottomRight() - QPoint(0, radius));
    path.quadTo(rect.bottomRight(), rect.bottomRight() - QPoint(radius, 0));
    path.lineTo(rect.bottomLeft() + QPoint(radius, 0));
    path.quadTo(rect.bottomLeft(), rect.bottomLeft() - QPoint(0, radius));
    path.lineTo(rect.topLeft() + QPoint(0, radius));
    path.quadTo(rect.topLeft(), rect.topLeft() + QPoint(radius, 0));
    QRegion mask(path.toFillPolygon().toPolygon());
    return mask;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->LastSeenAndOnlineLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->LastSeenAndOnlineCircle->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->LastSeenAndOnlineChoice->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->ProfilePhotoLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->ProfilePhotoCircle->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->ProfilePhotoChoice->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->AboutLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->AboutCircle->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->AboutChoice->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->StatusLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->StatusCircle->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->StatusChoice->setAttribute(Qt::WA_TransparentForMouseEvents);
    QPainterPath LastSeenAndOnlinePath;
    QRect LastSeenAndOnlineRect = ui->LastSeenAndOnlineButton->rect();
    ui->LastSeenAndOnlineButton->setMask(DrawTheButton(LastSeenAndOnlinePath, LastSeenAndOnlineRect, 30));
    QPainterPath ProfilePhotoPath;
    QRect ProfilePhotoRect = ui->ProfilePhotoButton->rect();
    ui->ProfilePhotoButton->setMask(DrawTheButton(ProfilePhotoPath, ProfilePhotoRect, 30));
    QPainterPath AboutPath;
    QRect AboutRect = ui->AboutButton->rect();
    ui->AboutButton->setMask(DrawTheButton(AboutPath, AboutRect, 30));
    QPainterPath StatusPath;
    QRect StatusRect = ui->StatusButton->rect();
    ui->StatusButton->setMask(DrawTheButton(StatusPath, StatusRect, 30));
    QPainterPath LastSeenAndOnlineBackPath;
    QRect LastSeenAndOnlineBackRect = ui->LastSeenAndOnlineBack->rect();
    ui->LastSeenAndOnlineBack->setMask(DrawTheButton(LastSeenAndOnlineBackPath, LastSeenAndOnlineBackRect, 12));
    QPainterPath ProfilePhotoBackPath;
    QRect ProfilePhotoBackRect = ui->ProfilePhotoBack->rect();
    ui->ProfilePhotoBack->setMask(DrawTheButton(ProfilePhotoBackPath, ProfilePhotoBackRect, 12));
    QPainterPath AboutBackPath;
    QRect AboutBackRect = ui->AboutBack->rect();
    ui->AboutBack->setMask(DrawTheButton(AboutBackPath, AboutBackRect, 12));
    QPainterPath StatusBackPath;
    QRect StatusBackRect = ui->StatusBack->rect();
    ui->StatusBack->setMask(DrawTheButton(StatusBackPath, StatusBackRect, 12));
    QPainterPath ExcludeContactsBackPath;
    QRect ExcludeContactsBackRect = ui->ExcludeContactsBack->rect();
    ui->ExcludeContactsBack->setMask(DrawTheButton(ExcludeContactsBackPath, ExcludeContactsBackRect, 12));
    ui->LastSeenChoiceEveryone->click();
    ui->OnlineChoiceEveryone->click();
    ui->AboutChoiceEveryone->click();
    ui->ProfilePhotoChoiceEveryone->click();
    ui->StatusChoiceMyContacts->click();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_LastSeenAndOnlineButton_clicked()
{
    ui->PrivacyWidgets->setCurrentWidget(ui->LastSeenAndOnlineWidget);
    CurrentWidget = LastSeenAndOnline;
}


void Widget::on_ProfilePhotoButton_clicked()
{
    ui->PrivacyWidgets->setCurrentWidget(ui->ProfilePhotoWidget);
    CurrentWidget = ProfilePhoto;
}


void Widget::on_StatusButton_clicked()
{
    ui->PrivacyWidgets->setCurrentWidget(ui->StatusWidget);
    CurrentWidget = Status;
}


void Widget::on_AboutButton_clicked()
{
    ui->PrivacyWidgets->setCurrentWidget(ui->AboutWidget);
    CurrentWidget = About;
}


void Widget::on_StatusBack_clicked()
{
    ui->PrivacyWidgets->setCurrentWidget(ui->MainPrivacyWidget);
    CurrentWidget = Main;
}


void Widget::on_ProfilePhotoBack_clicked()
{
    ui->PrivacyWidgets->setCurrentWidget(ui->MainPrivacyWidget);
    CurrentWidget = Main;
}


void Widget::on_LastSeenAndOnlineBack_clicked()
{
    ui->PrivacyWidgets->setCurrentWidget(ui->MainPrivacyWidget);
    CurrentWidget = Main;
}


void Widget::on_AboutBack_clicked()
{
    ui->PrivacyWidgets->setCurrentWidget(ui->MainPrivacyWidget);
    CurrentWidget = Main;
}


void Widget::on_ExcludeContactsBack_clicked()
{
    if (CurrentWidget == LastSeenAndOnline)
        ui->PrivacyWidgets->setCurrentWidget(ui->LastSeenAndOnlineWidget);
    else if (CurrentWidget == ProfilePhoto)
        ui->PrivacyWidgets->setCurrentWidget(ui->ProfilePhotoWidget);
    else if (CurrentWidget == About)
        ui->PrivacyWidgets->setCurrentWidget(ui->AboutWidget);
    else if (CurrentWidget == Status)
    {
        ui->PrivacyWidgets->setCurrentWidget(ui->StatusWidget);
        ui->ExcludeContactsWidgetLabel->setText("Exlcude contacts");
    }
}


void Widget::on_LastSeenChoiceEveryone_clicked()
{
    LastSeenMode = Everyone;
    if (OnlineMode == Everyone)
    {
        ui->LastSeenAndOnlineChoice->setText("Everyone, Everyone");
    }
    else
    {
        ui->LastSeenAndOnlineChoice->setText("Everyone");
    }
}


void Widget::on_LastSeenChoiceMyContacts_clicked()
{
    LastSeenMode = MyContacts;
    if (OnlineMode == Everyone)
    {
        ui->LastSeenAndOnlineChoice->setText("My Contacts, Everyone");
    }
    else
    {
        ui->LastSeenAndOnlineChoice->setText("My Contacts");
    }
}


void Widget::on_LastSeenChoiceMyContactsExept_clicked()
{
    LastSeenMode = MyContactsExept;
    ui->PrivacyWidgets->setCurrentWidget(ui->ExcludeContactsWidget);
    QString tmp = QString::number(LastSeenContactsExeptNum);
    if (OnlineMode == Everyone)
    {
        ui->LastSeenAndOnlineChoice->setText(tmp + " Contacts excluded, Everyone");
    }
    else
    {
        ui->LastSeenAndOnlineChoice->setText(tmp + " Contacts excluded");
    }
}


void Widget::on_LastSeenChoiceNobody_clicked()
{
    LastSeenMode = Nobody;
    if (OnlineMode == Everyone)
    {
        ui->LastSeenAndOnlineChoice->setText("Nobody, Everyone");
    }
    else
    {
        ui->LastSeenAndOnlineChoice->setText("Nobody");
    }
}


void Widget::on_OnlineChoiceEveryone_clicked()
{
    OnlineMode = Everyone;
    if (LastSeenMode == Everyone)
        ui->LastSeenAndOnlineChoice->setText("Everyone, Everyone");
    else if (LastSeenMode == MyContacts)
        ui->LastSeenAndOnlineChoice->setText("My contacts, Everyone");
    else if (LastSeenMode == Nobody)
        ui->LastSeenAndOnlineChoice->setText("Nobody, Everyone");
    else if (LastSeenMode == MyContactsExept)
    {
        QString tmp = QString::number(LastSeenContactsExeptNum);
        ui->LastSeenAndOnlineChoice->setText(tmp + " Contacts excluded, Everyone");
    }
}


void Widget::on_OnlineChoiceSameAsLastSeen_clicked()
{
    OnlineMode = LastSeenMode;
    if (LastSeenMode == MyContactsExept)
    {
        QString tmp = QString::number(LastSeenContactsExeptNum);
        ui->LastSeenAndOnlineChoice->setText(tmp + " Contacts excluded");
    }
    else if (LastSeenMode == Everyone)
        ui->LastSeenAndOnlineChoice->setText("Everyone");
    else if (LastSeenMode == MyContacts)
        ui->LastSeenAndOnlineChoice->setText("My contacts");
    else if (LastSeenMode == Nobody)
        ui->LastSeenAndOnlineChoice->setText("Nobody");
}


void Widget::on_AboutChoiceEveryone_clicked()
{
    AboutMode = Everyone;
    ui->AboutChoice->setText("Everyone");
}


void Widget::on_AboutChoiceMyContacts_clicked()
{
    AboutMode = MyContacts;
    ui->AboutChoice->setText("My contacts");
}


void Widget::on_AboutChoiceMyContactsExept_clicked()
{
    AboutMode = MyContactsExept;
    ui->PrivacyWidgets->setCurrentWidget(ui->ExcludeContactsWidget);
    QString tmp = QString::number(AboutContactsExeptNum);
    ui->AboutChoice->setText(tmp + " Contacts excluded");
}


void Widget::on_AboutChoiceNobody_clicked()
{
    AboutMode = Nobody;
    ui->AboutChoice->setText("Nobody");
}


void Widget::on_ProfilePhotoChoiceEveryone_clicked()
{
    ProfilePhotoMode = Everyone;
    ui->ProfilePhotoChoice->setText("Everyone");
}


void Widget::on_ProfilePhotoChoiceMyContacts_clicked()
{
    ProfilePhotoMode = MyContacts;
    ui->ProfilePhotoChoice->setText("My Contacts");
}


void Widget::on_ProfilePhotoChoiceMyContactsExept_clicked()
{
    ProfilePhotoMode = MyContactsExept;
    ui->PrivacyWidgets->setCurrentWidget(ui->ExcludeContactsWidget);
    QString tmp = QString::number(ProfilePhotoContactsExeptNum);
    ui->ProfilePhotoChoice->setText(tmp + " Contacts excluded");
}


void Widget::on_ProfilePhotoChoiceNobody_clicked()
{
    ProfilePhotoMode = Nobody;
    ui->ProfilePhotoChoice->setText("Nobody");
}


void Widget::on_StatusChoiceMyContacts_clicked()
{
    StatusMode = MyContacts;
    ui->StatusChoice->setText("My Contacts");
}


void Widget::on_StatusChoiceMyContactsExept_clicked()
{
    StatusMode = MyContactsExept;
    ui->PrivacyWidgets->setCurrentWidget(ui->ExcludeContactsWidget);
    QString tmp = QString::number(StatusContactsExeptNum);
    ui->StatusChoice->setText(tmp + " Contacts excluded");
}


void Widget::on_StatusChoiceOnlyShareWith_clicked()
{
    StatusMode = OnlyShareWith;
    ui->ExcludeContactsWidgetLabel->setText("Select Contacts");
    ui->PrivacyWidgets->setCurrentWidget(ui->ExcludeContactsWidget);
    QString tmp = QString::number(StatusContactsShareWithNum);
    ui->StatusChoice->setText(tmp + " Contacts included");
}

