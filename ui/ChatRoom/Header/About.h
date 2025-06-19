#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include <QResizeEvent>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(int userId, QWidget *parent = nullptr);
    ~Form();
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::Form *ui;
};

#endif // ABOUT_H
