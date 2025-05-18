#include "AttachmentCard.h"
#include <QFileDialog>
#include <QDesktopServices>
#include <QPainter>
#include <QStyleOption>
#include <QMimeDatabase>
#include <User.h>
#include <MessageModel.h>
AttachmentCard::AttachmentCard(MessageModel& msg,Message* Reply,QWidget *parent)
    : Message(msg,Reply,parent), filePath(msg.getContent().data())
{
    QFileInfo info(filePath);
    fileName = info.fileName();
    int h = 0;
    if(msg.option==MessageModel::REPLY){
        h = Reply->height();
    }
    setFixedSize(250,130+h);
    auto layout1 = new QVBoxLayout(this);
    QWidget *MessageBubble = new QWidget();
    layout1->addWidget(MessageBubble);
    layout1->setAlignment(Qt::AlignTop);
    layout1->setContentsMargins(0,0,0,0);
    layout1->setSpacing(0);
    // Layouts
    QVBoxLayout* mainLayout = new QVBoxLayout(MessageBubble);
    mainLayout->setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(8);
    // Top: icon + name + meta
    QHBoxLayout* topLayout = new QHBoxLayout();

    QLabel* iconLabel = new QLabel(MessageBubble);
    iconLabel->setPixmap(QIcon(":/Resources/AttachmentIcon.png").pixmap(40, 40));
    topLayout->addWidget(iconLabel);

    QVBoxLayout* textLayout = new QVBoxLayout();
    QLabel* nameLabel = new QLabel(MessageBubble);
    nameLabel->setStyleSheet("color:rgb(20,20,20); font-size: 15px;");
    nameLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    QFontMetrics metrics(nameLabel->font());
    QString elided = metrics.elidedText(info.fileName(), Qt::ElideRight, 200); // <-- adjust width if needed
    nameLabel->setText(elided);
    nameLabel->setToolTip(info.fileName()); // Show full name on hover

    textLayout->addWidget(nameLabel);

    QMimeDatabase db;
    QString type1 = db.mimeTypeForFile(info).comment();

    QLabel* metaLabel = new QLabel(
        QString("%1 KB, %2")
            .arg(info.size() / 1024)
            .arg(type1),
        this);
    metaLabel->setStyleSheet("font-size: 12px; color: rgb(70,70,70);");
    textLayout->addWidget(metaLabel);

    topLayout->addLayout(textLayout);
    mainLayout->addLayout(topLayout);

    // Middle: buttons
    QHBoxLayout* btnLayout = new QHBoxLayout();
    QPushButton* openBtn = new QPushButton("Open");
    QPushButton* saveBtn = new QPushButton("Save as...");
    openBtn->setStyleSheet("background-color: rgb(60,60,60); font-weight:bold; color: white; padding: 6px 12px; border-radius: 6px;");
    saveBtn->setStyleSheet("background-color: rgb(60,60,60); font-weight:bold; color: white; padding: 6px 12px; border-radius: 6px;");

    btnLayout->addWidget(openBtn);
    btnLayout->addWidget(saveBtn);
    mainLayout->addLayout(btnLayout);

    connect(openBtn, &QPushButton::clicked, this, &AttachmentCard::onOpenClicked);
    connect(saveBtn, &QPushButton::clicked, this, &AttachmentCard::onSaveAsClicked);
    if (msg.getUserID()==User::getCurrentUser()->getId())
    {
        ReadStatus = new QLabel(this);
        ReadStatus->setFixedSize(15,15);
        ReadStatusContainer = new QWidget(this);
        QVBoxLayout *ReadStatusLayout = new QVBoxLayout();
        ReadStatusLayout->addWidget(ReadStatus,0,Qt::AlignCenter);
        ReadStatusContainer->setLayout(ReadStatusLayout);
        string s = "border-image:url(:/Resources/";
        s+=((msg.status.getSeen())?"Read.png":"3.png");
        s+=") 5 stretch stretch; border-radius:7.5;";
        ReadStatus->setStyleSheet(s.data());
        ReadStatusContainer->setStyleSheet("background-color: #D3E8D2; border-radius:15");
    }
    if(msg.option==MessageModel::REPLY)
    {
        layout1->insertWidget(0,Reply);
        MessageBubble->setStyleSheet("background-color:rgb(214, 240, 209); padding-right:10px; padding-left:10px; border-bottom-left-radius:15px; border-bottom-right-radius:15px; font-size:12; color:#fff;");
    }else{
        if(Content.type==MessageModel::SENT){
            MessageBubble->setStyleSheet("background-color:rgb(214, 240, 209); padding-right:10px; padding-left:10px; border-bottom-left-radius:15px; border-top-left-radius:15px; border-bottom-right-radius:15px; font-size:12; color:#fff;");
        }else{
            MessageBubble->setStyleSheet("background-color:rgb(214, 240, 209); padding-right:10px; padding-left:10px; border-bottom-left-radius:15px; border-top-right-radius:15px; border-bottom-right-radius:15px; font-size:12; color:#fff;");
        }
    }

}

void AttachmentCard::onOpenClicked() {
    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}

void AttachmentCard::onSaveAsClicked() {
    QString savePath = QFileDialog::getSaveFileName(this, "Save As", QFileInfo(filePath).fileName());
    if (!savePath.isEmpty()) {
        QFile::copy(filePath, savePath);
    }
}

void AttachmentCard::Adjust(){
    if (Content.getUserID()==User::getCurrentUser()->getId())
        ReadStatusContainer->setGeometry(QRect(width()-30,height()-40,30,30));
}

void AttachmentCard::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
}
