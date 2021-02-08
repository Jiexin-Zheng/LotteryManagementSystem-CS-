#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include "protocol.h"
#include <QByteArray>

class ClientSocket : public QObject
{
    Q_OBJECT
private:
    QTcpSocket* socket;
    QByteArray buffer;
    Protocol protocol;
    QString username;
    
    void regist();
    void login();
    void quit();
    void createRoom();
    void quitRoom();
    void refleshRoom();
    void joinRoom();
    void chat();
    
    void handleStream(void);
    void handleProtocol(void);
    
public:
    explicit ClientSocket(QTcpSocket* socket, QObject *parent = nullptr);

    void writeToClient(Protocol& p);
    QString getUsername() const;
    void setUsername(const QString &value);

signals:

public slots:
    void onReadyread();
    void onDisconnected();
};

#endif // CLIENTSOCKET_H
