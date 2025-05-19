#ifndef BLOCKEDWIDGET_H
#define BLOCKEDWIDGET_H

#include <QWidget>

namespace Ui {
class BlockedWidget;
}

class BlockedWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BlockedWidget(QWidget *parent = nullptr);
    ~BlockedWidget();

private:
    Ui::BlockedWidget *ui;
};

#endif // BLOCKEDWIDGET_H
