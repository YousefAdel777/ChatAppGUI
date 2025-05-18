#ifndef SENDING_H
#define SENDING_H
#include "recorder.h"
#include "recording.h"
#include <currentselectedcontainer.h>
#include <photocomponent.h>
#include <filescomponent.h>
#include <QWidget>
namespace Ui {
class Sending;
}

class Sending : public QWidget
{
    Q_OBJECT

public:
    explicit Sending(QWidget *parent = nullptr);
    ~Sending();
    QVBoxLayout* getContainer();
    CurrentSelectedContainer *container;
private slots:
    void updateSize();
    void on_attachBtn_clicked();

    void on_recordBtn_clicked();
signals:
    void sizeChanged();
private:
    bool status = 0;
    Ui::Sending *ui;
};

#endif // SENDING_H
