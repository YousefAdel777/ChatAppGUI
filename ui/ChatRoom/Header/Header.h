#ifndef HEADER_H
#define HEADER_H

#include <QWidget>
#include <QPushButton>
namespace Ui {
class header;
}
class Header : public QWidget
{
    Q_OBJECT
public:
    explicit Header(QWidget *parent = nullptr);
    ~Header();
    QPushButton* getName();

private slots:
    void on_Name_clicked();
    void on_LastSeen_clicked();
    void on_Dots_clicked();
    void on_add_contact_clicked();
private:
    Ui::header *ui;
};
#endif // HEADER_H
