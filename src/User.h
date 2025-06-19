//
// Created by M.Ramadan on 4/16/25/
//

#ifndef  USER_H
#define USER_H

#include <queue>
#include <vector>
#include <json.hpp>
#include <set>
#include <fstream>
#include <unordered_set>
#include <bcrypt/src/bcrypt.h>
#include <regex>

#include "UserProfileDescription.h"
using namespace std;
using json = nlohmann::json;

class Story;
class ChatRoomModel;
class UserProfileDescription;

class User {
    inline static int count;
    inline static vector<User> users;
    static optional<User> currentUser;
    int id;
    tm lastSeen;
    string mobileNumber;
    string password;
    string firstName;
    string lastName;
    priority_queue<long long> chatRooms;
    set<Story> stories;
    set<int> contacts;
    UserProfileDescription userProfileDescription;
    unordered_set<int> infoVisibility;
    unordered_set<int> lastSeenVisibility;
    unordered_set<int> blocked;
    unordered_set<int> seenVisibility;
public:
    User(
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
    );

    User(
        const string &mobileNumber,
        const string &password,
        const string &firstName,
        const string &lastName,
        const priority_queue<long long> &chatRooms,
        const set<Story> &stories,
        const set<int> &contacts,
        const UserProfileDescription &userProfileDescription
    );

    User();

    int getId();

    void setId(int id);

    string getPassword();

    void setPassword(const string &password);

    string getMobileNumber();

    void setMobileNumber(const string &mobileNumber);

    string getFirstName();

    void setFirstName(const string &firstName);

    string getLastName();

    void setLastName(const string &lastName);

    set<int> getContacts();

    void setContacts(const set<int> &contacts);

    priority_queue<long long> getChatRooms();

    void setChatRooms(const priority_queue<long long> &chatRooms);

    set<Story> getStories();

    void setStories(const set<Story> &stories);

    UserProfileDescription& getUserProfileDescription();

    void setUserProfileDescription(const UserProfileDescription &userProfileDescription);

    static vector<User> getUsers();

    unordered_set<int> getInfoVisibility();

    void setInfoVisibility(unordered_set<int> infoVisibility);

    unordered_set<int> getLastSeenVisibility();

    void setLastSeenVisibility(unordered_set<int> lastSeenVisibility);

    unordered_set<int> getBlocked();

    void setBlocked(unordered_set<int> blocked);

    unordered_set<int> getSeenVisibility();

    void setSeenVisibility(unordered_set<int> seenVisibility);

    static int getCount();

    void addContact(int userId);

    void save();

    void deleteAccount();

    set<User> recommendContacts();

    bool operator<(const User &user) const;

    // nlohmann cannot deserialize priority_queue by default must convert to vector or list
    static User fromJson(const json &json);

    // nlohmann cannot serialize priority_queue by default must convert to vector or list
    json toJson();

    tm getLastSeen();

    void setLastSeen(const tm &lastSeen);

    void addChatRoom(int chatId);

    void removeChatRoom(int chatId);

    static void readUsers();

    static void writeUsers();

    static void readCurrentUser();

    static void writeCurrentUser();

    static bool login(const string &mobileNumber, const string &password);

    static bool signUp(const string &mobileNumber, const string &firstName, const string &lastName, const string &password, const UserProfileDescription &userProfileDescription);

    static optional<User> getUser(const string &mobileNumber);

    static optional<User> getUser(int id);

    void addInfoVisibility(int userId);

    void removeInfoVisibility(int userId);

    void addBlocked(int userId);

    void removeBlocked(int userId);

    void addSeenVisibility(int userId);

    void removeSeenVisibility(int userId);

    void addLastSeenVisibility(int userId);

    void removeLastSeenVisibility(int userId);

    static bool validateMobileNumber(const string &mobileNumber);

    static bool validatePassword(const string &password);

    static optional<User> getCurrentUser();

    static void setCurrentUser(const User &user);

    static void logout();

    bool hasContact(int userId);
    void addStory(Story story);
};


#include "ChatRoomModel.h"
#include "Story.h"
#endif //USER_H
