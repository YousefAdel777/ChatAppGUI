#include "testws.h"

#include <QPushButton>

#include "ui_testws.h"

TestWs::TestWs(QWidget *parent)
    : QWidget(parent), ui(new Ui::TestWs), server(new WebSocketServer(this))
{
    ui->setupUi(this);
    connect(ui->sendButton, &QPushButton::clicked, this, &TestWs::onSendButtonClicked);
    connect(server, &WebSocketServer::messageReceived, this, &TestWs::displayMessage);

    server->startServer(8000);
}

TestWs::~TestWs() {
    delete ui;
}

void TestWs::onSendButtonClicked() {
    QString chatId = ui->chatIdEdit->text().trimmed();
    QString message = ui->messageEdit->text().trimmed();
    if (!chatId.isEmpty() && !message.isEmpty()) {
        server->sendMessageToChat(chatId, "Server: " + message);
    }
}

void TestWs::displayMessage(const QString &chatId, const QString &message) {
    ui->chatBox->append("[" + chatId + "] " + message);
}
