#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QCloseEvent>

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidget(QTcpSocket* socket, QWidget *parent = 0);
    ~ChatWidget();

    QString getUsername() const;
    void setUsername(const QString &value);

    QString getRoomname() const;
    void setRoomname(const QString &value);

    void setRoomUsers(QStringList list);
    void appendChatText(QString text);

private:
    Ui::ChatWidget *ui;
    QString username;
    QString roomname;
    QTcpSocket* socket;

protected:
    virtual void closeEvent(QCloseEvent* event);
private slots:
    void on_leInput_returnPressed();
};

#endif // CHATWIDGET_H
