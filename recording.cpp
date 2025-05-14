#include "recording.h"
#include "ui_recording.h"
#include <QTimer>
#include <QTime>
#include<QShortcut>
#include<QFile>
Recording::Recording(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Recording)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    setFocusPolicy(Qt::StrongFocus);
    elapsedTimer.start();
    timer->start(100);
    accmulatedSum = 0;
    ui->Timer->setText("00:00:00");
    connect(timer, &QTimer::timeout, this, &Recording::updateTimer);
    recorder = new Recorder("t.wav");
    pauseIcon = QIcon("C:/Users/ELKAYAN/OneDrive/Documents/ChatAppGUI/icons/Arrow.png");
    ui->pauseBtn->setIcon(pauseIcon);
    recorder->recorder->record();
    del=0;
    auto* returnSc = new QShortcut(QKeySequence(Qt::Key_Return), this);
    connect(returnSc, &QShortcut::activated, this, &Recording::finishRecording);
    connect(recorder->recorder,&QMediaRecorder::recorderStateChanged,this,[=](){
        if(del){
            QFile::remove("C:/Users/ELKAYAN/OneDrive/Documents/ChatAppGUI/reso/t.wav");
            close();
        }
    });
}
void Recording::updateTimer() {
    qint64 totalSecs = (accmulatedSum+elapsedTimer.elapsed()) / 1000;
    int hours   = static_cast<int>(totalSecs / 3600);
    int minutes = static_cast<int>((totalSecs % 3600) / 60);
    int seconds = static_cast<int>(totalSecs % 60);
    QString text = QString("%1:%2:%3")
                       .arg(hours,   2, 10, QChar('0'))
                       .arg(minutes, 2, 10, QChar('0'))
                       .arg(seconds, 2, 10, QChar('0'));

    ui->Timer->setText(text);
}
Recording::~Recording()
{
    delete ui;
}

void Recording::on_pauseBtn_clicked()
{
    finishRecording();
}

void Recording::finishRecording()
{
    if (recorder->recorder->recorderState() != QMediaRecorder::PausedState){
        recorder->recorder->record();
    }
    if (recorder->recorder->recorderState() != QMediaRecorder::StoppedState) {
        recorder->recorder->stop();
    }
    timer->stop();
    close();
}
void Recording::on_deleteBtn_clicked()
{
    if (recorder->recorder->recorderState() != QMediaRecorder::StoppedState) {
        recorder->recorder->stop();
    }
    del = 1;
}

