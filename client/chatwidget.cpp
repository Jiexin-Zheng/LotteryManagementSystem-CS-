#include "chatwidget.h"
#include "ui_chatwidget.h"
#include "protocol.h"

ChatWidget::ChatWidget(QTcpSocket* socket, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWidget),
    socket(socket)
{
    ui->setupUi(this);
}

ChatWidget::~ChatWidget()
{
    delete ui;
}

QString ChatWidget::getUsername() const
{
    return username;
}

void ChatWidget::setUsername(const QString &value)
{
    ui->lwUser->addItem(value);
    ui->lbUsername->setText(value);
    username = value;
}

QString ChatWidget::getRoomname() const
{
    return roomname;
}

void ChatWidget::setRoomname(const QString &value)
{
    ui->lbRoomname->setText(value);
    roomname = value;
}

void ChatWidget::setRoomUsers(QStringList list)
{
    ui->lwUser->clear();
    ui->lwUser->addItems(list);
}

void ChatWidget::appendChatText(QString text)
{
    ui->tbShow->append(text);
}

void ChatWidget::closeEvent(QCloseEvent *event)
{
    Protocol p;
    p.setUsername(this->username);
    p.setRoomname(this->roomname);
    p.setType(Protocol::quitRoom);

    socket->write(p.toArray());

    event->ignore();
}

void ChatWidget::on_leInput_returnPressed()
{
    QString text = ui->leInput->text();
    ui->leInput->clear();

    Protocol p;
    p.setType(Protocol::chat);
    p.setUsername(this->username);
    p.setRoomname(this->roomname);
    p.setData(text);

    socket->write(p.toArray());
}
