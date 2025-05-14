#include "sending.h"
#include "ui_sending.h"
#include <iostream>
#include<QFileDialog>
#include<QMenu>
#include "recorder.h"
#include "recording.h"
Sending::Sending(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Sending)
{
    ui->setupUi(this);
    recorder = new Recorder("t.wav");
    connect(ui->textEdit,&QTextEdit::textChanged,this,&Sending::updateSize);
}
void Sending::updateSize(){
    const int mn= 46,mx=100;
    QTextDocument* doc = ui->textEdit->document();
    int docHeight = doc->size().height();
    std::cout << doc->size().height() << std::endl;
    int extra = ui->textEdit->frameWidth() * 2 + 4;
    int requiredHeight = std::ceil(docHeight) + extra;
    if (requiredHeight < mn) {
        ui->textEdit->setFixedHeight(mn);
    } else {
        ui->textEdit->setFixedHeight(std::min(requiredHeight,mx));
    }
    setFixedHeight(ui->textEdit->height()+22);
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
                              "border-radius: 10px; padding: 8px; } "
                              "QMenu::item { color: white; padding: 8px 15px;font-size: 14pt; } "
                              "QMenu::item:selected { background-color: rgba(255, 255, 255, 40); }");
    QAction sendImage("Image", this);
    QAction sendFile("File", this);
    contextMenu.addAction(&sendImage);
    contextMenu.addAction(&sendFile);
    // Connect actions to demo handlers
    auto showMessage = [](const QString &msg) {

    };
    connect(&sendImage, &QAction::triggered, this, [=](){
        QStringList fileNames = QFileDialog::getOpenFileNames(
            this,
            tr("Select Photos"),
            QDir::homePath(),
            tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)")
            );
    });
    connect(&sendFile, &QAction::triggered, this, [=](){
        QStringList fileNames = QFileDialog::getOpenFileNames(
            this,
            tr("Select Files"),
            QDir::homePath(),
            tr("All Files (*.*)")
            );
    });
    QPoint pos = QPoint(geometry().left(),geometry().top()-sizeHint().height());
    contextMenu.exec(pos);
}


void Sending::on_recordBtn_clicked(QWidget *p)
{
}

