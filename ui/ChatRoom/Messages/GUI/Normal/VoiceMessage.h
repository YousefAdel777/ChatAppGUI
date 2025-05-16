#ifndef VOICEMESSAGE_H
#define VOICEMESSAGE_H
#include <QWidget>
#include <QPushButton>
#include <QAudioOutput>
#include <QHBoxLayout>
#include <QLabel>
#include <QMediaPlayer>
#include <QResizeEvent>
#include <QFileDialog>
#include <QTimer>
#include <QObject>
#include <QPaintEvent>
#include "WaveformSlilder.h"
#include "message.h"
class VoiceMessage : public Message {
    Q_OBJECT
public:
    VoiceMessage(MessageModel msg,Message* Reply=nullptr,QWidget *parent=nullptr);
    QWidget *ReadStatusContainer;
    void Adjust() override;
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *) override;
    QMediaPlayer *player ;
    QLabel *ReadStatus;
    QWidget *MessageBubble;
    QAudioOutput *output;
    WaveformSlider *waveform;
    QLabel *timeLabel;
    QPushButton *playBtn;
signals:
    void voiceStartRequest(VoiceMessage *msg);
};

#endif // VOICEMESSAGEWIDGET_H
