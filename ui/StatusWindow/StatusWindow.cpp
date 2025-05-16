#include "StatusWindow.h"
#include "ui_StatusWindow.h"

StatusWindow::StatusWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::StoriesWindow) {
    ui->setupUi(this);
    User bruce("11", "1", "Bruce", "Wayne", {}, {}, {}, {});
    User barbra("?", "2", "Barbra", "Gordan", {}, {}, {}, {});
    User dick("?", "2", "Dick", "GraySon", {}, {}, {}, {});
    Story stor1(bruce.getId(), Date::getNow(), "الله اكبر", "", {});
    Story stor2(barbra.getId(), Date::getNow(), "الله اكبر", "", {});
    Story stor3(dick.getId(), Date::getNow(), "انطر ابلاكاش", "", {});
    bruce.addStory(stor1);
    barbra.addStory(stor2);
    dick.addStory(stor3);
    bruce.addContact(barbra.getId());
    barbra.addContact(bruce.getId());
    bruce.addContact(dick.getId());
    dick.addContact(bruce.getId());
    barbra.save();
    bruce.save();
    dick.save();
    User::setCurrentUser(bruce);
    User user = User::getCurrentUser().value();
    initializeStoriesPage(user);
}
void StatusWindow::loadPage() {
    ui->storyContentBox->setVisible(false);
    ui->myStoriesButton->setVisible(false);
    clearStories(ui->stories);
    contactButtons.clear();
}

void StatusWindow::setUpButton(QPushButton *button, set<Story>& currStories , int contactIndex, bool flag) {
    if(flag){
        button->setStyleSheet(defaultMyStoriesStyle);

        connect(button, &QPushButton::clicked, this, [this, currStories, contactIndex]() {
            updateButtonSelection(contactIndex);
            showUserStories(currStories);
        });
        return;
    }
    button->setStyleSheet(defaultStyle);
    button->setFixedSize(401, 81);
    button->setCursor(Qt::PointingHandCursor);

    connect(button, &QPushButton::clicked, this, [this, currStories, contactIndex]() {
        updateButtonSelection(contactIndex);
        showUserStories(currStories);
    });
}

void StatusWindow::initializeStoriesPage(User &user) {
    loadPage();
    int contactIndex = 0;
    set<Story> userStories = user.getStories();

    // Handle user's own stories
    if (!userStories.empty()) {
        ui->myStoriesButton->setVisible(true);
        // initializeUserImage();
        contactButtons.append(ui->myStoriesButton);
        setUpButton(ui->myStoriesButton, userStories, contactIndex, true);
        contactIndex++;
    }

    // Handle contacts' stories
    set<User> contacts;

    //getUserContacts(user.getContacts()):
    for (const int& id : user.getContacts()) {
        if (auto optContact = User::getUser(id); optContact.has_value()) {
            contacts.insert(optContact.value());
        }
    }

    for (User contact : contacts) {
        set<Story> contactStories;
        for (Story story : contact.getStories()) {
            if (!story.isExcluded(contact.getId())) {
                contactStories.insert(story);
            }
        }

        if (!contactStories.empty()) {
            QPushButton* contactButton = new QPushButton(
                QString("%1 %2").arg(
                QString::fromStdString(contact.getFirstName()),
                QString::fromStdString(contact.getLastName())),
                ui->stories
            );

            contactButtons.append(contactButton);

            setUpButton(contactButton, contactStories, contactIndex, false);
            ui->stories->layout()->addWidget(contactButton);
            contactIndex++;
        }
    }
}

void StatusWindow::updateButtonSelection(int newIndex) {
    // Reset previous selection
    if (selectedUser >= 0 && selectedUser < contactButtons.size()) {
        if (selectedUser == 0 && ui->myStoriesButton->isVisible()) {
            // Special case for "My Stories" button
            contactButtons[selectedUser]->setStyleSheet(defaultMyStoriesStyle);
        } else {
            // Normal contact buttons
            contactButtons[selectedUser]->setStyleSheet(defaultStyle);
        }
    }

    // Set new selection
    if (newIndex >= 0 && newIndex < contactButtons.size()) {
        contactButtons[newIndex]->setStyleSheet(selectedStyle);
        selectedUser = newIndex;
    }
}



void StatusWindow::clearStories(QWidget* container) {
    QLayout* layout = container->layout();
    if (!layout) return;

    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();  // deletes QLabel
        delete item;            // deletes the layout item
    }
}

