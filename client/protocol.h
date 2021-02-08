#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QString>
#include <QByteArray>
#include <QJsonObject>

/*
 * 变长包：定长部分 + 变长部分
 * 定长部分：存放发送的后续变长部分的长度
*/

class Protocol
{
public:
    enum Type{
        none = 0,
        regist,
        login,
        registError,
        loginError,
        quit,
        createRoom,
        quitRoom,
        refleshRoom,
        joinRoom,
        refleshUser,
        chat
    };
private:
    Type type;          //类型
    quint32 len;        //变长部分的长度
    QJsonObject object; //变长部分
public:
    Protocol();
    Type getType() const;
    void setType(const Type &value);

    quint32 getLen() const;
    void setLen(const quint32 &value);

    void setUsername(const QString& username);
    QString getUsername()const;
    void setUserpwd(const QString& userpwd);
    QString getUserpwd()const;
    void setUserOnline(bool online);
    bool getUserOnline()const;
    void setData(QString data);
    QString getData()const;
    void setRoomname(const QString& roomname);
    QString getRoomname()const;

    void setRoomUsers(QStringList users);
    QStringList getRoomUsers()const;

    QByteArray toArray();
    void fromJson(const QByteArray& array);
    static int size();
    char* toChar();
    void clear();
};

#endif // PROTOCOL_H
