#ifndef ROOMWIDGET_H
#define ROOMWIDGET_H

#include <QWidget>
#include <QCloseEvent>
#include <QTcpSocket>
#include <QListWidgetItem>

namespace Ui {
class RoomWidget;
}

class RoomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RoomWidget(QTcpSocket* socket, QWidget *parent = 0);
    ~RoomWidget();

    QString getUsername() const;
    void setUsername(const QString &value);

    void addRoomList(QString roomname);
private:
    Ui::RoomWidget *ui;
    QTcpSocket* socket;
    QString username;

protected:
    virtual void closeEvent(QCloseEvent* event);
private slots:
    void on_btnCreateRoom_clicked();
    void on_btnRefleshRoom_clicked();
    void on_lwRoomList_itemDoubleClicked(QListWidgetItem *item);
};

#endif // ROOMWIDGET_H
