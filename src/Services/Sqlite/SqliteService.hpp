#pragma once

// Sqlite3 libary: https://github.com/siara-cc/esp32_arduino_sqlite3_lib
// Sqlite3 callback example: https://stackoverflow.com/questions/31146713/sqlite3-exec-callback-function-clarification

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <format>
#include <string>
#include <sqlite3.h>
#include <SPI.h>
#include <FS.h>
#include <list>
#include "../../Models/Chatroom.h"
#include "SqliteConstants.hpp"
#include "../../Models/Contact.h"
#include "../../Models/Message.h"

class SqliteService  {
public: 
    SqliteService();

    bool Init();

    bool InsertMessage(Message * message);
    bool DeleteMessage(int messageId);
    bool GetMessagesFromChatroom(std::string chatroomId, std::list<Message> *data);

    bool insertIntoChatroom(Chatroom * message);
    bool DeleteChatroom(int chatroomId);
    bool GetAllChatrooms(std::list<Chatroom> *data);

    bool InsertContact(Contact * message);
    bool DeleteContact(int messageId);
    bool GetAllContacts(std::list<Contact> *data);

private:
    const char *_dbName = "/sd/BlueC.db"; // SD-Card storage
    sqlite3 *_db = NULL;

private: 
    bool CreateDefaultTables();
    
    bool CreateTableContact();
    bool CreateTableChatroom();
    bool CreateTableMessage();
    
    bool OpenDb();
    bool Query(std::string query);
    bool Query(std::string query, int (*callback)(void*,int,char**,char**));
    bool Query(std::string query, int (*callback)(void*,int,char**,char**), void* callbackData);
};