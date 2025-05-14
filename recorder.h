#ifndef RECORDER_H
#define RECORDER_H

#include <QWidget>
#include <QMediaCaptureSession>
#include <QMediaRecorder>
#include <QAudioInput>
#include <string>
QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE

class Recorder : public QWidget {
    Q_OBJECT
public:
    explicit Recorder(std::string path,QWidget *parent = nullptr);
    QPushButton *recordButton;
    QMediaRecorder *recorder;
private:
    QMediaCaptureSession captureSession;
    QAudioInput *audioInput;
};

#endif // RECORDER_H
