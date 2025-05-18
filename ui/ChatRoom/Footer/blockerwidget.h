#ifndef BLOCKERWIDGET_H
#define BLOCKERWIDGET_H

#include <QWidget>

namespace Ui {
class BlockerWidget;
}

class BlockerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BlockerWidget(QWidget *parent = nullptr);
    ~BlockerWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BlockerWidget *ui;
};

#endif // BLOCKERWIDGET_H
