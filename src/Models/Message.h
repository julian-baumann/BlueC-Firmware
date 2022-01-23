#pragma once

#include <string>

struct Message
{
    Message() {}

    Message(int id, std::string chatroomId, std::string text, std::string senderContactId, int timestamp) {
        this->Id = id;
        this->ChatroomId = chatroomId;
        this->Text = text;
        this->SenderContactId = senderContactId;
        this->Timestamp = timestamp;
    }

    std::string Id;
    std::string ChatroomId;
    std::string SenderContactId;
    std::string Text;
    int Timestamp;
};