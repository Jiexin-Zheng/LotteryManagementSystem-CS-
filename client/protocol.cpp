#include "protocol.h"
#include <cstring>
#include <QJsonDocument>
#include <QVariant>
#include <QJsonArray>
#include <QStringList>

Protocol::Protocol()
{
    this->clear();
}

Protocol::Type Protocol::getType() const
{
    return type;
}

void Protocol::setType(const Type &value)
{
    type = value;
}

quint32 Protocol::getLen() const
{
    return len;
}

void Protocol::setLen(const quint32 &value)
{
    len = value;
}

void Protocol::setUsername(const QString& username)
{
    QByteArray array(username.toUtf8().data(), username.toUtf8().size());
    array = array.toBase64(QByteArray::Base64Encoding);

    this->object["username"] = QString::fromUtf8(array);
}

QString Protocol::getUsername() const
{
    QString data = this->object["username"].toString();
    data = QString::fromUtf8(QByteArray::fromBase64(QByteArray(data.toUtf8().data(), data.size()), QByteArray::Base64Encoding));

    return data;
}

void Protocol::setUserpwd(const QString& userpwd)
{
    QByteArray array(userpwd.toUtf8().data(), userpwd.toUtf8().size());
    array = array.toBase64(QByteArray::Base64Encoding);

    this->object["userpwd"] = QString::fromUtf8(array);
}

QString Protocol::getUserpwd() const
{
    QString data = this->object["userpwd"].toString();
    data = QString::fromUtf8(QByteArray::fromBase64(QByteArray(data.toUtf8().data(), data.size()), QByteArray::Base64Encoding));

    return data;
}

void Protocol::setUserOnline(bool online)
{
    this->object["online"] = online;
}

bool Protocol::getUserOnline() const
{
    return this->object["online"].toBool();
}

void Protocol::setData(QString data)
{
    QByteArray array(data.toUtf8().data(), data.toUtf8().size());
    array = array.toBase64(QByteArray::Base64Encoding);

    this->object["data"] = QString::fromUtf8(array);
}

QString Protocol::getData() const
{
    QString data = this->object["data"].toString();
    data = QString::fromUtf8(QByteArray::fromBase64(QByteArray(data.toUtf8().data(), data.size()), QByteArray::Base64Encoding));

    return data;
}

void Protocol::setRoomname(const QString &roomname)
{
    QByteArray array(roomname.toUtf8().data(), roomname.toUtf8().size());
    array = array.toBase64(QByteArray::Base64Encoding);

    this->object["roomname"] = QString::fromUtf8(array);
}

QString Protocol::getRoomname() const
{
    QString data = this->object["roomname"].toString();
    data = QString::fromUtf8(QByteArray::fromBase64(QByteArray(data.toUtf8().data(), data.size()), QByteArray::Base64Encoding));

    return data;
}

void Protocol::setRoomUsers(QStringList users)
{
    QJsonArray array;
    QStringList::iterator it;
    for(it = users.begin(); it != users.end(); ++it){
        QByteArray barray(it->toUtf8().data(), it->toUtf8().size());
        barray = barray.toBase64(QByteArray::Base64Encoding);
        array.push_back(QString::fromUtf8(barray));
    }

    this->object["roomuser"] = array;
}

QStringList Protocol::getRoomUsers() const
{
    QStringList list;
    QJsonArray array = this->object["roomuser"].toArray();

    QJsonArray::iterator it;
    for(it = array.begin(); it != array.end(); ++it){
        QString data = it->toString();
        data = QString::fromUtf8(QByteArray::fromBase64(QByteArray(data.toUtf8().data(), data.size()), QByteArray::Base64Encoding));
        list.push_back(data);
    }

    return list;
}

QByteArray Protocol::toArray()
{
    //先序列化
    QJsonDocument document(this->object);
    QByteArray serialize = document.toJson();

    this->len = serialize.size();

    QByteArray array;
    array.append((char*)this, sizeof(Type) + sizeof(quint32));
    array.append(serialize);

    return array;
}

void Protocol::fromJson(const QByteArray &array)
{
    this->object = QJsonDocument::fromJson(array).object();
}

int Protocol::size()
{
    return sizeof(Type) + sizeof(quint32);
}

char *Protocol::toChar()
{
    return (char*)this;
}

void Protocol::clear()
{
    this->type = Protocol::none;
    this->len = 0;
    this->object = QJsonObject();
}
