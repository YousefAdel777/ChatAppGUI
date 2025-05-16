#include "Story.h"
#include "Date.h"
#include <iostream>
class Date;

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

bool Story::operator<(const Story &story) const {
    tm self = getPublishTime();
    tm other = story.getPublishTime();
    return mktime(&other) > mktime(&self);
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

bool Story::isExcluded(const int &id) {
    return excludedIds.find(id) != excludedIds.end();
}
