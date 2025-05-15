//
// Created by M.Ramadan on 4/16/25.
//

#ifndef CHATROOM_H
#define CHATROOM_H
#include <vector>
#include <algorithm>
#include <json.hpp>

#include "Message.h"
using namespace nlohmann;
class User;
using namespace std;
class ChatRoom {
    long long id;
    string name;
protected:
    vector<User> users;
    vector<Message> messages;
    //SearchEngine searcher;
    inline static long long Id_Generator = 0;
    inline static vector<ChatRoom> chatRooms;
public:
    ChatRoom();
    ChatRoom(long long id, string name, vector<User> &users, vector<Message> &messages);
    ChatRoom(string name, vector<User> &users, vector<Message> &messages);
    long long getId();
    string getName();
    const vector<User>& getUsers();
    vector<Message> getMessages();
    void setId(long long id);
    void setName(string name);
    void setUsers(vector<User> &users);
    void setMessages(vector<Message> &messages);
    void addMessage(Message &message);
    static vector<ChatRoom> getChatRooms();
    static ChatRoom fromJson(const json &json);
    json toJson();
    void save();
    static void writeChatRooms();
    static void readChatRooms();
    bool operator<(const ChatRoom &chatRoom) const;

};
#include "User.h"
#endif //CHATROOM_H