//
// Created by Dell on 5/18/2025.
//

#ifndef REMOVEFROMGROUP_H
#define REMOVEFROMGROUP_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class RemoveFromGroup; }
QT_END_NAMESPACE

class RemoveFromGroup : public QWidget {
Q_OBJECT

public:
    explicit RemoveFromGroup(QWidget *parent = nullptr);
    ~RemoveFromGroup() override;

private:
    Ui::RemoveFromGroup *ui;
};


#endif //REMOVEFROMGROUP_H
