#pragma once

#include <string>

struct Message
{
    std::string Id;
    std::string ChatroomId;
    std::string Message;
    std::string SenderId;
    std::string ReceiverId;
    int Timestamp;
};