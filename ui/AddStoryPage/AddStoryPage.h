#ifndef ADDSTORYPAGE_H
#define ADDSTORYPAGE_H

#include <QDialog>
#include <QToolButton>
#include <QGraphicsOpacityEffect>
#include <QRegularExpression>
#include <QWidget>
#include <QFileDialog>

#include "User.h"
// Forward declaration - must match exactly what Qt generates
namespace Ui {
class AddStoryPage;
}

class AddStoryPage : public QDialog
{
    Q_OBJECT

public:
    explicit AddStoryPage(QWidget *parent = nullptr, const User& user = {});
    ~AddStoryPage();
private slots:
    void on_textChoice_clicked();
    void on_closeButton_clicked();
    void on_closeMedia_clicked();
    void on_paletteButton_clicked();
    void on_doneButton_clicked();
    void on_publishButton_clicked();
    void on_publishMedia_clicked();
    void on_mediaChoice_clicked();
    void on_selectAnotherMedia_clicked();
private:
    // Pointer must match the forward-declared namespace
    QString mediaPath;
    Ui::AddStoryPage *ui;
    const QString red = "background-color: #FB7A7A;";
    const QString green = "background-color: #6AF273;";
    const QString blue = "background-color: #44E2F4;";
    const QString yellow = "background-color: #EEE369;";
    User user;
    void initializeAddStoryPage();
    void initializeTextPage();
    void initializeMediaPage(const QString& mediaPath);
    void setOpacityFor(QWidget* button);
    void setSelectedColor(int colorIndex);
    void unselectAllButtons();
    void selectButton(int colorIndex);
    void selectMedia();
};

#endif // ADDSTORYPAGE_H
