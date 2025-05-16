#include "AddStoryPage.h"
// This include MUST come after the header
#include "ui_AddStoryPage.h"

#include <QDebug>
AddStoryPage::AddStoryPage(QWidget *parent, const User& user)
    : QDialog(parent),
    ui(new Ui::AddStoryPage) {
    this->user = user;
    ui->setupUi(this);
    initializeAddStoryPage();
}

AddStoryPage::~AddStoryPage() {
    delete ui;
}

void AddStoryPage::on_textChoice_clicked(){
    initializeTextPage();
    ui->addStoryWindow->setCurrentIndex(1);
}

void AddStoryPage::on_closeButton_clicked() {
    ui->addStoryWindow->setCurrentIndex(0);
}

void AddStoryPage::on_closeMedia_clicked() {
    ui->addStoryWindow->setCurrentIndex(0);
}

void AddStoryPage::on_paletteButton_clicked() {
    ui->colorPalette->setVisible(true);
    ui->doneButton->setVisible(true);
    ui->closeButton->setVisible(false);
}

void AddStoryPage::on_doneButton_clicked() {
    ui->colorPalette->setVisible(false);
    ui->doneButton->setVisible(false);
    ui->closeButton->setVisible(true);
}

void AddStoryPage::on_publishButton_clicked() {

    string storyText = ui->storyText->toPlainText().toStdString();
    if(storyText.size()){
        string storyColor = ui->storyText->styleSheet().toStdString();
        Story story(user.getId(), Date::getNow(), storyText, "", {}, storyColor);
        user.addStory(story);
        user.save();
        User::setCurrentUser(user);
        ui->addStoryWindow->setCurrentIndex(0);
    }

}

void AddStoryPage::on_publishMedia_clicked() {
    if (!ui->mediaLabel->pixmap().isNull()) {
        string mediaCaption = ui->mediaCaption->toPlainText().toStdString();
        Story story(user.getId(), Date::getNow(), mediaCaption, mediaPath.toStdString(), {});
        user.addStory(story);
        user.save();
        User::setCurrentUser(user);
        ui->addStoryWindow->setCurrentIndex(0);
    }
}

void AddStoryPage::on_mediaChoice_clicked() {
    selectMedia();
}

void AddStoryPage::on_selectAnotherMedia_clicked() {
    selectMedia();
}

void AddStoryPage::setOpacityFor(QWidget* button) {

    QGraphicsOpacityEffect *opacity = new QGraphicsOpacityEffect(this);
    opacity->setOpacity(0.5);
    button->setGraphicsEffect(opacity);
}

void AddStoryPage::setSelectedColor(int colorIndex) {
    unselectAllButtons();
    selectButton(colorIndex);
    QString style = ui->storyText->styleSheet();
    // Remove any previous background-color
    style.remove(QRegularExpression("background-color\\s*:\\s*#[0-9a-fA-F]{6};"));

    if(!colorIndex){//red
        ui->buttonsHbox->setStyleSheet(red);
        ui->doneAndExit->setStyleSheet(red);
        style.append(red);
        ui->storyText->setStyleSheet(style);
        ui->textArea->setStyleSheet(red);
    }
    else if(colorIndex == 1){//blue
        ui->buttonsHbox->setStyleSheet(blue);
        ui->doneAndExit->setStyleSheet(blue);
        style.append(blue);
        ui->storyText->setStyleSheet(style);
        ui->textArea->setStyleSheet(blue);
    }
    else if(colorIndex == 2){//green
        ui->buttonsHbox->setStyleSheet(green);
        ui->doneAndExit->setStyleSheet(green);
        style.append(green);
        ui->storyText->setStyleSheet(style);
        ui->textArea->setStyleSheet(green);
    }
    else{//yellow
        ui->buttonsHbox->setStyleSheet(yellow);
        ui->doneAndExit->setStyleSheet(yellow);
        style.append(yellow);
        ui->storyText->setStyleSheet(style);
        ui->textArea->setStyleSheet(yellow);
    }
}

