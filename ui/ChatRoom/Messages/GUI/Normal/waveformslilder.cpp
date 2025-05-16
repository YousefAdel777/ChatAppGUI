#include "waveformslilder.h"
#include <QPainter>
#include <QMouseEvent>
#include <iostream>

WaveformSlider::WaveformSlider(QWidget *parent) : QWidget(parent) {
    setMouseTracking(true);
}

void WaveformSlider::setAmplitudes(const vector<float> &amps) {
    amplitudes = amps;
    update();
}


void WaveformSlider::setSegments(const vector<float> seg) {
    this->seg = seg;
    setAmplitudes(seg);
}

void WaveformSlider::setPlayer(QMediaPlayer *p) {
    player = p;
    connect(player, &QMediaPlayer::positionChanged, this, [=]() { update(); });
}

void WaveformSlider::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if (amplitudes.empty() || !player) return;
    int w = width(), h = height();
    float scaleX = float(w) / (amplitudes.size());
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    float ratio = float(player->position()) / player->duration();
    int x = int(ratio * w);
    int y =x/scaleX;
    for (int i = 0; i < amplitudes.size(); ++i) {
        float a = amplitudes[i];
        int a1 = a*(62);
        auto v = QRect(int(i * (scaleX)), (h-a1)/2,scaleX - 2,a1);
        if(y<i){
            painter.setBrush(Qt::gray);
            painter.setPen(Qt::gray);
        }
        painter.drawRoundedRect(v,scaleX*0.25,scaleX*0.25);
    }
    painter.setPen(QColor(0, 150, 255));
    painter.setBrush(QColor(0, 150, 255));
    auto v = QRect(std::min(x,w-12), (h-12)/2,12,12);
    painter.drawRoundedRect(v,6,6);
    painter.setBrush(Qt::transparent);
}

void WaveformSlider::mousePressEvent(QMouseEvent *event) {
    if (!player) return;
    float ratio = float(event->pos().x()) / width();
    player->setPosition(ratio * player->duration());
}

void WaveformSlider::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton)
        mousePressEvent(event);
}


void WaveformSlider::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    std::vector<float> result;
    int segmentsCount = width()/4;
    if(!segmentsCount)
        return ;
    int chunkSize = seg.size() / segmentsCount;
    int remainder = seg.size() % segmentsCount;
    size_t index = 0;
    float x = 0;
    for (int i = 0; i < segmentsCount; ++i) {
        int currentChunkSize = chunkSize + (remainder-- > 0 ? 1 : 0);
        float sum = 0;
        for (int j = 0; j < currentChunkSize && index < seg.size(); ++j)
            sum += seg[index++];
        sum/=currentChunkSize;
        x = std::max(sum,x);
        result.push_back(sum);
    }
    float factor =0;
    if(x)
        factor = min(0.5/x,100.0);
    for(auto &y : result){
        y*=factor;
    }
    setAmplitudes(result);
}
