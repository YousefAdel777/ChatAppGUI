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

void Widget::FixButtonsBorder()
{
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
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->PrivacyWidgets->setCurrentWidget(ui->MainPrivacyWidget);
    FixButtonsBorder();
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

void Widget::PrepareMyContactsExcept(set<int> Contacts,
                                     unordered_set<int> Excluded)
{
    QWidget *container = new QWidget();
    QVBoxLayout *ContactLayout = new QVBoxLayout(container);
    ContactLayout->setSpacing(3);
    ContactLayout->setContentsMargins(0, 0, 0, 0);

    for (auto i : Contacts)
    {
        ContactWidget *CW = new ContactWidget();
        CW->setName(QString::number(i));
        CW->setId(i);
        this->ContactWidgets.push_back(CW);
        if (!Excluded.empty() && Excluded.find(i) != Excluded.end())
            CW->CheckCheckBox();
        ContactLayout->addWidget(CW);
    }

    ContactLayout->addStretch();
    container->setLayout(ContactLayout);
    ui->scrollArea->setWidget(container);
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    container->adjustSize();
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
}

unordered_set<int> Widget::SetMyContactsExcept(vector<ContactWidget*> v)
{
    unordered_set<int> us;
    for (auto i : v)
    {
        if (i->CheckBoxIsChecked())
            us.insert(i->getId());
    }
    return us;
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
    {
        this->HideLastSeen[this->TmpID].clear();
        this->HideLastSeen[this->TmpID] = SetMyContactsExcept(ContactWidgets);
        for (auto i : TmpUsers)
            this->HideLastSeen[this->TmpID].insert(i);
        LastSeenContactsExeptNum = this->HideLastSeen[this->TmpID].size() - TmpUsers.size();
        QString tmp = QString::number(LastSeenContactsExeptNum);
        if (OnlineMode == Everyone)
        {
            ui->LastSeenAndOnlineChoice->setText(tmp + " Contacts excluded, Everyone");
        }
        else
        {
            ui->LastSeenAndOnlineChoice->setText(tmp + " Contacts excluded");
        }
        ui->PrivacyWidgets->setCurrentWidget(ui->LastSeenAndOnlineWidget);
    }
    else if (CurrentWidget == ProfilePhoto)
    {
        this->HidePhoto[this->TmpID] = SetMyContactsExcept(ContactWidgets);
        for (auto i : TmpUsers)
            this->HidePhoto[this->TmpID].insert(i);
        ProfilePhotoContactsExeptNum = this->HidePhoto[this->TmpID].size() - TmpUsers.size();
        QString tmp = QString::number(ProfilePhotoContactsExeptNum);
        ui->ProfilePhotoChoice->setText(tmp + " Contacts excluded");
        ui->PrivacyWidgets->setCurrentWidget(ui->ProfilePhotoWidget);
    }
    else if (CurrentWidget == About)
    {
        this->HideAbout[this->TmpID] = SetMyContactsExcept(ContactWidgets);
        for (auto i : TmpUsers)
            this->HideAbout[this->TmpID].insert(i);
        AboutContactsExeptNum = this->HideAbout[this->TmpID].size() - TmpUsers.size();
        QString tmp = QString::number(AboutContactsExeptNum);
        ui->AboutChoice->setText(tmp + " Contacts excluded");
        ui->PrivacyWidgets->setCurrentWidget(ui->AboutWidget);
    }
    else if (CurrentWidget == Status)
    {
        if (StatusMode == MyContactsExept)
        {
            this->HideStatus[this->TmpID] = SetMyContactsExcept(ContactWidgets);
            for (auto i : TmpUsers)
                this->HideStatus[this->TmpID].insert(i);
            StatusContactsExeptNum = this->HideStatus[this->TmpID].size() - TmpUsers.size();
            QString tmp = QString::number(StatusContactsExeptNum);
            ui->StatusChoice->setText(tmp + " Contacts excluded");
        }
        else if (StatusMode == OnlyShareWith)
        {
            unordered_set <int> Tmp;
            Tmp = SetMyContactsExcept(ContactWidgets);
            this->HideStatus[this->TmpID].clear();
            for (auto i : TmpUsers)
                this->HideStatus[this->TmpID].insert(i);
            for (auto i : TmpContacts)
                if (Tmp.size() && Tmp.find(i) == Tmp.end())
                    this->HideStatus[this->TmpID].insert(i);
            StatusContactsShareWithNum = Tmp.size();
            Tmp.clear();
            QString tmp = QString::number(StatusContactsShareWithNum);
            ui->StatusChoice->setText(tmp + " Contacts included");
        }
        ui->PrivacyWidgets->setCurrentWidget(ui->StatusWidget);
        ui->ExcludeContactsWidgetLabel->setText("Exlcude contacts");
    }
    ContactWidgets.clear();
}


void Widget::on_LastSeenChoiceEveryone_clicked()
{
    LastSeenMode = Everyone;
    this->HideLastSeen[this->TmpID].clear();
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
    for (auto i : TmpUsers)
        this->HideLastSeen[this->TmpID].insert(i);
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
    if (LastSeenMode != MyContactsExept)
    {
        this->HideLastSeen[this->TmpID].clear();
        for (auto i : TmpUsers)
            this->HideLastSeen[this->TmpID].insert(i);
        LastSeenMode = MyContactsExept;
    }
    PrepareMyContactsExcept(this->TmpContacts, this->HideLastSeen[this->TmpID]);
    ui->PrivacyWidgets->setCurrentWidget(ui->ExcludeContactsWidget);
}


void Widget::on_LastSeenChoiceNobody_clicked()
{
    LastSeenMode = Nobody;
    for (auto i : TmpUsers)
        this->HideLastSeen[this->TmpID].insert(i);
    for (auto i : TmpContacts)
        this->HideLastSeen[this->TmpID].insert(i);
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
    this->HideOnline[this->TmpID].clear();
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
    this->HideOnline[this->TmpID] = this->HideLastSeen[this->TmpID];
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
    this->HideAbout[this->TmpID].clear();
    ui->AboutChoice->setText("Everyone");
}


void Widget::on_AboutChoiceMyContacts_clicked()
{
    AboutMode = MyContacts;
    for (auto i : TmpUsers)
        this->HideAbout[this->TmpID].insert(i);
    ui->AboutChoice->setText("My contacts");
}


void Widget::on_AboutChoiceMyContactsExept_clicked()
{
    if (AboutMode != MyContactsExept)
    {
        AboutMode = MyContactsExept;
        this->HideAbout[this->TmpID].clear();
        for (auto i : TmpUsers)
            this->HideAbout[this->TmpID].insert(i);
    }
    PrepareMyContactsExcept(this->TmpContacts, this->HideAbout[this->TmpID]);
    ui->PrivacyWidgets->setCurrentWidget(ui->ExcludeContactsWidget);
}


void Widget::on_AboutChoiceNobody_clicked()
{
    AboutMode = Nobody;
    for (auto i : TmpUsers)
        this->HideAbout[this->TmpID].insert(i);
    for (auto i : TmpContacts)
        this->HideAbout[this->TmpID].insert(i);
    ui->AboutChoice->setText("Nobody");
}


void Widget::on_ProfilePhotoChoiceEveryone_clicked()
{
    ProfilePhotoMode = Everyone;
    this->HidePhoto[this->TmpID].clear();
    ui->ProfilePhotoChoice->setText("Everyone");
}


void Widget::on_ProfilePhotoChoiceMyContacts_clicked()
{
    ProfilePhotoMode = MyContacts;
    for (auto i : TmpUsers)
        this->HidePhoto[this->TmpID].insert(i);
    ui->ProfilePhotoChoice->setText("My Contacts");
}


void Widget::on_ProfilePhotoChoiceMyContactsExept_clicked()
{
    if (ProfilePhotoMode != MyContactsExept)
    {
        ProfilePhotoMode = MyContactsExept;
        this->HidePhoto[this->TmpID].clear();
        for (auto i : TmpUsers)
            this->HidePhoto[this->TmpID].insert(i);
    }
    PrepareMyContactsExcept(this->TmpContacts, this->HidePhoto[this->TmpID]);
    ui->PrivacyWidgets->setCurrentWidget(ui->ExcludeContactsWidget);
}


void Widget::on_ProfilePhotoChoiceNobody_clicked()
{
    ProfilePhotoMode = Nobody;
    for (auto i : TmpUsers)
        this->HidePhoto[this->TmpID].insert(i);
    for (auto i : TmpContacts)
        this->HidePhoto[this->TmpID].insert(i);
    ui->ProfilePhotoChoice->setText("Nobody");
}


void Widget::on_StatusChoiceMyContacts_clicked()
{
    StatusMode = MyContacts;
    for (auto i : TmpUsers)
        this->HideStatus[this->TmpID].insert(i);
    ui->StatusChoice->setText("My Contacts");
}


void Widget::on_StatusChoiceMyContactsExept_clicked()
{
    if (StatusMode != MyContactsExept)
    {
        StatusMode = MyContactsExept;
        this->HideStatus[this->TmpID].clear();
        for (auto i : TmpUsers)
            this->HideStatus[this->TmpID].insert(i);
    }
    PrepareMyContactsExcept(this->TmpContacts, this->HideStatus[this->TmpID]);
    ui->PrivacyWidgets->setCurrentWidget(ui->ExcludeContactsWidget);
}


void Widget::on_StatusChoiceOnlyShareWith_clicked()
{
    unordered_set <int> Tmp;
    if (StatusMode == OnlyShareWith)
    {
        for (auto i : TmpContacts)
            if (this->HideStatus[this->TmpID].size() && this->HideStatus[this->TmpID].find(i) == this->HideStatus[this->TmpID].end())
                Tmp.insert(i);

    }
    else
    {
        StatusMode = OnlyShareWith;
        this->HideStatus[this->TmpID].clear();
        for (auto i : TmpUsers)
            this->HideStatus[this->TmpID].insert(i);
    }
    PrepareMyContactsExcept(this->TmpContacts, Tmp);
    Tmp.clear();
    ui->ExcludeContactsWidgetLabel->setText("Select Contacts");
    ui->PrivacyWidgets->setCurrentWidget(ui->ExcludeContactsWidget);
}


void Widget::on_ExcludeContactsSelectAll_clicked()
{
    int TmpCnt = 0;
    for (auto i : this->ContactWidgets)
        if (i->CheckBoxIsChecked())
            TmpCnt++;
    if (TmpCnt > this->TmpContacts.size() / 2)
    {
        for (auto i : this->ContactWidgets)
            i->UnCheckCheckBox();
    }
    else
    {
        for (auto i : this->ContactWidgets)
            i->CheckCheckBox();
    }
}