void StatusWindow::displayCurrentStory() {
    if (currentStoryIndex < 0 || currentStoryIndex >= userStories.size()) {
        return;
    }
    QLayout* layout = ui->storyTimeBox->layout();
    QLayoutItem* item = layout->itemAt(currentStoryIndex);
    if(item && item->widget()){
        QWidget* indicator = item->widget();
        indicator->setStyleSheet("background-color: rgb(174, 209, 172);");
    }
    if(userStories[currentStoryIndex].second.isEmpty()){
        ui->expandinglabel->setVisible(false);
        ui->storyScreen->setText(userStories[currentStoryIndex].first.first);
        ui->storyScreen->setStyleSheet(userStories[currentStoryIndex].first.second);
    }
    else{
        ui->expandinglabel->setVisible(true);
        ui->mediaCaption->setText(userStories[currentStoryIndex].first.first);
        ui->storyScreen->setStyleSheet("background-color: black;");
        QString imagePath = userStories[currentStoryIndex].second;
        QPixmap pixmap(imagePath);

        if (!pixmap.isNull()) {
            ui->storyScreen->setPixmap(pixmap.scaled(
                ui->storyScreen->size(),           // Scale to fit the QLabel size
                Qt::KeepAspectRatio,               // Maintain aspect ratio
                Qt::SmoothTransformation));        // Smooth scaling
        }
    }
}

void StatusWindow::showUserStories(const set<Story>& stories) {
    userStories.clear();
    currentStoryIndex = 0;
    clearStories(ui->storyTimeBox);
    if(!ui->storyContentBox->isVisible()){
        ui->storyContentBox->setVisible(true);
    }

    makeUnclickable(ui->previousStoryButton, previousOpacity);
    if(stories.size() == 1){
        makeUnclickable(ui->nextStoryButton, nextOpacity);
    }
    else{
        makeClickable(ui->nextStoryButton, nextOpacity);
    }
    for(auto it = stories.rbegin(); it != stories.rend(); ++it){
        Story story = *it;
        userStories.append({{QString::fromStdString(story.getStoryText()),//Story text
                            QString::fromStdString(story.getStoryColor())},//Story Color "Text"
                            QString::fromStdString(story.getStoryPhotoPath())}//Story Image "Media"
                           );
        QLabel* storyIndicator = new QLabel(ui->storyTimeBox);
        storyIndicator->setStyleSheet("background-color: rgb(211, 232, 210);");

        ui->storyTimeBox->layout()->addWidget(storyIndicator);
    }
    displayCurrentStory();
}


void StatusWindow::on_previousStoryButton_clicked() {
    const int storyCount = ui->storyTimeBox->layout()->count();
    if(!currentStoryIndex){
        return;
    }
    QLayout* layout = ui->storyTimeBox->layout();
    QLayoutItem* item = layout->itemAt(currentStoryIndex);
    if(item && item->widget()){
        QWidget* indicator = item->widget();
        indicator->setStyleSheet("background-color: rgb(211, 232, 210);");
    }
    if(--currentStoryIndex == 0){
        makeUnclickable(ui->previousStoryButton, previousOpacity);
    }
    if(currentStoryIndex != storyCount - 1){
        makeClickable(ui->nextStoryButton, nextOpacity);
    }
    displayCurrentStory();
}


void StatusWindow::on_nextStoryButton_clicked() {
    const int storyCount = ui->storyTimeBox->layout()->count();
    if(currentStoryIndex == storyCount - 1){
        return;
    }
    if(++currentStoryIndex == storyCount - 1){
        makeUnclickable(ui->nextStoryButton, nextOpacity);
    }
    if(currentStoryIndex){
        makeClickable(ui->previousStoryButton, previousOpacity);
    }
    displayCurrentStory();
}

void StatusWindow::makeUnclickable(QPushButton *button, QGraphicsOpacityEffect*& effect) {
    setButtonOpacity(button, effect, 0.4);
    button->setCursor(Qt::ArrowCursor);
}

void StatusWindow::makeClickable(QPushButton *button, QGraphicsOpacityEffect *&effect) {
    setButtonOpacity(button, effect, 1.0);
    button->setCursor(Qt::PointingHandCursor);
}

void StatusWindow::setButtonOpacity(QPushButton* button, QGraphicsOpacityEffect*& effect, qreal opacity) {
    effect = new QGraphicsOpacityEffect(button);
    effect->setOpacity(opacity);
    button->setGraphicsEffect(effect);
}



StatusWindow::~StatusWindow() {
    delete ui;
}

void StatusWindow::on_addStoryButton_clicked() {
    User user = User::getCurrentUser().value();
    AddStoryPage* dialog = new AddStoryPage(this, user);
    dialog->setWindowModality(Qt::ApplicationModal);
    dialog->exec();  // or dialog->show();
    user = User::getCurrentUser().value();
    initializeStoriesPage(user);
}

void StatusWindow::initializeUserImage(string imagePath, QLabel *uiImage) {
    QPixmap src(QString::fromStdString(imagePath));

    QSize size = src.size();
    QPixmap dest(size);
    dest.fill(Qt::transparent);

    QPainter painter(&dest);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPainterPath path;
    path.addEllipse(0, 0, size.width(), size.height());
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, src);
    painter.end();

    uiImage->setPixmap(dest.scaled(85, 85));
}
