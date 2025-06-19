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
protected:
    enum ChatType {
        INDIVIDUAL = 0,
        GROUP = 1
    };
    vector<int> users;
    set<MessageModel> messages;
    //SearchEngine searcher;
    inline static long long Id_Generator = 0;
    inline static unordered_map<int,ChatRoomModel*>ChatRoomModels;
    long long id;
    string name;
    ChatType chatType;
public:
    bool type;

    ChatRoomModel();
    ChatRoomModel(long long id,bool type, string name, vector<int> &users, set<MessageModel> &messages);
    ChatRoomModel(string name,bool type, vector<int> &users, set<MessageModel> &messages);
    static ChatRoomModel * createChat(vector<int> usersIds);
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
    static optional<ChatRoomModel*>  getChatRoomModel(int id);
    static ChatRoomModel * fromJson(const json &json);
    virtual json toJson();
    void save();

    static void writeChatRoomModels();
    static void readChatRoomModels();
    bool operator<(const ChatRoomModel &ChatRoomModel) const;
    virtual ~ChatRoomModel() = default;
private:
    void addMember(int userId);
};
#include "User.h"
#endif //ChatRoomModel_H
