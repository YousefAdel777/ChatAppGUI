//
// Created by M.Ramadan on 4/16/25.
//

#include "User.h"
#include <QString>
#include <QDir>
#include <QCoreApplication>

optional<User> User::currentUser;

User::User(
    int id,
    tm lastSeen,
    const string &mobileNumber,
    const string &password,
    const string &firstName,
    const string &lastName,
    const priority_queue<long long> &chatRooms,
    const set<Story> &stories,
    const set<int> &contacts,
    const UserProfileDescription &userProfileDescription,
    unordered_set<int> infoVisibility,
    unordered_set<int> lastSeenVisibility,
    unordered_set<int> blocked,
    unordered_set<int> seenVisibility
) {
    this->id = id;
    this->lastSeen = lastSeen;
    this->mobileNumber = mobileNumber;
    this->password = password;
    this->firstName = firstName;
    this->lastName = lastName;
    this->chatRooms = chatRooms;
    this->contacts = contacts;
    this->stories = stories;
    this->userProfileDescription = userProfileDescription;
    this->infoVisibility = infoVisibility;
    this->lastSeenVisibility = lastSeenVisibility;
    this->blocked = blocked;
    this->seenVisibility = seenVisibility;
}

User::User(
    const string &mobileNumber,
    const string &password,
    const string &firstName,
    const string &lastName,
    const priority_queue<long long> &chatRooms,
    const set<Story> &stories,
    const set<int> &contacts,
    const UserProfileDescription &userProfileDescription
) {
    count++;
    this->id = count;
    this->lastSeen = Date::getNow();
    this->mobileNumber = mobileNumber;
    this->password = password;
    this->firstName = firstName;
    this->lastName = lastName;
    this->chatRooms = chatRooms;
    this->stories = stories;
    this->contacts = contacts;
    this->userProfileDescription = userProfileDescription;
}

User::User() {}

int User::getId() {
    return id;
}

void User::setId(int id) {
    this->id = id;
}

string User::getPassword() {
    return password;
}

void User::setPassword(const string &password) {
    this->password = password;
}

string User::getFirstName() {
    return firstName;
}

void User::setFirstName(const string &firstName) {
    this->firstName = firstName;
}

string User::getLastName() {
    return lastName;
}

void User::setLastName(const string &lastName) {
    this->lastName = lastName;
}


string User::getMobileNumber() {
    return mobileNumber;
}

void User::setMobileNumber(const string &mobileNumber) {
    this->mobileNumber = mobileNumber;
}


priority_queue<long long> User::getChatRooms() {
    return chatRooms;
}

void User::setChatRooms(const priority_queue<long long> &chatRooms) {
    this->chatRooms = chatRooms;
}

set<int> User::getContacts() {
    return contacts;
}

void User::setContacts(const set<int> &contacts) {
    this->contacts = contacts;
}

set<Story> User::getStories() {
    return stories;
}

void User::setStories(const set<Story> &stories) {
    this->stories = stories;
}

UserProfileDescription& User::getUserProfileDescription() {
    return userProfileDescription;
}

void User::setUserProfileDescription(const UserProfileDescription &userProfileDescription) {
    this->userProfileDescription = userProfileDescription;
}

unordered_set<int> User::getInfoVisibility() {
    return infoVisibility;
}

void User::setInfoVisibility(unordered_set<int> infoVisibility) {
    this->infoVisibility = infoVisibility;
}

unordered_set<int> User::getSeenVisibility() {
    return seenVisibility;
}

void User::setSeenVisibility(unordered_set<int> seenVisibility) {
    this->seenVisibility = seenVisibility;
}

unordered_set<int> User::getLastSeenVisibility() {
    return lastSeenVisibility;
}

void User::setLastSeenVisibility(unordered_set<int> lastSeenVisibility) {
    this->lastSeenVisibility = lastSeenVisibility;
}

unordered_set<int> User::getBlocked() {
    return blocked;
}

void User::setBlocked(unordered_set<int> blocked) {
    this->blocked = blocked;
}

