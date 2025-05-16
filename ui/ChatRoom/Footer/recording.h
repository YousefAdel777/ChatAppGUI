#ifndef RECORDING_H
#define RECORDING_H

#include <QWidget>
#include <QElapsedTimer>
#include "recorder.h"
namespace Ui {
class Recording;
}

class Recording : public QWidget
{
    Q_OBJECT

public:
    inline static int Id_Generator = 0;
    explicit Recording(QWidget *parent = nullptr);
    ~Recording();
    QTimer* timer;
    QElapsedTimer elapsedTimer;
    QIcon micIcon,pauseIcon;
    qint64 accmulatedSum;
    Recorder *recorder;
    bool del;
public slots:
    void updateTimer();
private slots:
    void on_pauseBtn_clicked();
    void finishRecording();
    void on_deleteBtn_clicked();

private:
    Ui::Recording *ui;
};

#endif // RECORDING_H
