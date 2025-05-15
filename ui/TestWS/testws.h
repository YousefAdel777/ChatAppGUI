#ifndef TESTWS_H
#define TESTWS_H

#include <QMainWindow>
#include "ws/WebSocketServer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TestWs; }
QT_END_NAMESPACE

class TestWs : public QWidget {
    Q_OBJECT

public:
    TestWs(QWidget *parent = nullptr);
    ~TestWs();

    private slots:
        void onSendButtonClicked();
    void displayMessage(const QString &chatId, const QString &message);

private:
    Ui::TestWs *ui;
    WebSocketServer *server;
};

#endif // TESTWS_H
