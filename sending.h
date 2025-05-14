#ifndef SENDING_H
#define SENDING_H
#include "recorder.h"
#include "recording.h"
#include <QWidget>
namespace Ui {
class Sending;
}

class Sending : public QWidget
{
    Q_OBJECT

public:
    Recorder *recorder;
    Recording recording;
    explicit Sending(QWidget *parent = nullptr);
    ~Sending();

private slots:
    void updateSize();
    void on_attachBtn_clicked();

    void on_recordBtn_clicked(QWidget *p);

private:
    Ui::Sending *ui;
};

#endif // SENDING_H
