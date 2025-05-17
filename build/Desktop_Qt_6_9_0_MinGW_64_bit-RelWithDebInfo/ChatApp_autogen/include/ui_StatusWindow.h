/********************************************************************************
** Form generated from reading UI file 'StatusWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSWINDOW_H
#define UI_STATUSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StoriesWindow
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *addStoryButton;
    QPushButton *closeButton;
    QPushButton *myStoriesButton;
    QLabel *recentStoriesLabel;
    QWidget *stories;
    QVBoxLayout *verticalLayout_6;
    QPushButton *friendStory_3;
    QPushButton *friendStory_4;
    QPushButton *friendStory_6;
    QPushButton *friendStory_7;
    QPushButton *friendStory_8;
    QLabel *noStoryLabel;
    QLabel *noStoryText;
    QWidget *storyContentBox;
    QVBoxLayout *verticalLayout_2;
    QWidget *storyTimeBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_2;
    QWidget *storyHBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *previousStoryButton;
    QWidget *widget_2;
    QLabel *storyScreen;
    QWidget *expandinglabel;
    QVBoxLayout *verticalLayout_3;
    QLabel *mediaCaption;
    QPushButton *nextStoryButton;

    void setupUi(QMainWindow *StoriesWindow)
    {
        if (StoriesWindow->objectName().isEmpty())
            StoriesWindow->setObjectName("StoriesWindow");
        StoriesWindow->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StoriesWindow->sizePolicy().hasHeightForWidth());
        StoriesWindow->setSizePolicy(sizePolicy);
        StoriesWindow->setMinimumSize(QSize(0, 720));
        StoriesWindow->setMaximumSize(QSize(16777215, 720));
        StoriesWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(StoriesWindow);
        centralwidget->setObjectName("centralwidget");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(-10, 0, 455, 720));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(0, 720));
        scrollArea->setMaximumSize(QSize(16777215, 720));
        scrollArea->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: rgb(251, 253, 246);\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #f0f0f0;\n"
"    width: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #888;\n"
"    min-height: 20px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 438, 703));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;\n"
""));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(17, -1, -1, -1);
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy3);
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font.setPointSize(24);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #000;\n"
"padding-left: 5px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label->setMargin(0);

        horizontalLayout_2->addWidget(label);

        addStoryButton = new QPushButton(widget);
        addStoryButton->setObjectName("addStoryButton");
        sizePolicy2.setHeightForWidth(addStoryButton->sizePolicy().hasHeightForWidth());
        addStoryButton->setSizePolicy(sizePolicy2);
        addStoryButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addStoryButton->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;\n"
"image: url(:/icons/plus.png);"));

        horizontalLayout_2->addWidget(addStoryButton);

        closeButton = new QPushButton(widget);
        closeButton->setObjectName("closeButton");
        sizePolicy2.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy2);
        closeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        closeButton->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;\n"
"image: url(:/icons/close.png);\n"
""));

        horizontalLayout_2->addWidget(closeButton);


        verticalLayout->addWidget(widget);

        myStoriesButton = new QPushButton(scrollAreaWidgetContents);
        myStoriesButton->setObjectName("myStoriesButton");
        sizePolicy3.setHeightForWidth(myStoriesButton->sizePolicy().hasHeightForWidth());
        myStoriesButton->setSizePolicy(sizePolicy3);
        myStoriesButton->setMinimumSize(QSize(411, 91));
        myStoriesButton->setMaximumSize(QSize(411, 91));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font1.setPointSize(18);
        font1.setWeight(QFont::Medium);
        font1.setItalic(false);
        myStoriesButton->setFont(font1);
        myStoriesButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        myStoriesButton->setStyleSheet(QString::fromUtf8("background-color: #E7F1E6;\n"
"border: none;\n"
"border-radius: 30px;\n"
"text-align: left;\n"
"padding-left: 80px;\n"
"padding-bottom: 20px;\n"
"color: #000\n"
""));

        verticalLayout->addWidget(myStoriesButton);

        recentStoriesLabel = new QLabel(scrollAreaWidgetContents);
        recentStoriesLabel->setObjectName("recentStoriesLabel");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(recentStoriesLabel->sizePolicy().hasHeightForWidth());
        recentStoriesLabel->setSizePolicy(sizePolicy4);
        recentStoriesLabel->setMinimumSize(QSize(136, 32));
        recentStoriesLabel->setMaximumSize(QSize(121, 32));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font2.setPointSize(14);
        recentStoriesLabel->setFont(font2);
        recentStoriesLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(251, 253, 246);\n"
"color: rgb(66, 73, 65);\n"
"padding-left: 5px;"));

        verticalLayout->addWidget(recentStoriesLabel);

        stories = new QWidget(scrollAreaWidgetContents);
        stories->setObjectName("stories");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(stories->sizePolicy().hasHeightForWidth());
        stories->setSizePolicy(sizePolicy5);
        stories->setMaximumSize(QSize(412, 16777215));
        verticalLayout_6 = new QVBoxLayout(stories);
        verticalLayout_6->setSpacing(16);
        verticalLayout_6->setObjectName("verticalLayout_6");
        friendStory_3 = new QPushButton(stories);
        friendStory_3->setObjectName("friendStory_3");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(friendStory_3->sizePolicy().hasHeightForWidth());
        friendStory_3->setSizePolicy(sizePolicy6);
        friendStory_3->setMinimumSize(QSize(401, 81));
        friendStory_3->setMaximumSize(QSize(401, 81));
        friendStory_3->setFont(font1);
        friendStory_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        friendStory_3->setStyleSheet(QString::fromUtf8("background-color: #FFF;\n"
"font: 500 18pt \"Product Sans Medium\";\n"
"border: none;\n"
"border-radius: 30px;\n"
"text-align: left;\n"
"padding-left: 80px;\n"
"padding-bottom: 20px;\n"
"color: #000;\n"
""));
        friendStory_3->setIconSize(QSize(90, 90));

        verticalLayout_6->addWidget(friendStory_3);

        friendStory_4 = new QPushButton(stories);
        friendStory_4->setObjectName("friendStory_4");
        sizePolicy6.setHeightForWidth(friendStory_4->sizePolicy().hasHeightForWidth());
        friendStory_4->setSizePolicy(sizePolicy6);
        friendStory_4->setMinimumSize(QSize(401, 81));
        friendStory_4->setMaximumSize(QSize(401, 81));
        friendStory_4->setFont(font1);
        friendStory_4->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        friendStory_4->setStyleSheet(QString::fromUtf8("background-color: rgb(251, 253, 246);\n"
"border: none;\n"
"border-radius: 30px;\n"
"text-align: left;\n"
"padding-left: 80px;\n"
"padding-bottom: 20px;\n"
"color: #000;\n"
""));

        verticalLayout_6->addWidget(friendStory_4);

        friendStory_6 = new QPushButton(stories);
        friendStory_6->setObjectName("friendStory_6");
        sizePolicy6.setHeightForWidth(friendStory_6->sizePolicy().hasHeightForWidth());
        friendStory_6->setSizePolicy(sizePolicy6);
        friendStory_6->setMinimumSize(QSize(401, 81));
        friendStory_6->setMaximumSize(QSize(401, 81));
        friendStory_6->setFont(font1);
        friendStory_6->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        friendStory_6->setStyleSheet(QString::fromUtf8("background-color: rgb(251, 253, 246);\n"
"border: none;\n"
"border-radius: 30px;\n"
"text-align: left;\n"
"padding-left: 80px;\n"
"padding-bottom: 20px;\n"
"color: #000;\n"
""));

        verticalLayout_6->addWidget(friendStory_6);

        friendStory_7 = new QPushButton(stories);
        friendStory_7->setObjectName("friendStory_7");
        sizePolicy6.setHeightForWidth(friendStory_7->sizePolicy().hasHeightForWidth());
        friendStory_7->setSizePolicy(sizePolicy6);
        friendStory_7->setMinimumSize(QSize(401, 81));
        friendStory_7->setMaximumSize(QSize(401, 81));
        friendStory_7->setFont(font1);
        friendStory_7->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        friendStory_7->setStyleSheet(QString::fromUtf8("background-color: rgb(251, 253, 246);\n"
"border: none;\n"
"border-radius: 30px;\n"
"text-align: left;\n"
"padding-left: 80px;\n"
"padding-bottom: 20px;\n"
"color: #000;\n"
""));

        verticalLayout_6->addWidget(friendStory_7);

        friendStory_8 = new QPushButton(stories);
        friendStory_8->setObjectName("friendStory_8");
        sizePolicy6.setHeightForWidth(friendStory_8->sizePolicy().hasHeightForWidth());
        friendStory_8->setSizePolicy(sizePolicy6);
        friendStory_8->setMinimumSize(QSize(401, 81));
        friendStory_8->setMaximumSize(QSize(401, 81));
        friendStory_8->setFont(font1);
        friendStory_8->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        friendStory_8->setStyleSheet(QString::fromUtf8("background-color: rgb(251, 253, 246);\n"
"border: none;\n"
"border-radius: 30px;\n"
"text-align: left;\n"
"padding-left: 80px;\n"
"padding-bottom: 20px;\n"
"color: #000;\n"
""));

        verticalLayout_6->addWidget(friendStory_8);


        verticalLayout->addWidget(stories);

        scrollArea->setWidget(scrollAreaWidgetContents);
        noStoryLabel = new QLabel(centralwidget);
        noStoryLabel->setObjectName("noStoryLabel");
        noStoryLabel->setGeometry(QRect(885, 320, 91, 91));
        noStoryLabel->setStyleSheet(QString::fromUtf8("image: url(:/icons/unhappy.png);"));
        noStoryText = new QLabel(centralwidget);
        noStoryText->setObjectName("noStoryText");
        noStoryText->setGeometry(QRect(836, 403, 201, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font3.setPointSize(20);
        noStoryText->setFont(font3);
        noStoryText->setStyleSheet(QString::fromUtf8("color: rgb(163, 163, 163);"));
        storyContentBox = new QWidget(centralwidget);
        storyContentBox->setObjectName("storyContentBox");
        storyContentBox->setGeometry(QRect(640, 0, 570, 726));
        sizePolicy6.setHeightForWidth(storyContentBox->sizePolicy().hasHeightForWidth());
        storyContentBox->setSizePolicy(sizePolicy6);
        storyContentBox->setMaximumSize(QSize(16777215, 16777196));
        verticalLayout_2 = new QVBoxLayout(storyContentBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        storyTimeBox = new QWidget(storyContentBox);
        storyTimeBox->setObjectName("storyTimeBox");
        sizePolicy2.setHeightForWidth(storyTimeBox->sizePolicy().hasHeightForWidth());
        storyTimeBox->setSizePolicy(sizePolicy2);
        storyTimeBox->setMinimumSize(QSize(552, 20));
        storyTimeBox->setMaximumSize(QSize(552, 26));
        storyTimeBox->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(storyTimeBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(10, 10, 10, 10);
        label_3 = new QLabel(storyTimeBox);
        label_3->setObjectName("label_3");
        sizePolicy6.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy6);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(174, 209, 172);"));

        horizontalLayout_3->addWidget(label_3);

        label_2 = new QLabel(storyTimeBox);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy7);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 232, 210);\n"
"border-radius: 50%;  "));

        horizontalLayout_3->addWidget(label_2);


        verticalLayout_2->addWidget(storyTimeBox);

        storyHBox = new QWidget(storyContentBox);
        storyHBox->setObjectName("storyHBox");
        QSizePolicy sizePolicy8(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(storyHBox->sizePolicy().hasHeightForWidth());
        storyHBox->setSizePolicy(sizePolicy8);
        storyHBox->setMinimumSize(QSize(552, 641));
        storyHBox->setMaximumSize(QSize(552, 726));
        storyHBox->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;"));
        horizontalLayout = new QHBoxLayout(storyHBox);
        horizontalLayout->setObjectName("horizontalLayout");
        previousStoryButton = new QPushButton(storyHBox);
        previousStoryButton->setObjectName("previousStoryButton");
        previousStoryButton->setMinimumSize(QSize(45, 45));
        previousStoryButton->setMaximumSize(QSize(45, 45));
        previousStoryButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        previousStoryButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/previousButton.png);\n"
"background-color: transparent;\n"
"border: none;\n"
"color: rgba(255, 255, 255, 128);"));

        horizontalLayout->addWidget(previousStoryButton);

        widget_2 = new QWidget(storyHBox);
        widget_2->setObjectName("widget_2");
        storyScreen = new QLabel(widget_2);
        storyScreen->setObjectName("storyScreen");
        storyScreen->setGeometry(QRect(9, 10, 420, 640));
        sizePolicy2.setHeightForWidth(storyScreen->sizePolicy().hasHeightForWidth());
        storyScreen->setSizePolicy(sizePolicy2);
        storyScreen->setMinimumSize(QSize(420, 640));
        storyScreen->setMaximumSize(QSize(420, 637));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font4.setPointSize(26);
        storyScreen->setFont(font4);
        storyScreen->setStyleSheet(QString::fromUtf8("border-radius: 30px;\n"
"background-color: rgb(0, 0, 0);\n"
"color: #FFF;"));
        storyScreen->setPixmap(QPixmap(QString::fromUtf8("../../../../../Downloads/f826bf2ad330de7ee18d2bd8cd03b9ad.jpg")));
        storyScreen->setScaledContents(false);
        storyScreen->setAlignment(Qt::AlignmentFlag::AlignCenter);
        storyScreen->setWordWrap(true);
        storyScreen->setMargin(10);
        expandinglabel = new QWidget(widget_2);
        expandinglabel->setObjectName("expandinglabel");
        expandinglabel->setGeometry(QRect(9, 520, 420, 41));
        QSizePolicy sizePolicy9(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(expandinglabel->sizePolicy().hasHeightForWidth());
        expandinglabel->setSizePolicy(sizePolicy9);
        expandinglabel->setMinimumSize(QSize(420, 41));
        expandinglabel->setMaximumSize(QSize(420, 80));
        expandinglabel->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 128);"));
        verticalLayout_3 = new QVBoxLayout(expandinglabel);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        mediaCaption = new QLabel(expandinglabel);
        mediaCaption->setObjectName("mediaCaption");
        QSizePolicy sizePolicy10(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(mediaCaption->sizePolicy().hasHeightForWidth());
        mediaCaption->setSizePolicy(sizePolicy10);
        mediaCaption->setMinimumSize(QSize(420, 41));
        mediaCaption->setMaximumSize(QSize(420, 80));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font5.setPointSize(15);
        mediaCaption->setFont(font5);
        mediaCaption->setStyleSheet(QString::fromUtf8("color: white;"));
        mediaCaption->setAlignment(Qt::AlignmentFlag::AlignCenter);
        mediaCaption->setWordWrap(true);

        verticalLayout_3->addWidget(mediaCaption);


        horizontalLayout->addWidget(widget_2);

        nextStoryButton = new QPushButton(storyHBox);
        nextStoryButton->setObjectName("nextStoryButton");
        sizePolicy5.setHeightForWidth(nextStoryButton->sizePolicy().hasHeightForWidth());
        nextStoryButton->setSizePolicy(sizePolicy5);
        nextStoryButton->setMinimumSize(QSize(45, 45));
        nextStoryButton->setMaximumSize(QSize(45, 45));
        nextStoryButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        nextStoryButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/nextButton.png);\n"
"background-color: transparent;\n"
"border: none;"));

        horizontalLayout->addWidget(nextStoryButton);


        verticalLayout_2->addWidget(storyHBox);

        StoriesWindow->setCentralWidget(centralwidget);
        noStoryText->raise();
        noStoryLabel->raise();
        scrollArea->raise();
        storyContentBox->raise();

        retranslateUi(StoriesWindow);

        QMetaObject::connectSlotsByName(StoriesWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StoriesWindow)
    {
        StoriesWindow->setWindowTitle(QCoreApplication::translate("StoriesWindow", "StatusWindow", nullptr));
        label->setText(QCoreApplication::translate("StoriesWindow", "Stories", nullptr));
        addStoryButton->setText(QString());
        closeButton->setText(QString());
        myStoriesButton->setText(QCoreApplication::translate("StoriesWindow", "My stories", nullptr));
        recentStoriesLabel->setText(QCoreApplication::translate("StoriesWindow", "Recent stories", nullptr));
        friendStory_3->setText(QCoreApplication::translate("StoriesWindow", "Friend Name", nullptr));
        friendStory_4->setText(QCoreApplication::translate("StoriesWindow", "Friend Name", nullptr));
        friendStory_6->setText(QCoreApplication::translate("StoriesWindow", "Friend Name", nullptr));
        friendStory_7->setText(QCoreApplication::translate("StoriesWindow", "Friend Name", nullptr));
        friendStory_8->setText(QCoreApplication::translate("StoriesWindow", "Friend Name", nullptr));
        noStoryLabel->setText(QString());
        noStoryText->setText(QCoreApplication::translate("StoriesWindow", "No stories found", nullptr));
        label_3->setText(QString());
        label_2->setText(QString());
        previousStoryButton->setText(QString());
        mediaCaption->setText(QCoreApplication::translate("StoriesWindow", "sadsa", nullptr));
        nextStoryButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StoriesWindow: public Ui_StoriesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSWINDOW_H
