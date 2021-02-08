#include "sqlmanager.h"

SqlManager::SqlManager()
    :db(QSqlDatabase::addDatabase("QSQLITE"))
{
    db.setDatabaseName("data.db");
}

SqlManager* SqlManager::instance = new SqlManager;

SqlManager *SqlManager::getInstance()
{
    return instance;
}

void SqlManager::openDatabase()
{
    db.open();
}

void SqlManager::closeDatabase()
{
    db.close();
}
