//
// Created by M.Ramadan on 4/16/25.
//
#include "ChatRoom.h"

ChatRoom::ChatRoom() :
    id(++Id_Generator),
    name("ChatRoom"+to_string(id))
{}

ChatRoom::ChatRoom(long long id, string name, vector<User> &users, vector<Message> &messages):
    id(id),
    name(name),
    users(users),
    messages(messages)
{}
ChatRoom::ChatRoom(string name, vector<User> &users, vector<Message> &messages):
    id(++Id_Generator),
    name(name),
    users(users),
    messages(messages)
{}
long long ChatRoom::getId() {
    return id;
}
string ChatRoom::getName() {
    return name;
}
const vector<User>& ChatRoom::getUsers() {
    return users;
}
vector<Message> ChatRoom::getMessages() {
    return messages;
}
void ChatRoom::setId(long long id) {
    this->id = id;
}
void ChatRoom::setName(string name) {
    this->name = name;
}
void ChatRoom::setUsers(vector<User> &users) {
    this->users = users;
}
void ChatRoom::setMessages(vector<Message> &messages) {
    this->messages = messages;
}
void ChatRoom::addMessage(Message &message) {
    messages.push_back(message);
}
vector<ChatRoom> ChatRoom::getChatRooms() {
    return chatRooms;
}
ChatRoom ChatRoom::fromJson(const json &json) {
    vector<User> users;
    vector<Message> messages;
    for (const auto &user : json["users"]) {
        users.push_back(User::fromJson(user));
    }
    for (const auto &message : json["messages"]) {
        // TODO
        //messages.push_back(Message::fromJson(message));
    }
    return ChatRoom(
        json["id"].get<long long>(),
        json["name"].get<string>(),
        users,
        messages
    );
}
json ChatRoom::toJson() {
    json json;
    json["id"] = id;
    json["name"] = name;
    json["users"] = json::array();
    for (User &user : users) {
        json["users"].push_back(user.toJson());
    }
    json["messages"] = json::array();
    for (Message &message : messages) {
        //TODO
        //json["messages"].push_back(messages.toJson());
    }

    return json;
}
void ChatRoom::save() {
    chatRooms.push_back(*this);
}
void ChatRoom::writeChatRooms() {
    ofstream file("../data/chatRooms.json");
    json json = json::array();
    if (!file.is_open()) {
        throw runtime_error("Failed to open chatRooms.json");
    }
    for (ChatRoom &chatRoom : chatRooms) {
        json.push_back(chatRoom.toJson());
    }
    file << json.dump(2);
    file.close();
}
void ChatRoom::readChatRooms() {
    ifstream file("../data/chatRooms.json");
    json json;
    if (!file.is_open()) {
        throw runtime_error("Failed to open chatRooms.json");
    }
    file >> json;
    file.close();
    for (const auto &chatRoom : json) {
        chatRooms.push_back(fromJson(chatRoom));
    }
    if (!chatRooms.empty()) {
        Id_Generator = chatRooms.back().getId();
    }
}
bool ChatRoom::operator<(const ChatRoom &chatRoom) const {
    Message message = chatRoom.messages.back();
    Message currentChatMessage = messages.back();

    Status messageStatus = message.getStatus();
    Status currentMessageStatus = currentChatMessage.getStatus();

    tm messageTime = messageStatus.getDeliveryTime();
    tm currentTime = currentMessageStatus.getDeliveryTime();
    return mktime(&messageTime) < mktime(&currentTime);
}
