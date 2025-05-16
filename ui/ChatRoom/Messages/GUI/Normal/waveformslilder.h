#pragma once
#include <QWidget>
#include <QVector>
#include <QMediaPlayer>
#include <vector>
using namespace std;
class WaveformSlider : public QWidget {
    Q_OBJECT
public:
    explicit WaveformSlider(QWidget *parent = nullptr);
    void setAmplitudes(const vector<float> &amps);
    void setPlayer(QMediaPlayer *player);
    void setSegments(const vector<float>seg);
protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void resizeEvent(QResizeEvent *event) override;
private:
    vector<float> amplitudes,seg;
    QMediaPlayer *player = nullptr;
};
