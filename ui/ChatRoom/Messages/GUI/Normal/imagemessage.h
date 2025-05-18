#ifndef IMAGEMESSAGE_H
#define IMAGEMESSAGE_H

#include <QWidget>
#include <QResizeEvent>
#include <QPixmap>
#include <QLabel>
#include <QImageReader>
#include "textmessage.h"
#include "MessageModel.h"
#include <QPainter>
#include <QPainterPath>
#include "message.h"
namespace Ui {
class ImageMessage;
}

class ImageMessage : public Message
{
public:
    class HighQualityImage : public QWidget {
    public:
        explicit HighQualityImage(const QString &imagePath, int fixedWidth, QWidget *parent = nullptr)
            : QWidget(parent), fixedWidth(fixedWidth) {
            QImageReader reader(imagePath);
            path = imagePath.toStdString();
            reader.setAutoTransform(true);
            image = reader.read();
            aspectRatio = static_cast<double>(image.height()) / image.width();
            originalSize = image.width();
            setFixedSize(fixedWidth, int(fixedWidth*aspectRatio));
        }
        void Adjust(){
            setFixedWidth(min(originalSize,width()));
            setFixedHeight(int(width() * aspectRatio));
        }
        string getPath(){
            return path;
        }
    protected:
        void paintEvent(QPaintEvent *event) override {
            Q_UNUSED(event);
            QPainter painter(this);
            painter.setRenderHint(QPainter::Antialiasing);
            QPainterPath path;
            path.addRoundedRect(rect(), 16, 16);
            painter.setClipPath(path);

            painter.setRenderHint(QPainter::SmoothPixmapTransform);
            painter.drawImage(rect(), image);  // scaled automatically inside rect
        }

        void resizeEvent(QResizeEvent *event) override {
            QWidget::resizeEvent(event);
            Adjust();
        }

    private:
        QImage image;
        int fixedWidth;
        int originalSize;
        double aspectRatio;
        string path;
    } *Image;

    explicit ImageMessage(MessageModel msg,Message* Reply=nullptr,QWidget *parent=nullptr);
    ~ImageMessage();
    void resizeEvent(QResizeEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    void Adjust() override;
    QWidget *ReadStatusContainer;
    TextMessage *label;
    QPixmap *photo;
    QWidget *widget;
    QWidget *bubble;
    QLabel *ReadStatus;
};

#endif // IMAGEMESSAGE_H
