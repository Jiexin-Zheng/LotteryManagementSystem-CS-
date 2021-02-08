#include "user.h"

QString User::getUsername() const
{
    return username;
}

void User::setUsername(const QString &value)
{
    username = value;
}

QString User::getUserpwd() const
{
    return userpwd;
}

void User::setUserpwd(const QString &value)
{
    userpwd = value;
}

bool User::getOnline() const
{
    return online;
}

void User::setOnline(bool value)
{
    online = value;
}

User::User(const QString &username, const QString &userpwd, bool online)
    :username(username), userpwd(userpwd), online(online)
{

}
