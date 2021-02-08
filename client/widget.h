#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QByteArray>
#include "protocol.h"

#include "roomwidget.h"
#include "chatwidget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_btnRegister_clicked();
    void onReadyread();
    void on_btnLogin_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket* socket;
    QByteArray buffer;
    Protocol protocol;

    RoomWidget* rw;
    ChatWidget* cw;

    void handleStream();
    void handleProtocol();
    void refleshUser();
};

#endif // WIDGET_H
