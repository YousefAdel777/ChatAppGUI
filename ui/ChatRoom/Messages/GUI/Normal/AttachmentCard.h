#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
#include <QFileInfo>
#include <QDateTime>
#include "message.h"
class AttachmentCard : public Message {
    Q_OBJECT

public:
    explicit AttachmentCard(MessageModel& msg,Message*Reply = nullptr,QWidget *parent=nullptr);
    void paintEvent(QPaintEvent *event) override;
    void Adjust() override;
private slots:
    void onOpenClicked();
    void onSaveAsClicked();

public:
    QString filePath,fileName;
    QLabel *ReadStatus;
    QWidget *ReadStatusContainer = nullptr;
};
