#include "Story.h"
#include <QCoreApplication>
Story::Story(
    const int &userId,
    const tm &publishTime,
    const string &storyText,
    const string &storyPhotoPath,
    const set<int> &excludedIds) : userId(userId),
    publishTime(publishTime),
    storyText(storyText),
    storyPhotoPath(storyPhotoPath),
    excludedIds(excludedIds) {
}

Story::Story(
    const int &userId,
    const tm &publishTime,
    const string &storyText,
    const string &storyPhotoPath,
    const set<int> &excludedIds,
    const string& storyColor
    ) : userId(userId),
    publishTime(publishTime),
    storyText(storyText),
    storyPhotoPath(storyPhotoPath),
    excludedIds(excludedIds),
    storyColor(storyColor) {
}


void Story::setId(const int &userId) {
    this->userId = userId;
}

int Story::getId() const {
    return userId;
}

void Story::setPublishTime(const tm &publishTime) {
    this->publishTime = publishTime;
}

tm Story::getPublishTime() const {
    return publishTime;
}

void Story::setStoryPhotoPath(const string &storyPhotoPath) {
    this->storyPhotoPath = storyPhotoPath;
}

string Story::getStoryPhotoPath() const {
    return storyPhotoPath;
}

void Story::setStoryText(const string &storyText) {
    this->storyText = storyText;
}

string Story::getStoryText() const {
    return storyText;
}

void Story::setStoryColor(const string &storyColor) {
    this->storyColor = storyColor;
}

string Story::getStoryColor() const {
    return storyColor;
}

bool Story::operator<(const Story &story) const {
    tm self = getPublishTime();
    tm other = story.getPublishTime();

    // First, compare by publishTime
    // if (mktime(&self) != mktime(&other)) {
    return mktime(&self) <= mktime(&other);  // Descending order of publish time
    // }

    // If publishTime is the same, compare by storyText
    // return storyText > story.getStoryText();
}
void Story::readStories() {
    ifstream file(QCoreApplication::applicationDirPath().toStdString()+"/../../src/data/stories.json");
    json json;
    if (!file.is_open()) {
        throw runtime_error("Failed to open users.json");
    }
    file >> json;
    file.close();
    for (const auto &story: json) {
        Story fileStory = fromJson(story);
        if (fileStory.isExpired()) {
            continue;
        }
        stories.push_back(fileStory);
    }
}

void Story::writeStories() {
    ofstream file(QCoreApplication::applicationDirPath().toStdString()+"/../../src/data/stories.json");
    json json = json::array();
    if (!file.is_open()) {
        throw runtime_error("Failed to open users.json");
    }
    for (Story story: stories) {
        json.push_back(story.toJson());
    }
    file << json.dump(2);
    file.close();
}

set<Story> Story::retrieveStoriesByUserId(const int &userId) {
    set<Story> userStories;
    for (const Story &story: stories) {
        if (story.getId() == userId) {
            userStories.insert(story);
        }
    }
    return userStories;
}

Story Story::fromJson(const json &json) {
    set<int> excluded = set<int>(json["excludedIds"].begin(), json["excludedIds"].end());
    return Story(
        json["userId"].get<int>(),
        Date::fromJson(json["publishTime"]),
        json["storyText"].get<string>(),
        json["storyPhotoPath"].get<string>(),
        excluded
        );
}


json Story::toJson() {
    json json;
    json["userId"] = userId;
    json["publishTime"] = Date::toJson(publishTime);
    json["storyText"] = storyText;
    json["storyPhotoPath"] = storyPhotoPath;
    json["excludedIds"] = excludedIds;
    return json;
}

bool Story::isExpired() const {
    tm now = Date::getNow();
    tm publishTime = this->publishTime;
    int timeLimit = 24 * 60 * 60; //24 hours in seconds
    return difftime(mktime(&now), mktime(&publishTime)) > timeLimit;
}

void Story::excludeContact(const int &id) {
    excludedIds.insert(id);
}

void Story::includeContact(const int &id) {
    excludedIds.erase(id);
}

bool Story::isExcluded(const int &id) const {
    if(User::getUser(userId).has_value()){
        User storyUser = User::getUser(userId).value();
        return storyUser.hasContact(id) && excludedIds.find(id) != excludedIds.end();
    }
    return false;
}


void Story::save() {
    stories.push_back(*this);
}
