#ifndef ROOM_H
#define ROOM_H

#include <QString>
#include <QVector>
#include "clientsocket.h"

class Room
{
private:
    QString roomname;
    QVector<ClientSocket*> users;

public:
    Room(QString roomname = "");
    QString getRoomname() const;
    void setRoomname(const QString &value);
    void insertUser(ClientSocket* user);
    void removeUser(ClientSocket* user);
    QVector<ClientSocket*>& getAllUsers();
};

#endif // ROOM_H
