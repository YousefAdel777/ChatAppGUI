#ifndef PHOTOCOMPONENT_H
#define PHOTOCOMPONENT_H

#include <QWidget>
#include <QImageReader>
#include <QPainter>
#include <QPainterPath>
using namespace std;
namespace Ui {
class PhotoComponent;
}

class PhotoComponent : public QWidget
{
    Q_OBJECT

public:
    class HighQualityImage : public QWidget {
    public:
        explicit HighQualityImage(const QString &imagePath, int fixedWidth, QWidget *parent = nullptr)
            : QWidget(parent), fixedWidth(fixedWidth) {
            QImageReader reader(imagePath);
            path = imagePath.toStdString();
            reader.setAutoTransform(true);
            image = reader.read();
            aspectRatio = static_cast<double>(image.width()) / image.height();
            setFixedSize(int(fixedWidth*aspectRatio) ,fixedWidth);
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
    private:
        QImage image;
        int fixedWidth;
        double aspectRatio;
        string path;
    } *Image;
    explicit PhotoComponent(QString path,QWidget *parent = nullptr);
    ~PhotoComponent();
signals:
    void deleteRequest(QWidget* widget);
private slots:
    void on_Remove_clicked();

private:
    Ui::PhotoComponent *ui;
};

#endif // PHOTOCOMPONENT_H
