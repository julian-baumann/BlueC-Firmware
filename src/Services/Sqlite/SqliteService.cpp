#include "SqliteService.hpp"

SqliteService::SqliteService() {
    sqlite3_initialize();
    if (!OpenDb())
    {
        return;
    }
}

bool SqliteService::Init() {
    return OpenDb() && CreateDefaultTables();
}


bool SqliteService::CreateDefaultTables()
{
    return CreateTableContact() && CreateTableChatroom() && CreateTableMessage();
}

bool SqliteService::CreateTableContact() {
    std::string query = std::format("CREATE TABLE IF NOT EXISTS {}", MESSAGE_TABLE_NAME);
}

bool SqliteService::OpenDb()
{
    bool success = sqlite3_open(_dbName, &_db);
    if (success)
    {
        _db = NULL;
        Serial.printf("Can't open database  - %s: %s\n", _dbName, sqlite3_errmsg(_db));
    }
    else
    {
        Serial.printf("Opened database successfully - %s\n", _dbName);
    }

    return success;
}