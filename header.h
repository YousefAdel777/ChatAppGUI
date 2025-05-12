#ifndef HEADER_H
#define HEADER_H

#include <QWidget>

namespace Ui {
class header;
}
class header : public QWidget
{
    Q_OBJECT
public:
    explicit header(QWidget *parent = nullptr);
    ~header();
private slots:
    void on_Name_clicked();
    void on_LastSeen_clicked();
    void on_Dots_clicked();

private:
    Ui::header *ui;
};
#endif // HEADER_H