void AddStoryPage::unselectAllButtons() {
    QString style = ui->redButton->styleSheet();

    style.replace(
        QRegularExpression("border\\s*:\\s*2px\\s+solid\\s+#FFFFFF;"),
        "border: 0px solid #FFFFFF;"
        );

    ui->redButton->setStyleSheet(style);


    //////////////////////////////////////////////////////
    style = ui->blueButton->styleSheet();
    style.replace(
        QRegularExpression("border\\s*:\\s*2px\\s+solid\\s+#FFFFFF;"),
        "border: 0px solid #FFFFFF;"
        );

    ui->blueButton->setStyleSheet(style);
    //////////////////////////////////////////////////////
    style = ui->greenButton->styleSheet();

    style.replace(
        QRegularExpression("border\\s*:\\s*2px\\s+solid\\s+#FFFFFF;"),
        "border: 0px solid #FFFFFF;"
        );

    ui->greenButton->setStyleSheet(style);

    //////////////////////////////////////////////////////

    style = ui->yellowButton->styleSheet();

    style.replace(
        QRegularExpression("border\\s*:\\s*2px\\s+solid\\s+#FFFFFF;"),
        "border: 0px solid #FFFFFF;"
        );

    ui->yellowButton->setStyleSheet(style);
}

void AddStoryPage::selectButton(int colorIndex) {
    QString style;



    if(!colorIndex){//red
        style = ui->redButton->styleSheet();
    }
    else if(colorIndex == 1){//blue
        style = ui->blueButton->styleSheet();
    }
    else if(colorIndex == 2){//green
        style = ui->greenButton->styleSheet();
    }
    else{//yellow
        style = ui->yellowButton->styleSheet();
    }
    style.replace(
        QRegularExpression("border\\s*:\\s*0px\\s+solid\\s+#FFFFFF;"),
        "border: 2px solid #FFFFFF;"
        );
    if(!colorIndex){//red
        ui->redButton->setStyleSheet(style);
    }
    else if(colorIndex == 1){//blue
        ui->blueButton->setStyleSheet(style);
    }
    else if(colorIndex == 2){//green
        ui->greenButton->setStyleSheet(style);
    }
    else{//yellow
        ui->yellowButton->setStyleSheet(style);
    }
}

void AddStoryPage::selectMedia() {
    mediaPath = QFileDialog::getOpenFileName(this,
                                                     tr("Select media file"),
                                                     QCoreApplication::applicationDirPath(),
                                                     tr("Image Files (*.jpg *.png *.bmp)"));
    if (!mediaPath.isEmpty()) {
        initializeMediaPage(mediaPath);
    }

}

void AddStoryPage::initializeAddStoryPage() {
    ui->addStoryWindow->setCurrentIndex(0);
    initializeTextPage();
}

void AddStoryPage::initializeTextPage() {
    ui->doneButton->setVisible(false);
    setOpacityFor(ui->closeButton);
    setOpacityFor(ui->paletteButton);
    setOpacityFor(ui->lowerButtonsHbox);
    ui->colorPalette->setVisible(false);
    ui->storyText->setText("");
    ui->storyText->selectAll();
    ui->storyText->setAlignment(Qt::AlignCenter);

    setSelectedColor(0);
    connect(ui->redButton, &QPushButton::clicked, this, [=]() { setSelectedColor(0);});
    connect(ui->blueButton, &QPushButton::clicked, this, [=]() { setSelectedColor(1); });
    connect(ui->greenButton, &QPushButton::clicked, this, [=]() { setSelectedColor(2); });
    connect(ui->yellowButton, &QPushButton::clicked, this, [=]() { setSelectedColor(3); });

}

void AddStoryPage::initializeMediaPage(const QString &mediaPath) {
    QPixmap pixmap(mediaPath);
    ui->mediaCaption->setText("");
    if (pixmap.isNull()) {
        return;
    }

    ui->mediaLabel->setPixmap(pixmap.scaled(ui->mediaLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->addStoryWindow->setCurrentIndex(2);
}

