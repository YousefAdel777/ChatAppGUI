#ifndef FILESCOMPONENT_H
#define FILESCOMPONENT_H

#include <QWidget>

namespace Ui {
class FilesComponent;
}

class FilesComponent : public QWidget
{
    Q_OBJECT

public:
    explicit FilesComponent(QString path,QWidget *parent = nullptr);
    ~FilesComponent();
    std::string getPath();
signals:
    void deleteRequest(QWidget* widget);
private slots:
    void on_Remove_clicked();
private:
    Ui::FilesComponent *ui;
    std::string path;
};

#endif // FILESCOMPONENT_H
