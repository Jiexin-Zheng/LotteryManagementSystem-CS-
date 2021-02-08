#include "roommanager.h"

RoomManager::RoomManager()
{

}

RoomManager* RoomManager::instance = new RoomManager;

RoomManager *RoomManager::getInstance()
{
    return instance;
}

void RoomManager::insertRoom(Room room)
{
    rooms.push_back(room);
}

void RoomManager::removeRoom(QString roomname)
{
    QVector<Room>::iterator it;
    for(it = rooms.begin(); it != rooms.end(); ++it){
        if(it->getRoomname() == roomname){
            rooms.erase(it);
            break;
        }
    }

    return;
}

Room* RoomManager::selectRoom(QString roomname)
{
    QVector<Room>::iterator it;
    for(it = rooms.begin(); it != rooms.end(); ++it){
        if(it->getRoomname() == roomname){
            return it;
        }
    }

    return NULL;
}

QVector<Room>& RoomManager::getAllRooms()
{
    return rooms;
}
