#ifndef SQLDAO_H
#define SQLDAO_H

#include "user.h"

class SqlDao
{
public:
    SqlDao();

    bool insertUser(const User& user)const;
    bool selectUser(User& user)const;
    bool updateUser(const User& user)const;
};

#endif // SQLDAO_H
