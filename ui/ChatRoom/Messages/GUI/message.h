#ifndef MESSAGE_H
#define MESSAGE_H
#include <QWidget>
#include <QScrollArea>
#include <QMenu>
#include <QAction>
#include <QGuiApplication>
#include <QClipboard>
#include <MessageModel.h>
using namespace std;
class Message : public QWidget {
    Q_OBJECT
public:
    Message(MessageModel content,Message* Reply,QWidget *parent = nullptr);
    Message(Message*Reply,QWidget *parent=nullptr);

    void setContent(MessageModel& content);
    ~Message();
    int pos = 0;
    virtual void Adjust();
    MessageModel Content;
    Message* Reply;
    Message* MessageBubble;
    bool operator<(const Message &message) const;
    bool operator==(const Message& message) const;

protected:
    void mousePressEvent(QMouseEvent *event) override;
signals:
    void MessageDeleted(Message *msg);
    void clicked(Message* msg);
    void showMenu(QPoint point);
    void ReplyRequest(Message *msg);
public slots:
    void showContextMenu(const QPoint &pos) {
        QMenu contextMenu(this);
        contextMenu.setWindowOpacity(0.9);
        contextMenu.setAttribute(Qt::WA_TranslucentBackground);
        contextMenu.setWindowFlags(contextMenu.windowFlags() | Qt::FramelessWindowHint);
        contextMenu.setStyleSheet("QMenu { background-color: rgba(30, 30, 30, 240); "
                                  "border-radius: 10px; padding: 8px; } "
                                  "QMenu::item { color: white; padding: 5px 15px; } "
                                  "QMenu::item:selected { background-color: rgba(255, 255, 255, 40); }");

        QAction replyAction("Reply", this);
        QAction copyAction("Copy", this);
        QAction forwardAction("Forward", this);
        QAction deleteAction("Delete", this);

        contextMenu.addAction(&replyAction);
        contextMenu.addAction(&copyAction);
        contextMenu.addAction(&forwardAction);
        contextMenu.addAction(&deleteAction);

        // Connect demo handlers
        auto showMessage = [](const QString &msg) {

        };
        connect(&copyAction, &QAction::triggered, this, [=]() {
            if(this->Content.datatype==MessageModel::TEXT){
                QClipboard *clipboard = QGuiApplication::clipboard();
                clipboard->setText(Content.getContent().data());
            }
        });
        connect(&replyAction, &QAction::triggered, this, [=]() { emit ReplyRequest(this); });
        connect(&forwardAction, &QAction::triggered, this, [=]() { showMessage("Forward clicked"); });
        connect(&deleteAction, &QAction::triggered, this, [=]() { emit MessageDeleted(this); });

        contextMenu.exec(mapToGlobal(pos));
    }
};

#endif
