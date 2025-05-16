//
// Created by M.Ramadan on 4/16/25.
//

#include "MessageModel.h"
#include "User.h"
#include <recording.h>
#include <utility>
MessageModel::MessageModel(int MessageId){
    messageID = MessageId;
    userID = 0;
    content = "";
    Status status = Status();
}
MessageModel::MessageModel(int messageID, int userID,MessageDataType datatype,MessageType type,MessageOptions option,
             int ReplyMessageID, std::string content, Status status,std::string prompt):
    messageID(messageID),userID(userID),datatype(datatype),type(type),option(option),ReplyMessageID(ReplyMessageID),
    content(std::move(content)),status(status),prompt(std::move(prompt)){
}
int MessageModel::getMessageID() {
    return messageID;
}
int MessageModel::getUserID() {
    return userID;
}
std::string MessageModel::getContent() {
    return content;
}
Status MessageModel::getStatus() {
    return status;
}
string MessageModel::getPrompt(){
    return prompt;
}
void MessageModel::setMessageID(int messageID) {
    this->messageID = messageID;
}
void MessageModel::setUserID(int userID) {
    this->userID = userID;
}
void MessageModel::setContent(std::string content) {
    this->content = content;
}
void MessageModel::setStatus(Status status) {
    this->status = status;
}

json MessageModel::toJson() {
    json json;
    json["id"] = messageID;
    json["user_id"] = userID;
    json["reply_message_id"] = ReplyMessageID;
    json["datatype"] = datatype;
    json["option"] = option;
    json["content"] = content;
    json["prompt"] = prompt;
    json["status"] = status.toJson();
    return json;
}
MessageModel MessageModel::fromJson(const json &json) {
    MessageType type;
    auto status = Status::fromJson(json["status"]);
    if(json["user_id"].get<int>()==User::getCurrentUser()->getId())
        type = SENT;
    else
    {
        type = RECEIVED;
        status.setSeen(json["user_id"].get<int>());
    }
    return MessageModel(
        json["id"].get<int>(),
        json["user_id"].get<int>(),
        toMessageDataType(json["datatype"].get<int>()),
        type,
        toMessageOptions(json["option"].get<int>()),
        json["reply_message_id"].get<int>(),
        json["content"].get<string>(),
        status,
        json["prompt"].get<string>()
        );
}

MessageModel::MessageDataType MessageModel::toMessageDataType(int value) {
    switch (value) {
    case 1: return TEXT;
    case 2: return VOICE;
    case 3: return DOCUMENT;
    case 4: return IMAGE;
    default:
        throw std::invalid_argument("Invalid MessageDataType value: " + std::to_string(value));
    }
}

MessageModel::MessageType MessageModel::toMessageType(int value) {
    switch (value) {
    case 1: return RECEIVED;
    case 2: return SENT;
    default:
        throw std::invalid_argument("Invalid MessageType value: " + std::to_string(value));
    }
}


MessageModel::MessageOptions MessageModel::toMessageOptions(int value) {
    switch (value) {
    case 1: return NORMAL;
    case 2: return REPLY;
    default:
        throw std::invalid_argument("Invalid MessageType value: " + std::to_string(value));
    }
}

bool MessageModel::operator<(const MessageModel &message) const {
    return messageID < message.messageID;
}

bool MessageModel::operator==(const MessageModel& message) const {
    return messageID==message.messageID;
}