tm User::getLastSeen() {
    return lastSeen;
}

void User::setLastSeen(const tm &lastSeen) {
    this->lastSeen = lastSeen;
}

int User::getCount() {
    return count;
}

vector<User> User::getUsers() {
    return users;
}

void User::addContact(int userId) {
    contacts.insert(userId);
}

User User::fromJson(const json &json) {
    priority_queue<long long> chatRooms;
    set<Story> stories;
    set<User> contacts;
    UserProfileDescription userProfileDescription = UserProfileDescription::fromJson(json["userProfileDescription"]);
    for (const auto &chatRoom : json["chatRooms"]) {
        chatRooms.push(chatRoom);
    }
    for (const auto &story: json["stories"]) {
        Story storedStory = Story::fromJson(story);
        if (storedStory.isExpired()) {
            continue;
        }
        stories.insert(storedStory);
    }
    // auto time = json["lastSeen"].get<time_t>();
    return  User(
        json["id"].get<int>(),
        Date::fromJson(json["lastSeen"]),
        json["mobileNumber"].get<string>(),
        json["password"].get<string>(),
        json["firstName"].get<string>(),
        json["lastName"].get<string>(),
        chatRooms,
        stories,
        json["contacts"].get<set<int>>(),
        userProfileDescription,
        json["infoVisibility"].get<unordered_set<int>>(),
        json["lastSeenVisibility"].get<unordered_set<int>>(),
        json["blocked"].get<unordered_set<int>>(),
        json["seenVisibility"].get<unordered_set<int>>()
        );
}

json User::toJson() {
    json json;
    json["id"] = id;
    json["mobileNumber"] = mobileNumber;
    json["password"] = password;
    json["firstName"] = firstName;
    json["lastName"] = lastName;
    json["contacts"] = json::array();
    json["infoVisibility"] = infoVisibility;
    json["seenVisibility"] = seenVisibility;
    json["lastSeenVisibility"] = lastSeenVisibility;
    json["blocked"] = blocked;
    json["contacts"] = contacts;
    json["chatRooms"] = json::array();
    json["lastSeen"] = Date::toJson(lastSeen);
    while (!chatRooms.empty()) {
        long long chatRoom = chatRooms.top();
        json["chatRooms"].push_back(chatRoom);
        chatRooms.pop();
    }
    json["stories"] = json::array();
    for (Story story : stories) {
        json["stories"].push_back(story.toJson());
    }
    json["userProfileDescription"] = userProfileDescription.toJson();
    return json;
}

void User::addChatRoom(int chatId) {
    chatRooms.push(chatId);
}

void User::removeChatRoom(int chatId) {
    priority_queue<long long> newRooms;
    while (!chatRooms.empty()) {
        int chatRoom = chatRooms.top();
        chatRooms.pop();
        cout << chatRoom << chatId << endl;
        if (chatRoom == chatId) continue;
        newRooms.push(chatRoom);
    }
    chatRooms = newRooms;
}

void User::save() {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getId() == getId()) {
            *it = *this;
            return;
        }
    }
    users.push_back(*this);
}

void User::deleteAccount() {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getId() == getId()) {
            users.erase(it);
            return;
        }
    }
}

void User::writeUsers() {
    ofstream file(QCoreApplication::applicationDirPath().toStdString()+"/../../src/data/users.json");
    json json = json::array();
    if (!file.is_open()) {
        throw runtime_error("Failed to open users.json");
    }
    for (User &user : users) {
        json.push_back(user.toJson());
    }
    file << json.dump(2);
    file.close();
}

void User::readUsers() {
    ifstream file(QCoreApplication::applicationDirPath().toStdString()+"/../../src/data/users.json");
    json json;
    if (!file.is_open()) {
        throw runtime_error("Failed to open users.json");
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        file.close();
        return;
    }
    file.seekg(0, ios::beg);
    file >> json;
    file.close();
    if (json.empty()) return;
    for (const auto &user : json) {
        users.push_back(fromJson(user));
    }
    if (!users.empty()) {
        count = users.back().getId();
    }
}

