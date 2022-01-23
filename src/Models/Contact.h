#pragma once

#include <string>

struct Contact
{
    Contact() {}
    Contact(std::string id, std::string name) {
        this->Id = id;
        this->Name = name;
    }

    std::string Id;
    std::string Name;
};
