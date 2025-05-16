//
// Created by M.Ramadan on 4/16/25.
//

#ifndef ChatRoomModel_H
#define ChatRoomModel_H
#include <set>
#include <vector>
#include <json.hpp>
#include "MessageModel.h"
using namespace nlohmann;
class User;
using namespace std;
class ChatRoomModel {
    long long id;
    string name;
protected:
    vector<int> users;
    set<MessageModel> messages;
    //SearchEngine searcher;
    inline static long long Id_Generator = 0;
    inline static unordered_map<int,ChatRoomModel>ChatRoomModels;
public:
    ChatRoomModel();
    ChatRoomModel(long long id, string name, vector<int> &users, set<MessageModel> &messages);
    ChatRoomModel(string name, vector<int> &users, set<MessageModel> &messages);
    long long getId();
    string getName();
    const vector<int>& getUsers();
    set<MessageModel> getMessages();
    void setId(long long id);
    void setName(string name);
    MessageModel getMessage(int id);
    void setUsers(vector<int> &users);
    void setMessages(set<MessageModel> &messages);
    void addMessage(MessageModel &message);
    void clearMessages();
    void removeMessage(long long id);
    static optional<ChatRoomModel>  getChatRoomModel(int id);
    static ChatRoomModel fromJson(const json &json);
    json toJson();
    void save();
    static void writeChatRoomModels();
    static void readChatRoomModels();
    bool operator<(const ChatRoomModel &ChatRoomModel) const;
};
#include "User.h"
#endif //ChatRoomModel_H
