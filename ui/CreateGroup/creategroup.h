//
// Created by Dell on 5/18/2025.
//

#ifndef CREATEGROUP_H
#define CREATEGROUP_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class CreateGroup; }
QT_END_NAMESPACE

class CreateGroup : public QWidget {
Q_OBJECT

public slots:
    void on_create();
    void removeImage();
    void uploadImage();

public:
    explicit CreateGroup(QWidget *parent = nullptr);
    ~CreateGroup() override;

private:
    Ui::CreateGroup *ui;
    std::string imagePath;
    void setImage(std::string path);
};


#endif //CREATEGROUP_H