void User::readCurrentUser() {
    ifstream file("../../src/data/currentUser.json");
    json json;
    if (!file.is_open()) {
        throw runtime_error("Failed to open currentUser.json");
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        file.close();
        return;
    }
    file.seekg(0, ios::beg);
    file >> json;
    file.close();
    if (!json.empty()) setCurrentUser(fromJson(json));
}

void User::writeCurrentUser() {
    ofstream file("../../src/data/currentUser.json");
    json json;
    if (!file.is_open()) {
        throw runtime_error("Failed to open currentUser.json");
    }
    if (currentUser.has_value()) {
        json = currentUser.value().toJson();
    };
    file << json.dump(2);
    file.close();
}

bool User::signUp(const string &mobileNumber, const string &firstName, const string &lastName, const string &password, const UserProfileDescription &userProfileDescription) {
    optional<User> optUser = getUser(mobileNumber);
    string hashedPassword = bcrypt::generateHash(password);
    User user(
        mobileNumber,
        hashedPassword,
        firstName,
        lastName,
        {},
        {},
        {},
        userProfileDescription
    );
    user.save();
    setCurrentUser(user);
    return true;
}

bool User::login(const string &mobileNumber, const string &password) {
    optional<User> optUser = getUser(mobileNumber);
    if (optUser.has_value()) {
        const User& user = optUser.value();
        if (bcrypt::validatePassword(password, user.password)) {
            setCurrentUser(user);
            return true;
        }
        return false;
    }
    return false;
}

optional<User> User::getUser(const string &mobileNumber) {
    for (User user : users) {
        if (user.getMobileNumber() == mobileNumber) {
            return user;
        }
    }
    return nullopt;
}

optional<User> User::getUser(int id) {
    for (User user : users) {
        if (user.getId() == id) {
            return user;
        }
    }
    return nullopt;
}

bool User::operator<(const User &user) const {
    return id < user.id;
}

set<User> User::recommendContacts() {
    unordered_map<int, int> distance;
    set<User> recommended;
    queue<User> q;
    q.push(*this);
    distance[id] = 0;

    while (!q.empty()) {
        User user = q.front();
        q.pop();
        int level = distance[user.getId()];
        if (level > 2) {
            break;
        }
        for (int contactId : user.getContacts()) {
            if (!distance[contactId]) {
                distance[contactId] = level + 1;
                optional<User> optionalUser = getUser(contactId);
                if (!optionalUser.has_value()) continue;
                User contact = optionalUser.value();
                q.push(contact);
                if (level + 1 == 2) {
                    recommended.insert(contact);
                }
            }
        }
    }
    return recommended;
}

void User::addBlocked(int userId) {
    blocked.insert(userId);
}

void User::removeBlocked(int userId) {
    blocked.erase(userId);
}

void User::addInfoVisibility(int userId) {
    infoVisibility.insert(userId);
}

void User::removeInfoVisibility(int userId) {
    infoVisibility.erase(userId);
}

void User::addSeenVisibility(int userId) {
    seenVisibility.insert(userId);
}

void User::removeSeenVisibility(int userId) {
    seenVisibility.erase(userId);
}

void User::addLastSeenVisibility(int userId) {
    lastSeenVisibility.insert(userId);
}

void User::removeLastSeenVisibility(int userId) {
    lastSeenVisibility.erase(userId);
}

bool User::validateMobileNumber(const string &mobileNumber) {
    regex pattern("^\\+[1-9]\\d{7,14}$");
    return regex_match(mobileNumber, pattern);
}

bool User::validatePassword(const string &password) {
    regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[^A-Za-z\\d]).{8,}$");
    return regex_match(password, pattern);
}

optional<User> User::getCurrentUser() {
    return currentUser;
}

void User::setCurrentUser(const User &user) {
    currentUser = user;
}

void User::logout() {
    currentUser.reset();
}

bool User::hasContact(int userId) {
    return contacts.find(userId) != contacts.end();
}

void User::addStory(Story story) {
    stories.insert(story);
}
