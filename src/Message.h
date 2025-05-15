//
// Created by M.Ramadan on 4/16/25.
//

#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include "Status.h"


class Message {
    private:
    int messageID;
    int userID;
    std::string content;
    Status status;

    public:
    Message();
    Message(int messageID, int userID, std::string content, Status status);
    int getMessageID();
    int getUserID();
    std::string getContent();
    Status getStatus();
    void setMessageID(int messageID);
    void setUserID(int userID);
    void setContent(std::string content);
    void setStatus(Status status);
};



#endif //MESSAGE_H
