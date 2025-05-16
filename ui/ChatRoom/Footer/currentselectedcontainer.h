#ifndef CURRENTSELECTEDCONTAINER_H
#define CURRENTSELECTEDCONTAINER_H

#include <QWidget>
#include <QHBoxLayout>
#include <PhotoComponent.h>
#include <filescomponent.h>
namespace Ui {
class CurrentSelectedContainer;
}

class CurrentSelectedContainer : public QWidget
{
    Q_OBJECT

public:
    explicit CurrentSelectedContainer(bool type = 0,QWidget *parent = nullptr);
    void addToContainer(PhotoComponent *widget);
    void addToContainer(FilesComponent *widget);
    ~CurrentSelectedContainer();
    bool type;
    QHBoxLayout* getContainer();
signals:
    void becameEmpty();
private:
    Ui::CurrentSelectedContainer *ui;
};

#endif // CURRENTSELECTEDCONTAINER_H
