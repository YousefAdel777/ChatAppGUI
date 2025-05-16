//
// Created by M.Ramadan on 4/16/25.
//

#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H
#include <string>
#include <json.hpp>
#include <status.h>
using namespace nlohmann;

class MessageModel {
    public:
    int messageID;
    int userID;
    std::string content;
    std::string prompt;
    Status status;
    public:
    enum MessageDataType{
        TEXT=1,
        VOICE=2,
        DOCUMENT=3,
        IMAGE=4
    };

    enum MessageType{
        RECEIVED = 1,
        SENT = 2
    };

    enum MessageOptions{
        NORMAL = 1,
        REPLY  = 2
    };
    MessageModel(int MessageID = 0);
    MessageModel(int messageID, int userID,MessageDataType datatype,MessageType type,MessageOptions option, int ReplyMessageID, std::string content, Status status,std::string prompt="");
    int getMessageID();
    static MessageDataType toMessageDataType(int value);
    static MessageType toMessageType(int value);
    static MessageOptions toMessageOptions(int value);
    int getUserID();
    std::string getContent();
    std::string getPrompt();
    Status getStatus();
    void setMessageID(int messageID);
    void setUserID(int userID);
    void setContent(std::string content);
    void setStatus(Status status);
    bool operator<(const MessageModel &message) const;
    bool operator==(const MessageModel &message) const;
    static MessageModel fromJson(const json &json);
    json toJson();
    MessageDataType datatype;
    MessageType type;
    int ReplyMessageID;
    MessageOptions option;
};



#endif //MESSAGEMODEL_H
