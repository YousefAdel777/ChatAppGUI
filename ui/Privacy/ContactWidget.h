#ifndef ContactWidget_H
#define ContactWidget_H

#include <QWidget>
#include <QPropertyAnimation>

namespace Ui {
class ContactWidget;
}

class ContactWidget : public QWidget
{
    Q_OBJECT
    long long id;

public:
    explicit ContactWidget(QWidget *parent = nullptr);
    ~ContactWidget();

    void setName(const QString &Name);
    void setIcon(const QPixmap &Icon);
    void setId(long long id);
    long long getId();
    bool CheckBoxIsChecked();
    void CheckCheckBox();
    void UnCheckCheckBox();

private:
    Ui::ContactWidget *ui;
};

#endif // ContactWidget_H
