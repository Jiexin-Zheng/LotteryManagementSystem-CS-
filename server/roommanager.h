#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include <QVector>
#include "room.h"

class RoomManager
{
private:
    RoomManager();
    static RoomManager* instance;
    QVector<Room> rooms;

public:
    static RoomManager* getInstance();

    void insertRoom(Room room);
    void removeRoom(QString roomname);
    Room* selectRoom(QString roomname);
    QVector<Room>& getAllRooms();
};

#endif // ROOMMANAGER_H
