#include "clientsocket.h"
#include "sqldao.h"
#include <QDebug>
#include "roommanager.h"

ClientSocket::ClientSocket(QTcpSocket* socket, QObject *parent)
    : QObject(parent), socket(socket)
{
    QObject::connect(this->socket, SIGNAL(readyRead()), this, SLOT(onReadyread()));
    QObject::connect(this->socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
}

QString ClientSocket::getUsername() const
{
    return username;
}

void ClientSocket::setUsername(const QString &value)
{
    username = value;
}

void ClientSocket::regist()
{
    User user(protocol.getUsername(), protocol.getUserpwd());

    Protocol p;
    p.setUsername(user.getUsername());
    p.setUserpwd(user.getUserpwd());

    SqlDao sd;
    if(sd.insertUser(user)){
        //注册成功
        p.setType(Protocol::regist);
        p.setData("注册成功");
    }else{
        //注册失败
        p.setType(Protocol::registError);
        p.setData("注册失败");
    }

    this->writeToClient(p);
}

void ClientSocket::login()
{
    User user(protocol.getUsername(), protocol.getUserpwd());

    Protocol p;
    p.setUsername(user.getUsername());
    p.setUserpwd(user.getUserpwd());
    p.setType(Protocol::loginError);

    SqlDao sd;

    do{
        if(!sd.selectUser(user)){
            p.setData("无此用户");
            break;
        }

//        if(user.getOnline()){
 //           p.setData("此用户已经在线");
  //          break;
   //     }

        if(user.getUserpwd() != p.getUserpwd()){
            p.setData("密码错误");
            break;
        }

        //登录成功
        p.setType(Protocol::login);
        p.setData("登录成功");

        user.setOnline(true);
        sd.updateUser(user);

        this->username = protocol.getUsername();
    }while(0);

    this->writeToClient(p);
}

void ClientSocket::quit()
{
    User user(protocol.getUsername());
    SqlDao sd;

    if(!sd.selectUser(user)){
        return;
    }

    user.setOnline(false);
    sd.updateUser(user);

    Protocol p;
    p.setType(Protocol::quit);
    p.setUsername(user.getUsername());

    this->writeToClient(p);

    this->username.clear();
}

void ClientSocket::createRoom()
{
    Room room(protocol.getUsername());
    room.insertUser(this);

    RoomManager::getInstance()->insertRoom(room);

    Protocol p;
    p.setType(Protocol::createRoom);
    p.setRoomname(room.getRoomname());

    this->writeToClient(p);
}

void ClientSocket::quitRoom()
{
    Room* room = RoomManager::getInstance()->selectRoom(protocol.getRoomname());
    if(room == NULL)    return;

    room->removeUser(this);
    Protocol p;
    p.setType(Protocol::quitRoom);

    this->writeToClient(p);

    //刷新用户
    QVector<ClientSocket *>& users = room->getAllUsers();
    QVector<ClientSocket *>::iterator it;
    QStringList list;
    for(it = users.begin(); it != users.end(); ++it){
        list.push_back((*it)->getUsername());
    }

    p.clear();
    p.setType(Protocol::refleshUser);
    p.setRoomUsers(list);

    for(it = users.begin(); it != users.end(); ++it){
        (*it)->writeToClient(p);
    }

    p.clear();
    p.setType(Protocol::quitRoom);
    /*如果房主退出，则其他用户强制退出*/
    if(room->getRoomname() == protocol.getUsername()){
        //房主退出
        QVector<ClientSocket*>& users = room->getAllUsers();
        QVector<ClientSocket*>::iterator it;
        for(it = users.begin(); it != users.end();){
            (*it)->writeToClient(p);
            users.erase(it);
        }

        RoomManager::getInstance()->removeRoom(protocol.getRoomname());
    }
}

void ClientSocket::refleshRoom()
{
    Protocol p;
    p.setType(Protocol::refleshRoom);

    QVector<Room>& rooms = RoomManager::getInstance()->getAllRooms();
    QVector<Room>::iterator it;
    for(it = rooms.begin(); it != rooms.end(); ++it){
        p.setRoomname(it->getRoomname());
        this->writeToClient(p);
    }
}

void ClientSocket::joinRoom()
{
    Room* room = RoomManager::getInstance()->selectRoom(protocol.getRoomname());
    if(room == NULL)    return;

    room->insertUser(this);

    Protocol p;
    p.setType(Protocol::joinRoom);
    p.setRoomname(protocol.getRoomname());
    p.setUsername(protocol.getUsername());

    this->writeToClient(p);

    //刷新用户
    QVector<ClientSocket *>& users = room->getAllUsers();
    QVector<ClientSocket *>::iterator it;
    QStringList list;
    for(it = users.begin(); it != users.end(); ++it){
        list.push_back((*it)->getUsername());
    }

    p.clear();
    p.setType(Protocol::refleshUser);
    p.setRoomUsers(list);

    for(it = users.begin(); it != users.end(); ++it){
        (*it)->writeToClient(p);
    }
}

void ClientSocket::chat()
{
    Room* room = RoomManager::getInstance()->selectRoom(protocol.getRoomname());
    if(room == NULL)    return;

    Protocol p;
    p.setType(Protocol::chat);
    p.setUsername(protocol.getUsername());
    p.setRoomname(protocol.getRoomname());
    p.setData(protocol.getData());

    QVector<ClientSocket*> users = room->getAllUsers();
    QVector<ClientSocket*>::iterator it;
    for(it = users.begin(); it != users.end(); ++it){
        (*it)->writeToClient(p);
    }
}

void ClientSocket::handleStream()
{
    while(1){
        if(this->protocol.getLen() == 0){//定长包拿完了吗？
            //没拿完
            if(this->buffer.size() < Protocol::size()){
                //定长包不够拿
                break;
            }

            //获取定长部分的内容
            protocol.setType(*(Protocol::Type*)buffer.data());
            buffer.remove(0, sizeof(Protocol::Type));//裁剪
            protocol.setLen(*(quint32*)buffer.data());
            buffer.remove(0, sizeof(quint32));
        }else{
            //定长包拿完了
            if(this->buffer.size() < (int)protocol.getLen()){
                //变长包不够拿
                break;
            }

            //变长部分的包够
            QByteArray json(this->buffer.data(), protocol.getLen());
            protocol.fromJson(json);

            this->buffer.remove(0, protocol.getLen());

            //一个完整的包处理完毕
            handleProtocol();
            protocol.clear();
        }
    }
}

void ClientSocket::handleProtocol()
{
    switch(protocol.getType()){
    case Protocol::refleshUser:
        break;
    case Protocol::chat:
        this->chat();
        break;
    case Protocol::joinRoom:
        this->joinRoom();
        break;
    case Protocol::refleshRoom:
        this->refleshRoom();
        break;
    case Protocol::quitRoom:
        this->quitRoom();
        break;
    case Protocol::createRoom:
        this->createRoom();
        break;
    case Protocol::quit:
        this->quit();
        break;
    case Protocol::none:
        break;
    case Protocol::regist:
        this->regist();
        break;
    case Protocol::login:
        this->login();
        break;
    case Protocol::registError:
        break;
    case Protocol::loginError:
        break;
    default:
        break;
    }
}

void ClientSocket::writeToClient(Protocol &p)
{
    socket->write(p.toArray());
}

void ClientSocket::onReadyread()
{
    this->buffer += socket->readAll();

    handleStream();
}


void ClientSocket::onDisconnected()
{
    /*1.断开信号与槽*/
    QObject::disconnect(this->socket,0,0,0);

    /*2.套接字回收*/
    this->socket->deleteLater();//回收资源
    /*3.从管理对象中将此cs删除掉*/

    /*4.套接字管理对象回收*/
    this->deleteLater();//回收资源
}
