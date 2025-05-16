#ifndef REPLYIMAGEMESSAGE_H
#define REPLYIMAGEMESSAGE_H
#include <QWidget>
#include <QImageReader>
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QResizeEvent>
#include "message.h"
#include "imagemessage.h"

namespace Ui {
class ReplyImageMessage;
}

class ReplyImageMessage : public Message
{
    Q_OBJECT

public:
    class HighQualityImage : public QWidget {
    public:
        explicit HighQualityImage(const QString &imagePath, int fixedWidth, QWidget *parent = nullptr)
            : QWidget(parent), fixedWidth(fixedWidth) {
            QImageReader reader(imagePath);
            reader.setAutoTransform(true);
            image = reader.read();
            setStyleSheet("background-color:transparent; border:0;");
            aspectRatio = static_cast<double>(image.height()) / image.width();
            setFixedSize(80,50);
        }
        void Adjust(){
            //setFixedHeight(int(width() * aspectRatio));
        }
    protected:
        void paintEvent(QPaintEvent *event) override {
            Q_UNUSED(event);
            QPainter painter(this);
            painter.setRenderHint(QPainter::Antialiasing);
            QPainterPath path;
            path.addRoundedRect(rect(), 10,10);
            painter.setClipPath(path);

            painter.setRenderHint(QPainter::SmoothPixmapTransform);
            painter.drawImage(rect(), image);
        }

        void resizeEvent(QResizeEvent *event) override {
            QWidget::resizeEvent(event);
            Adjust();
        }

    private:
        QImage image;
        int fixedWidth;
        double aspectRatio;
    } *image;
    ReplyImageMessage(ImageMessage* msg,QWidget *parent = nullptr);
    ~ReplyImageMessage();
    void resizeEvent(QResizeEvent *event) override;
    void Adjust() override;
private:
    Ui::ReplyImageMessage *ui;
    int RefId;
    int MinWidth;
    int MinHeight;
};

#endif // REPLYIMAGEMESSAGE_H
