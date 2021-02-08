#include "roomwidget.h"
#include "ui_roomwidget.h"
#include "protocol.h"

RoomWidget::RoomWidget(QTcpSocket* socket, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoomWidget),
  socket(socket)
{
    ui->setupUi(this);
}

RoomWidget::~RoomWidget()
{
    delete ui;
}

QString RoomWidget::getUsername() const
{
    return username;
}

void RoomWidget::setUsername(const QString &value)
{
    username = value;
    ui->lbUserame->setText(this->username);
}

void RoomWidget::addRoomList(QString roomname)
{
    ui->lwRoomList->addItem(roomname);
}

void RoomWidget::closeEvent(QCloseEvent *event)
{
    Protocol p;
    p.setType(Protocol::quit);
    p.setUsername(this->username);

    socket->write(p.toArray());

    event->ignore();
}

void RoomWidget::on_btnCreateRoom_clicked()
{
    Protocol p;
    p.setType(Protocol::createRoom);
    p.setUsername(this->username);

    socket->write(p.toArray());

}

void RoomWidget::on_btnRefleshRoom_clicked()
{
    ui->lwRoomList->clear();

    Protocol p;
    p.setType(Protocol::refleshRoom);

    socket->write(p.toArray());
}

void RoomWidget::on_lwRoomList_itemDoubleClicked(QListWidgetItem *item)
{
    QString roomname = item->text();

    Protocol p;
    p.setType(Protocol::joinRoom);
    p.setUsername(this->username);
    p.setRoomname(roomname);

    socket->write(p.toArray());
}
