//
// Created by M.Ramadan on 4/16/25.
//
#include "./ChatRoom.h"
#include <QCoreApplication>
#include <Group.h>
ChatRoomModel::ChatRoomModel() :
    id(++Id_Generator),
    name("ChatRoomModel"+to_string(id)),
    chatType(ChatRoomModel::ChatType::INDIVIDUAL)
{
    type = 0;
}
ChatRoomModel::ChatRoomModel(long long id,bool type, string name, vector<int> &users, set<MessageModel> &messages):
    id(id),
    name(name),
    users(users),
    messages(messages),
    type(type),
    chatType(ChatRoomModel::ChatType::INDIVIDUAL)
{
    save();
}
ChatRoomModel::ChatRoomModel(string name,bool type, vector<int> &users, set<MessageModel> &messages):
    id(++Id_Generator),
    name(name),
    users(users),
    messages(messages),
    type(type),
    chatType(ChatRoomModel::ChatType::INDIVIDUAL)
{
    save();
}

long long ChatRoomModel::getId() {
    return id;
}
string ChatRoomModel::getName() {
    return name;
}
const vector<int>& ChatRoomModel::getUsers() {
    return users;
}
set<MessageModel> ChatRoomModel::getMessages() {
    return messages;
}
void ChatRoomModel::setId(long long id) {
    this->id = id;
}
void ChatRoomModel::setName(string name) {
    this->name = name;
    save();
}
void ChatRoomModel::setUsers(vector<int> &users) {
    this->users = users;
    save();
}
MessageModel ChatRoomModel::getMessage(int id){
    return *messages.find(MessageModel(id));
}

ChatRoomModel * ChatRoomModel::createChat(vector<int> usersIds) {
    ChatRoomModel * chat = new ChatRoomModel();
    for (const int id : usersIds) {
        chat->addMember(id);
    }
    int id = User::getCurrentUser()->getId();
    User::setCurrentUser(User::getUser(id).value());
    chat->save();
    return chat;
}

void ChatRoomModel::setMessages(set<MessageModel> &messages) {
    this->messages = messages;
    save();
}
void ChatRoomModel::addMessage(MessageModel &message) {
    messages.insert(message);
    save();
}
void ChatRoomModel::clearMessages() {
    messages.clear();
    save();
}
void ChatRoomModel::removeMessage(long long id) {
    messages.erase(messages.lower_bound(MessageModel(id)));
    save();
}
optional<ChatRoomModel*> ChatRoomModel::getChatRoomModel(int id) {
    if( ChatRoomModels.count(id)==0)
        return nullopt;
    return ChatRoomModels[id];
}
ChatRoomModel* ChatRoomModel::fromJson(const json &json) {
    vector<int> users;
    set<MessageModel> messages;
    for (const auto &user : json["users"]) {
        users.push_back(user.get<int>());
    }
    for (const auto &message : json["messages"]) {
        messages.insert(MessageModel::fromJson(message));
    }
    ChatType chatType = json["chatType"].get<ChatType>();
    if (chatType == ChatType::INDIVIDUAL) {
        return new ChatRoomModel(
            json["id"].get<long long>(),
            json["type"].get<bool>(),
            json["name"].get<string>(),
            users,
            messages
        );
    }
    return Group::fromJson(json);
}
json ChatRoomModel::toJson() {
    json json;
    if (chatType == ChatType::GROUP) {
        Group* group = static_cast<Group*>(this);
        json = group->toJson();
    }
    json["type"] = type;
    json["chatType"] = chatType;
    json["id"] = id;
    json["name"] = name;
    json["users"] = json::array();
    for (int &user : users) {
        json["users"].push_back(user);
    }
    json["messages"] = json::array();
    for (MessageModel message : messages) {
        json["messages"].push_back(message.toJson());
    }
    return json;
}
void ChatRoomModel::save() {
    ChatRoomModels[id]= this;
}
void ChatRoomModel::addMember(int userId) {
    User user = User::getUser(userId).value();
    user.addChatRoom(id);
    user.save();
    users.push_back(userId);
}
void ChatRoomModel::writeChatRoomModels() {
    ofstream file(QCoreApplication::applicationDirPath().toStdString()+"/../../src/data/chatRooms.json");
    json json = json::array();
    if (!file.is_open()) {
        throw runtime_error("Failed to open ChatRoomModels.json");
    }
    for (auto &x: ChatRoomModels) {
        json.push_back(x.second->toJson());
    }
    file << json.dump(2);
    file.close();
}
void ChatRoomModel::readChatRoomModels() {
    ifstream file(QCoreApplication::applicationDirPath().toStdString()+"/../../src/data/chatRooms.json");
    json json;
    if (!file.is_open()) {
        throw runtime_error("Failed to open ChatRoomModels.json");
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        file.close();
        return;
    }
    file.seekg(0, ios::beg);
    file >> json;
    file.close();
    for (const auto &ChatRoomModel : json) {
        Id_Generator++;
        if(ChatRoomModel["type"].get<bool>()==0)
            ChatRoomModels[ChatRoomModel["id"].get<long long>()]=fromJson(ChatRoomModel);
        else
            ChatRoomModels[ChatRoomModel["id"].get<long long>()]=Group::fromJson(ChatRoomModel);
    }
}
bool ChatRoomModel::operator<(const ChatRoomModel &ChatRoomModel) const {
    MessageModel message = *ChatRoomModel.messages.rbegin();
    MessageModel currentChatMessage = *messages.rbegin();
    Status messageStatus = message.getStatus();
    Status currentMessageStatus = currentChatMessage.getStatus();
    tm messageTime = messageStatus.getDeliveryTime();
    tm currentTime = currentMessageStatus.getDeliveryTime();
    return mktime(&messageTime) < mktime(&currentTime);
}
