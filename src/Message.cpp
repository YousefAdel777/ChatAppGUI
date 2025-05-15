//
// Created by M.Ramadan on 4/16/25.
//

#include "Message.h"

#include <utility>
Message::Message() {
    messageID = 0;
    userID = 0;
    content = "";
    Status status = Status();
}
Message::Message(int messageID, int userID, std::string content, Status status) {
    this->messageID = messageID;
    this->userID = userID;
    this->content = std::move(content);
    this->status = status;
}
int Message::getMessageID() {
    return messageID;
}
int Message::getUserID() {
    return userID;
}
std::string Message::getContent() {
    return content;
}
Status Message::getStatus() {
    return status;
}
void Message::setMessageID(int messageID) {
    this->messageID = messageID;
}
void Message::setUserID(int userID) {
    this->userID = userID;
}
void Message::setContent(std::string content) {
    this->content = content;
}
void Message::setStatus(Status status) {
    this->status = status;
}
