#ifndef STATUSWINDOW_H
#define STATUSWINDOW_H

#include <QLabel>
#include <QCursor>
#include <QWidget>
#include <QDialog>
#include <QListView>
#include <QMainWindow>
#include <QToolButton>
#include <QScrollArea>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsOpacityEffect>


#include "User.h"
#include "Story.h"
#include "../AddStoryPage/AddStoryPage.h"
#include "UserProfileDescription.h"

QT_BEGIN_NAMESPACE

namespace Ui {
    class StoriesWindow;
}

QT_END_NAMESPACE

class StatusWindow : public QMainWindow {
    Q_OBJECT

public:
    StatusWindow(User& user, QWidget *parent = nullptr);

    ~StatusWindow();

private slots:

    void initializeStoriesPage(User &user);

    void showUserStories(const set<Story>& stories);

    void clearStories(QWidget *parent);

    void on_previousStoryButton_clicked();

    void displayCurrentStory();

    void on_nextStoryButton_clicked();

    void updateButtonSelection(int index);

    void loadPage();

    void setUpButton(QPushButton* button, set<Story>& currStories , int contactIndex, bool flag);

    void on_addStoryButton_clicked();

    void on_closeButton_clicked();
signals:
    void backClicked();
private:
    QListView recentStories;
    Ui::StoriesWindow *ui;
    QVector<pair<pair<QString, QString>, QString>> userStories;
    int currentStoryIndex = 0;
    int selectedUser = -1;
    QVector<QPushButton*> contactButtons;  // Track all buttons
    const QString defaultStyle =
        "QPushButton {"
            "background-color: rgb(251, 253, 246);"
            "font: 500 18pt 'Product Sans Medium';"
            "border: none;"
            "border-radius: 30px;"
            "text-align: left;"
            "padding-left: 80px;"
            "padding-bottom: 20px;"
            "color: #000;"
        "}";

    const QString selectedStyle =
        "QPushButton {"
            "background-color: #FFF;"
            "font: 500 18pt 'Product Sans Medium';"
            "border: none;"
            "border-radius: 30px;"
            "text-align: left;"
            "padding-left: 80px;"
            "padding-bottom: 20px;"
            "color: #000;"
        "}";

    const QString defaultMyStoriesStyle =
        "QPushButton {"
            "background-color: #E7F1E6;"
            "border: none;"
            "border-radius: 30px;"
            "text-align: left;"
            "padding-left: 80px;"
            "padding-bottom: 20px;"
            "color: #000"
        "}";

    QGraphicsOpacityEffect* previousOpacity;
    QGraphicsOpacityEffect* nextOpacity;

    void setButtonOpacity(QPushButton* button, QGraphicsOpacityEffect*& effect, qreal opacity);
    void makeUnclickable(QPushButton* button, QGraphicsOpacityEffect*& effect);
    void makeClickable(QPushButton* button, QGraphicsOpacityEffect*& effect);
    void initializeUserImage(string imagePath, QLabel *uiImage);
};
#endif // STATUSWINDOW_H
