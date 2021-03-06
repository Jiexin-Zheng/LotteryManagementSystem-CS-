#ifndef USER_H
#define USER_H

#include <QString>

class User
{
private:
    QString username;
    QString userpwd;
    bool online;
public:
    User(const QString& username = "", const QString& userpwd = "", bool online = false);
    QString getUsername() const;
    void setUsername(const QString &value);
    QString getUserpwd() const;
    void setUserpwd(const QString &value);
    bool getOnline() const;
    void setOnline(bool value);
};

#endif // USER_H
