#include "sending.h"
#include "ui_sending.h"
#include <iostream>
#include<QFileDialog>
#include<QMenu>
#include "recorder.h"
#include "recording.h"
#include <iostream>
#include <MessageModel.h>
#include <ChatRoom.h>
#include "recording.h"
using namespace std;
Sending::Sending(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Sending)
{
    ui->setupUi(this);
    connect(ui->textEdit,&QTextEdit::textChanged,this,&Sending::updateSize);
    container = nullptr;
    ui->container->setAlignment(Qt::AlignBottom);
}

QVBoxLayout* Sending::getContainer(){
    return ui->container;
}
void Sending::updateSize(){
    const int mn= 46,mx=100;
    QTextDocument* doc = ui->textEdit->document();
    int docHeight = doc->size().height();
    int extra = ui->textEdit->frameWidth() * 2 + 4;
    int requiredHeight = std::ceil(docHeight) + extra;
    if (requiredHeight < mn) {
        ui->textEdit->setFixedHeight(mn);
    } else {
        ui->textEdit->setFixedHeight(std::min(requiredHeight,mx));
    }
    setFixedHeight(ui->textEdit->height()+21);
    emit sizeChanged();
    if(doc->isEmpty()){
        ui->recordBtn->setIcon(QIcon(":/icons/mic.png"));
        status = 0;
    }else{
        ui->recordBtn->setIcon(QIcon(":/icons/Arrow.png"));
        status = 1;
    }
}
Sending::~Sending()
{
    delete ui;
}

void Sending::on_attachBtn_clicked()
{
    QMenu contextMenu(this);
    contextMenu.setWindowOpacity(0.9);
    contextMenu.setAttribute(Qt::WA_TranslucentBackground);
    contextMenu.setWindowFlags(contextMenu.windowFlags() | Qt::FramelessWindowHint);
    contextMenu.setStyleSheet("QMenu { background-color: rgba(30, 30, 30, 240); "
                              "border-radius:8px; padding: 8px; } "
                              "QMenu::item { color: white; padding: 8px 15px;font-size: 10pt; } "
                              "QMenu::item:selected { background-color: rgba(255, 255, 255, 40); }");
    QAction sendImage("Image", this);
    QAction sendFile("File", this);
    contextMenu.addAction(&sendImage);
    contextMenu.addAction(&sendFile);
    // Connect actions to demo handlers
    auto showMessage = [](const QString &msg) {

    };
    connect(&sendImage, &QAction::triggered, this, [=](){
        if(container){
            delete container;
        }
        container = new CurrentSelectedContainer(0,parentWidget());
        connect(container,&CurrentSelectedContainer::becameEmpty,this,[=](){
            container->setParent(nullptr);
            delete container;
            container = nullptr;
            emit sizeChanged();
        });
        QStringList fileNames = QFileDialog::getOpenFileNames(
            this,
            tr("Select Photos"),
            QDir::homePath(),
            tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)")
            );
        for(auto &x : fileNames){
            PhotoComponent *photo = new PhotoComponent(x);
            container->addToContainer(photo);
        }
        if(fileNames.size())
        {
            status = 1;
            ui->recordBtn->setIcon(QIcon(":/icons/Arrow.png"));
            container->setGeometry(geometry().left(),geometry().top()-container->height(),geometry().width(),container->geometry().height());
            container->show();
            emit sizeChanged();
        }else{
            container->becameEmpty();
        }
    });
    connect(&sendFile, &QAction::triggered, this, [=](){
        if(container){
            delete container;
        }
        container = new CurrentSelectedContainer(1,parentWidget());
        connect(container,&CurrentSelectedContainer::becameEmpty,this,[=](){
            container->setParent(nullptr);
            delete container;
            container = nullptr;
        });
        QStringList fileNames = QFileDialog::getOpenFileNames(
            this,
            tr("Select Files"),
            QDir::homePath(),
            tr("All Files (*.*)")
            );
        for(auto &x : fileNames){
            FilesComponent *file = new FilesComponent(x);
            container->addToContainer(file);
        }
        if(fileNames.size())
        {
            status = 1;
            ui->recordBtn->setIcon(QIcon(":/icons/Arrow.png"));
            container->setGeometry(geometry().left(),geometry().top()-container->height(),geometry().width(),container->geometry().height());
            container->show();
            emit sizeChanged();
        }else{
            container->becameEmpty();
        }
    });
    QPoint pos = mapToGlobal(QPoint(ui->attachBtn->geometry().left()+20,ui->attachBtn->geometry().top()-contextMenu.sizeHint().height()));
    contextMenu.exec(pos);
}


void Sending::on_recordBtn_clicked()
{
    if(status){
        if(parentWidget()!=nullptr){
            ChatRoom *chat = dynamic_cast<ChatRoom*>(parentWidget());

            if(container&&container->type==0){
                Message* temp = chat->chat->CurrentReply;
                chat->chat->CurrentReply = nullptr;
                while(container->getContainer()->count()>1){
                    PhotoComponent *comp = dynamic_cast<PhotoComponent*>(container->getContainer()->itemAt(0)->widget());
                    MessageModel msg3(++chat->msgId,User::getCurrentUser()->getId(),MessageModel::IMAGE,MessageModel::SENT,MessageModel::NORMAL,-1,comp->Image->getPath(),Status());
                    comp->deleteRequest(comp);
                    chat->chat->sendMessage(msg3);
                    emit messageSent(msg3);
                }
                chat->chat->CurrentReply = temp;
                PhotoComponent *comp = dynamic_cast<PhotoComponent*>(container->getContainer()->itemAt(0)->widget());
                MessageModel msg3(++chat->msgId,User::getCurrentUser()->getId(),MessageModel::IMAGE,MessageModel::SENT,MessageModel::NORMAL,-1,comp->Image->getPath(),Status(),ui->textEdit->document()->toRawText().toStdString());
                comp->deleteRequest(comp);
                chat->chat->sendMessage(msg3);
                ui->textEdit->clear();
                emit messageSent(msg3);
            }else if(container){
                Message* temp = chat->chat->CurrentReply;
                chat->chat->CurrentReply = nullptr;
                while(container->getContainer()->count()>1){
                    FilesComponent *comp = dynamic_cast<FilesComponent*>(container->getContainer()->itemAt(0)->widget());
                    MessageModel msg3(++chat->msgId,User::getCurrentUser()->getId(),MessageModel::DOCUMENT,MessageModel::SENT,MessageModel::NORMAL,-1,comp->getPath(),Status());
                    comp->deleteRequest(comp);
                    chat->chat->sendMessage(msg3);
                    emit messageSent(msg3);
                }
                chat->chat->CurrentReply = temp;
                FilesComponent *comp = dynamic_cast<FilesComponent*>(container->getContainer()->itemAt(0)->widget());
                MessageModel msg3(++chat->msgId,User::getCurrentUser()->getId(),MessageModel::DOCUMENT,MessageModel::SENT,MessageModel::NORMAL,-1,comp->getPath(),Status());
                comp->deleteRequest(comp);
                chat->chat->sendMessage(msg3);
                emit messageSent(msg3);
            }
            else{
                MessageModel msg5(++chat->msgId,User::getCurrentUser()->getId(),MessageModel::TEXT,MessageModel::SENT,MessageModel::NORMAL,-1,ui->textEdit->document()->toRawText().toStdString(),Status());
                chat->chat->sendMessage(msg5);
                ui->textEdit->clear();
                emit messageSent(msg5);
            }
        }
    }else{
        auto RecordWidget  = new Recording(parentWidget());
        RecordWidget->setGeometry(geometry());
        RecordWidget->show();
    }
}

