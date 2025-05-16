#include "recorder.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QUrl>
#include <QCoreApplication>
#include <QDebug>
#include <QMediaFormat>
Recorder::Recorder(std::string FileName,QWidget *parent)
    : QWidget(parent),
    recorder(new QMediaRecorder(this)),
    audioInput(new QAudioInput(this)) {

    QMediaFormat format;
    format.setFileFormat(QMediaFormat::Wave);
    recorder->setMediaFormat(format);

    captureSession.setAudioInput(audioInput);
    captureSession.setRecorder(recorder);

    recorder->setOutputLocation(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/../../Resources/" + FileName.data()));
}
