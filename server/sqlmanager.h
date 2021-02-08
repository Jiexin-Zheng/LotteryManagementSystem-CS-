#ifndef SQLMANAGER_H
#define SQLMANAGER_H

#include <QSqlDatabase>

class SqlManager
{
private:
    QSqlDatabase db;
    SqlManager();
    static SqlManager* instance;
public:
    static SqlManager* getInstance();
    void openDatabase();
    void closeDatabase();
};

#endif // SQLMANAGER_H
