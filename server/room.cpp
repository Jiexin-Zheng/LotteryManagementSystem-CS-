#include "room.h"

QString Room::getRoomname() const
{
    return roomname;
}

void Room::setRoomname(const QString &value)
{
    roomname = value;
}

void Room::insertUser(ClientSocket *user)
{
    users.push_back(user);
}

void Room::removeUser(ClientSocket *user)
{
    QVector<ClientSocket*>::iterator it;
    for(it = users.begin(); it != users.end(); ++it){
        if(*it == user){
            users.erase(it);
            break;
        }
    }

    return;
}

QVector<ClientSocket *>& Room::getAllUsers()
{
    return users;
}

Room::Room(QString roomname)
    :roomname(roomname)
{

}
