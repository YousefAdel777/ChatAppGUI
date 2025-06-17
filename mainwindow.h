#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ChatWidget.h"
#include "StatusWindow/StatusWindow.h"
#include "Settings/settings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ChatWidget *Mainwidget;
    StatusWindow *Status;
    Settings * settings;
};
#endif // MAINWINDOW_H
