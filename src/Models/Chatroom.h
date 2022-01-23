#pragma once

struct Chatroom
{
    Chatroom() {}
    Chatroom(int id, int contactId) {
        this->Id = id;
        this->ContactId = contactId;
    }

    std::string Id;
    std::string Name;
    std::string ContactId;
};
