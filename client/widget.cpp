#include "widget.h"
#include "ui_widget.h"
#include "protocol.h"
#include <QMessageBox>
#include <QDebug>
#include <QTime>
#include <QByteArray>

/*
 * 登录成功后，界面跳转
 * 退出此界面，则回到登录界面，服务器需要将此用户的在线状态改为离线
*/

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    socket(new QTcpSocket(this)),
    rw(new RoomWidget(socket)),
    cw(new ChatWidget(socket))
{
    ui->setupUi(this);

    socket->connectToHost("192.168.3.42", 12000);

    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyread()));
}

Widget::~Widget()
{
    delete ui;
    delete rw;
    delete cw;
}

void Widget::onReadyread()
{
    this->buffer += socket->readAll();

    handleStream();
}

void Widget::on_btnRegister_clicked()
{
    QString username = ui->leUsername->text();
    QString userpwd = ui->leUserpwd->text();

    ui->leUsername->clear();
    ui->leUserpwd->clear();

    //创建协议包
    Protocol p;
    p.clear();
    p.setType(Protocol::regist);
    p.setUsername(username);
    p.setUserpwd(userpwd);

    //发送协议包
    socket->write(p.toArray());
}

void Widget::on_btnLogin_clicked()
{
    QString username = ui->leUsername->text();
    QString userpwd = ui->leUserpwd->text();

    ui->leUsername->clear();
    ui->leUserpwd->clear();

    //创建协议包
    Protocol p;
    p.clear();
    p.setType(Protocol::login);
    p.setUsername(username);
    p.setUserpwd(userpwd);

    //发送协议包
    socket->write(p.toArray());
}

void Widget::handleStream()
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

void Widget::handleProtocol()
{
    switch(protocol.getType()){
    case Protocol::chat:
        cw->appendChatText(protocol.getUsername() + " : " + protocol.getData());
        break;
    case Protocol::refleshUser:
        this->refleshUser();
        break;
    case Protocol::joinRoom:
        rw->hide();
        cw->setUsername(rw->getUsername());
        cw->setRoomname(protocol.getRoomname());
        cw->show();

        break;
    case Protocol::refleshRoom:
        rw->addRoomList(protocol.getRoomname());
        break;
    case Protocol::quitRoom:
        rw->show();
        cw->hide();
        break;
    case Protocol::createRoom:
        QMessageBox::information(this,"房间信息","创建房间成功");

        rw->hide();
        cw->setUsername(rw->getUsername());
        cw->setRoomname(protocol.getRoomname());
        cw->show();

        break;
    case Protocol::quit:
        rw->hide();
        this->show();
        break;
    case Protocol::none:
        break;
    case Protocol::regist:
        QMessageBox::information(this,"注册信息",protocol.getData());
        break;
    case Protocol::login:
        QMessageBox::information(this,"登录信息",protocol.getData());
        this->hide();
        rw->setUsername(protocol.getUsername());
        rw->show();
        break;
    case Protocol::registError:
        QMessageBox::warning(this,"注册信息",protocol.getData());
        break;
    case Protocol::loginError:
        QMessageBox::warning(this,"登录信息",protocol.getData());
        break;
    default:
        break;
    }
}

void Widget::refleshUser()
{
    QStringList list = protocol.getRoomUsers();
    cw->setRoomUsers(list);
}
