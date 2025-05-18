#ifndef HEADERG_H
#define HEADERG_H

#include <QWidget>

namespace Ui {
class HeaderG;
}

class HeaderG : public QWidget
{
    Q_OBJECT

public:
    explicit HeaderG(QWidget *parent = nullptr);
    ~HeaderG();

private:
    Ui::HeaderG *ui;
};

#endif // HEADERG_H
