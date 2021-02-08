#include "widget.h"
#include "ui_widget.h"
#include <QTcpSocket>
#include <QDebug>
#include "clientsocket.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    server(new QTcpServer(this))
{
    ui->setupUi(this);

    server->listen(QHostAddress::Any, 12000);

    QObject::connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onNewConnection()
{
    QTcpSocket* socket = NULL;

    while((socket = server->nextPendingConnection()) != NULL){
        ClientSocket* cs = new ClientSocket(socket, this);
        Q_UNUSED(cs);
    }
}
