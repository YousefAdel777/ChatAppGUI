/********************************************************************************
** Form generated from reading UI file 'addStoryPage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTORYPAGE_H
#define UI_ADDSTORYPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddStoryPage
{
public:
    QStackedWidget *addStoryWindow;
    QWidget *mainPage;
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *textChoice;
    QToolButton *mediaChoice;
    QLabel *label;
    QLabel *label_2;
    QWidget *textPage;
    QWidget *colorPalette;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *redButton;
    QPushButton *blueButton;
    QPushButton *greenButton;
    QPushButton *yellowButton;
    QWidget *lowerButtonsHbox;
    QHBoxLayout *horizontalLayout_13;
    QToolButton *publishButton;
    QToolButton *excludeContacts;
    QWidget *screen;
    QVBoxLayout *verticalLayout_3;
    QWidget *buttonsHbox;
    QHBoxLayout *horizontalLayout_6;
    QWidget *doneAndExit;
    QHBoxLayout *horizontalLayout_14;
    QToolButton *doneButton;
    QToolButton *closeButton;
    QToolButton *paletteButton;
    QWidget *textArea;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QTextEdit *storyText;
    QSpacerItem *verticalSpacer2;
    QWidget *mediaPage;
    QToolButton *closeMedia;
    QLabel *mediaLabel;
    QWidget *lowerButtonsHbox_2;
    QHBoxLayout *horizontalLayout_15;
    QToolButton *excludeContactsFromMedia;
    QToolButton *publishMedia;
    QTextEdit *mediaCaption;
    QToolButton *selectAnotherMedia;

    void setupUi(QDialog *AddStoryPage)
    {
        if (AddStoryPage->objectName().isEmpty())
            AddStoryPage->setObjectName("AddStoryPage");
        AddStoryPage->resize(420, 640);
        AddStoryPage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        addStoryWindow = new QStackedWidget(AddStoryPage);
        addStoryWindow->setObjectName("addStoryWindow");
        addStoryWindow->setGeometry(QRect(0, 0, 420, 640));
        addStoryWindow->setFrameShape(QFrame::Shape::NoFrame);
        mainPage = new QWidget();
        mainPage->setObjectName("mainPage");
        centralwidget = new QWidget(mainPage);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 420, 641));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 7, 420, 91));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(28);
        horizontalLayout->setObjectName("horizontalLayout");
        textChoice = new QToolButton(widget);
        textChoice->setObjectName("textChoice");
        textChoice->setMinimumSize(QSize(0, 0));
        textChoice->setMaximumSize(QSize(150, 96));
        textChoice->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        textChoice->setAutoFillBackground(false);
        textChoice->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	font: 52pt \"Bell MT\";\n"
"    background-color: #EAF3EB;\n"
"    border: 2px solid;\n"
"    border-radius: 25px;\n"
"    padding: 10px;\n"
"    font-size: 22px;\n"
"    color: black;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/T.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        textChoice->setIcon(icon);
        textChoice->setIconSize(QSize(20, 20));
        textChoice->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(textChoice);

        mediaChoice = new QToolButton(widget);
        mediaChoice->setObjectName("mediaChoice");
        mediaChoice->setMinimumSize(QSize(0, 0));
        mediaChoice->setMaximumSize(QSize(150, 96));
        mediaChoice->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        mediaChoice->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	font: 52pt \"Bell MT\";\n"
"    background-color: #EAF3EB;\n"
"    border: 2px solid;\n"
"    border-radius: 25px;\n"
"    padding: 10px;\n"
"    font-size: 22px;\n"
"    color: black;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/black-color-palette.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        mediaChoice->setIcon(icon1);
        mediaChoice->setIconSize(QSize(25, 25));
        mediaChoice->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(mediaChoice);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 220, 150, 150));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/art.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label->setTextInteractionFlags(Qt::TextInteractionFlag::LinksAccessibleByMouse);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 381, 420, 48));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bell MT")});
        font.setPointSize(35);
        font.setBold(false);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(173, 173, 173);"));
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        addStoryWindow->addWidget(mainPage);
        textPage = new QWidget();
        textPage->setObjectName("textPage");
        colorPalette = new QWidget(textPage);
        colorPalette->setObjectName("colorPalette");
        colorPalette->setGeometry(QRect(0, 498, 420, 61));
        colorPalette->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        horizontalLayout_4 = new QHBoxLayout(colorPalette);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        redButton = new QPushButton(colorPalette);
        redButton->setObjectName("redButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(redButton->sizePolicy().hasHeightForWidth());
        redButton->setSizePolicy(sizePolicy1);
        redButton->setMinimumSize(QSize(93, 50));
        redButton->setMaximumSize(QSize(93, 50));
        redButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        redButton->setAutoFillBackground(false);
        redButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #FB7A7A;\n"
"    border: 0px solid #FFFFFF;\n"
"    border-radius: 25px;\n"
"}\n"
""));
        redButton->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(redButton);

        blueButton = new QPushButton(colorPalette);
        blueButton->setObjectName("blueButton");
        sizePolicy1.setHeightForWidth(blueButton->sizePolicy().hasHeightForWidth());
        blueButton->setSizePolicy(sizePolicy1);
        blueButton->setMinimumSize(QSize(93, 50));
        blueButton->setMaximumSize(QSize(93, 50));
        blueButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        blueButton->setAutoFillBackground(false);
        blueButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #44E2F4;\n"
"    border: 0px solid #FFFFFF;\n"
"    border-radius: 25px;\n"
"}\n"
""));
        blueButton->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(blueButton);

        greenButton = new QPushButton(colorPalette);
        greenButton->setObjectName("greenButton");
        sizePolicy1.setHeightForWidth(greenButton->sizePolicy().hasHeightForWidth());
        greenButton->setSizePolicy(sizePolicy1);
        greenButton->setMinimumSize(QSize(93, 50));
        greenButton->setMaximumSize(QSize(93, 50));
        greenButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        greenButton->setAutoFillBackground(false);
        greenButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #6AF273;\n"
"    border: 0px solid #FFFFFF;\n"
"    border-radius: 25px;\n"
"}\n"
""));
        greenButton->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(greenButton);

        yellowButton = new QPushButton(colorPalette);
        yellowButton->setObjectName("yellowButton");
        sizePolicy1.setHeightForWidth(yellowButton->sizePolicy().hasHeightForWidth());
        yellowButton->setSizePolicy(sizePolicy1);
        yellowButton->setMinimumSize(QSize(93, 50));
        yellowButton->setMaximumSize(QSize(93, 50));
        yellowButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        yellowButton->setAutoFillBackground(false);
        yellowButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #EEE369;\n"
"    border: 0px solid #FFFFFF;\n"
"    border-radius: 25px;\n"
"}\n"
""));
        yellowButton->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(yellowButton);

        redButton->raise();
        greenButton->raise();
        yellowButton->raise();
        blueButton->raise();
        lowerButtonsHbox = new QWidget(textPage);
        lowerButtonsHbox->setObjectName("lowerButtonsHbox");
        lowerButtonsHbox->setGeometry(QRect(0, 572, 420, 68));
        lowerButtonsHbox->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 128);"));
        horizontalLayout_13 = new QHBoxLayout(lowerButtonsHbox);
        horizontalLayout_13->setSpacing(162);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        publishButton = new QToolButton(textPage);
        publishButton->setObjectName("publishButton");
        publishButton->setGeometry(QRect(362, 582, 52, 51));
        publishButton->setMinimumSize(QSize(34, 24));
        publishButton->setMaximumSize(QSize(52, 51));
        publishButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        publishButton->setAutoFillBackground(false);
        publishButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background-color: rgba(67, 255, 105, 255);\n"
"    border: none;\n"
"    border-radius: 25px;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/blackSend.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        publishButton->setIcon(icon2);
        publishButton->setIconSize(QSize(20, 20));
        publishButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        excludeContacts = new QToolButton(textPage);
        excludeContacts->setObjectName("excludeContacts");
        excludeContacts->setGeometry(QRect(8, 591, 180, 31));
        sizePolicy1.setHeightForWidth(excludeContacts->sizePolicy().hasHeightForWidth());
        excludeContacts->setSizePolicy(sizePolicy1);
        excludeContacts->setMinimumSize(QSize(0, 0));
        excludeContacts->setMaximumSize(QSize(180, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font1.setWeight(QFont::Medium);
        font1.setItalic(false);
        excludeContacts->setFont(font1);
        excludeContacts->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        excludeContacts->setAutoFillBackground(false);
        excludeContacts->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background-color: rgb(0, 10, 33);\n"
"	font: 500 5pt \"Product Sans Medium\";\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    font-size: 20px;\n"
"    color: white;\n"
"}\n"
""));
        excludeContacts->setIconSize(QSize(20, 20));
        excludeContacts->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        screen = new QWidget(textPage);
        screen->setObjectName("screen");
        screen->setGeometry(QRect(0, 0, 420, 731));
        verticalLayout_3 = new QVBoxLayout(screen);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        buttonsHbox = new QWidget(screen);
        buttonsHbox->setObjectName("buttonsHbox");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonsHbox->sizePolicy().hasHeightForWidth());
        buttonsHbox->setSizePolicy(sizePolicy2);
        buttonsHbox->setMinimumSize(QSize(420, 91));
        buttonsHbox->setMaximumSize(QSize(420, 91));
        buttonsHbox->setStyleSheet(QString::fromUtf8("background-color: #FB7A7A;"));
        horizontalLayout_6 = new QHBoxLayout(buttonsHbox);
        horizontalLayout_6->setSpacing(245);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        doneAndExit = new QWidget(buttonsHbox);
        doneAndExit->setObjectName("doneAndExit");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(doneAndExit->sizePolicy().hasHeightForWidth());
        doneAndExit->setSizePolicy(sizePolicy3);
        doneAndExit->setMinimumSize(QSize(0, 91));
        doneAndExit->setMaximumSize(QSize(93, 91));
        doneAndExit->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        doneAndExit->setStyleSheet(QString::fromUtf8("background-color: #FB7A7A;"));
        horizontalLayout_14 = new QHBoxLayout(doneAndExit);
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        doneButton = new QToolButton(doneAndExit);
        doneButton->setObjectName("doneButton");
        sizePolicy1.setHeightForWidth(doneButton->sizePolicy().hasHeightForWidth());
        doneButton->setSizePolicy(sizePolicy1);
        doneButton->setMinimumSize(QSize(93, 50));
        doneButton->setMaximumSize(QSize(93, 50));
        doneButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        doneButton->setAutoFillBackground(false);
        doneButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	font: 500 9pt \"Product Sans Medium\";\n"
"    background-color: #FFF;\n"
"    border: none;\n"
"    border-radius: 25px;\n"
"    font-size: 22px;\n"
"    color: black;\n"
"}\n"
""));
        doneButton->setIconSize(QSize(20, 20));
        doneButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        horizontalLayout_14->addWidget(doneButton);

        closeButton = new QToolButton(doneAndExit);
        closeButton->setObjectName("closeButton");
        closeButton->setMinimumSize(QSize(34, 24));
        closeButton->setMaximumSize(QSize(52, 51));
        closeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        closeButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        closeButton->setAutoFillBackground(false);
        closeButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background-color: rgb(0, 10, 33);\n"
"    border: none;\n"
"    border-radius: 25px;\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/whiteclose.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        closeButton->setIcon(icon3);
        closeButton->setIconSize(QSize(30, 30));
        closeButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);

        horizontalLayout_14->addWidget(closeButton);


        horizontalLayout_6->addWidget(doneAndExit);

        paletteButton = new QToolButton(buttonsHbox);
        paletteButton->setObjectName("paletteButton");
        paletteButton->setMinimumSize(QSize(34, 24));
        paletteButton->setMaximumSize(QSize(52, 51));
        paletteButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        paletteButton->setAutoFillBackground(false);
        paletteButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background-color: rgb(0, 10, 33);\n"
"    border: none;\n"
"    border-radius: 25px;\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/color-palette.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        paletteButton->setIcon(icon4);
        paletteButton->setIconSize(QSize(20, 20));
        paletteButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);

        horizontalLayout_6->addWidget(paletteButton);


        verticalLayout_3->addWidget(buttonsHbox);

        textArea = new QWidget(screen);
        textArea->setObjectName("textArea");
        textArea->setMinimumSize(QSize(420, 640));
        textArea->setMaximumSize(QSize(420, 640));
        textArea->setStyleSheet(QString::fromUtf8("background-color: #FB7A7A;"));
        verticalLayout_4 = new QVBoxLayout(textArea);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer = new QSpacerItem(20, 49, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_4->addItem(verticalSpacer);

        storyText = new QTextEdit(textArea);
        storyText->setObjectName("storyText");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font2.setPointSize(26);
        storyText->setFont(font2);
        storyText->setStyleSheet(QString::fromUtf8("background-color: #FB7A7A;\n"
"color: rgb(255, 255, 255);"));
        storyText->setFrameShape(QFrame::Shape::NoFrame);
        storyText->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        storyText->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

        verticalLayout_4->addWidget(storyText);

        verticalSpacer2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer2);


        verticalLayout_3->addWidget(textArea);

        addStoryWindow->addWidget(textPage);
        screen->raise();
        colorPalette->raise();
        lowerButtonsHbox->raise();
        publishButton->raise();
        excludeContacts->raise();
        mediaPage = new QWidget();
        mediaPage->setObjectName("mediaPage");
        closeMedia = new QToolButton(mediaPage);
        closeMedia->setObjectName("closeMedia");
        closeMedia->setGeometry(QRect(14, 20, 51, 51));
        closeMedia->setMinimumSize(QSize(34, 24));
        closeMedia->setMaximumSize(QSize(52, 51));
        closeMedia->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        closeMedia->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        closeMedia->setAutoFillBackground(false);
        closeMedia->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background-color: rgb(0, 10, 33);\n"
"    border: none;\n"
"    border-radius: 25px;\n"
"}\n"
""));
        closeMedia->setIcon(icon3);
        closeMedia->setIconSize(QSize(30, 30));
        closeMedia->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        mediaLabel = new QLabel(mediaPage);
        mediaLabel->setObjectName("mediaLabel");
        mediaLabel->setGeometry(QRect(0, 0, 420, 640));
        mediaLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        mediaLabel->setPixmap(QPixmap(QString::fromUtf8("../../../../../Downloads/so-did-i-miss-it-or-was-this-never-explained-v0-fz0txu9r02hd1.png")));
        mediaLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lowerButtonsHbox_2 = new QWidget(mediaPage);
        lowerButtonsHbox_2->setObjectName("lowerButtonsHbox_2");
        lowerButtonsHbox_2->setGeometry(QRect(0, 572, 420, 68));
        lowerButtonsHbox_2->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 128);"));
        horizontalLayout_15 = new QHBoxLayout(lowerButtonsHbox_2);
        horizontalLayout_15->setSpacing(162);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        excludeContactsFromMedia = new QToolButton(mediaPage);
        excludeContactsFromMedia->setObjectName("excludeContactsFromMedia");
        excludeContactsFromMedia->setGeometry(QRect(8, 591, 180, 31));
        sizePolicy1.setHeightForWidth(excludeContactsFromMedia->sizePolicy().hasHeightForWidth());
        excludeContactsFromMedia->setSizePolicy(sizePolicy1);
        excludeContactsFromMedia->setMinimumSize(QSize(0, 0));
        excludeContactsFromMedia->setMaximumSize(QSize(180, 31));
        excludeContactsFromMedia->setFont(font1);
        excludeContactsFromMedia->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        excludeContactsFromMedia->setAutoFillBackground(false);
        excludeContactsFromMedia->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background-color: rgb(0, 10, 33);\n"
"	font: 500 5pt \"Product Sans Medium\";\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    font-size: 20px;\n"
"    color: white;\n"
"}\n"
""));
        excludeContactsFromMedia->setIconSize(QSize(20, 20));
        excludeContactsFromMedia->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        publishMedia = new QToolButton(mediaPage);
        publishMedia->setObjectName("publishMedia");
        publishMedia->setGeometry(QRect(362, 582, 52, 51));
        publishMedia->setMinimumSize(QSize(34, 24));
        publishMedia->setMaximumSize(QSize(52, 51));
        publishMedia->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        publishMedia->setAutoFillBackground(false);
        publishMedia->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background-color: rgba(67, 255, 105, 255);\n"
"    border: none;\n"
"    border-radius: 25px;\n"
"}\n"
""));
        publishMedia->setIcon(icon2);
        publishMedia->setIconSize(QSize(20, 20));
        publishMedia->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        mediaCaption = new QTextEdit(mediaPage);
        mediaCaption->setObjectName("mediaCaption");
        mediaCaption->setGeometry(QRect(40, 539, 371, 31));
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(mediaCaption->sizePolicy().hasHeightForWidth());
        mediaCaption->setSizePolicy(sizePolicy4);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Product Sans Medium")});
        font3.setPointSize(14);
        font3.setWeight(QFont::Medium);
        font3.setItalic(false);
        mediaCaption->setFont(font3);
        mediaCaption->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"	background-color: rgb(0, 10, 33);\n"
"	font: 500 14pt \"Product Sans Medium\";\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    color: white;\n"
"}\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #f0f0f0;\n"
"    width: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}"));
        selectAnotherMedia = new QToolButton(mediaPage);
        selectAnotherMedia->setObjectName("selectAnotherMedia");
        selectAnotherMedia->setGeometry(QRect(5, 539, 34, 31));
        selectAnotherMedia->setMinimumSize(QSize(34, 24));
        selectAnotherMedia->setMaximumSize(QSize(52, 51));
        selectAnotherMedia->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        selectAnotherMedia->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        selectAnotherMedia->setAutoFillBackground(false);
        selectAnotherMedia->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background-color: rgb(0, 10, 33);\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/folder.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        selectAnotherMedia->setIcon(icon5);
        selectAnotherMedia->setIconSize(QSize(20, 20));
        selectAnotherMedia->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        addStoryWindow->addWidget(mediaPage);
        mediaLabel->raise();
        closeMedia->raise();
        lowerButtonsHbox_2->raise();
        excludeContactsFromMedia->raise();
        publishMedia->raise();
        mediaCaption->raise();
        selectAnotherMedia->raise();

        retranslateUi(AddStoryPage);

        addStoryWindow->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AddStoryPage);
    } // setupUi

    void retranslateUi(QDialog *AddStoryPage)
    {
        AddStoryPage->setWindowTitle(QCoreApplication::translate("AddStoryPage", "MainWindow", nullptr));
        textChoice->setText(QCoreApplication::translate("AddStoryPage", "Text", nullptr));
        mediaChoice->setText(QCoreApplication::translate("AddStoryPage", "Media", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("AddStoryPage", "Create and express", nullptr));
        redButton->setText(QString());
        blueButton->setText(QString());
        greenButton->setText(QString());
        yellowButton->setText(QString());
        publishButton->setText(QString());
        excludeContacts->setText(QCoreApplication::translate("AddStoryPage", "Exclude contacts", nullptr));
        doneButton->setText(QCoreApplication::translate("AddStoryPage", "Done", nullptr));
        closeButton->setText(QString());
        paletteButton->setText(QString());
        storyText->setHtml(QCoreApplication::translate("AddStoryPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Product Sans Medium'; font-size:26pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        storyText->setPlaceholderText(QString());
        closeMedia->setText(QString());
        mediaLabel->setText(QString());
        excludeContactsFromMedia->setText(QCoreApplication::translate("AddStoryPage", "Exclude contacts", nullptr));
        publishMedia->setText(QString());
        mediaCaption->setHtml(QCoreApplication::translate("AddStoryPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Product Sans Medium'; font-size:14pt; font-weight:500; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10px;\"><br /></p></body></html>", nullptr));
        mediaCaption->setPlaceholderText(QCoreApplication::translate("AddStoryPage", "Add a caption...", nullptr));
        selectAnotherMedia->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddStoryPage: public Ui_AddStoryPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTORYPAGE_H
