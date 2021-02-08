#include "sqldao.h"
#include "sqlmanager.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

SqlDao::SqlDao()
{

}

bool SqlDao::insertUser(const User &user) const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("insert into user(username,userpwd)values(:username,:userpwd);");
    query.bindValue(":username", user.getUsername());
    query.bindValue(":userpwd", user.getUserpwd());

    if(!(ret = query.exec())){
        qDebug()<<query.lastError().text();
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

bool SqlDao::selectUser(User &user) const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select userpwd,online from user where username = :username;");
    query.bindValue(":username", user.getUsername());

    if(!(ret = query.exec())){
        qDebug()<<query.lastError().text();
    }else{
        if(query.next()){
            //有了
            user.setUserpwd(query.value(0).toString());
            user.setOnline(query.value(1).toBool());
            ret = true;
        }else{
            ret = false;
        }
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

bool SqlDao::updateUser(const User &user) const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("update user set userpwd = :userpwd, online = :online where username = :username;");
    query.bindValue(":userpwd", user.getUserpwd());
    query.bindValue(":online", user.getOnline());
    query.bindValue(":username", user.getUsername());

    if(!(ret = query.exec())){
        qDebug()<<query.lastError().text();
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}
