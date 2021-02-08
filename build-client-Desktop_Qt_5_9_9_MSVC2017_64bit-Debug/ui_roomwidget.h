/********************************************************************************
** Form generated from reading UI file 'roomwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMWIDGET_H
#define UI_ROOMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *lbUserame;
    QHBoxLayout *horizontalLayout;
    QListWidget *lwRoomList;
    QVBoxLayout *verticalLayout;
    QPushButton *btnRefleshRoom;
    QPushButton *btnCreateRoom;

    void setupUi(QWidget *RoomWidget)
    {
        if (RoomWidget->objectName().isEmpty())
            RoomWidget->setObjectName(QStringLiteral("RoomWidget"));
        RoomWidget->resize(694, 545);
        verticalLayout_2 = new QVBoxLayout(RoomWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lbUserame = new QLabel(RoomWidget);
        lbUserame->setObjectName(QStringLiteral("lbUserame"));
        lbUserame->setMinimumSize(QSize(54, 12));
        lbUserame->setMaximumSize(QSize(54, 12));

        verticalLayout_2->addWidget(lbUserame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lwRoomList = new QListWidget(RoomWidget);
        lwRoomList->setObjectName(QStringLiteral("lwRoomList"));

        horizontalLayout->addWidget(lwRoomList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnRefleshRoom = new QPushButton(RoomWidget);
        btnRefleshRoom->setObjectName(QStringLiteral("btnRefleshRoom"));

        verticalLayout->addWidget(btnRefleshRoom);

        btnCreateRoom = new QPushButton(RoomWidget);
        btnCreateRoom->setObjectName(QStringLiteral("btnCreateRoom"));

        verticalLayout->addWidget(btnCreateRoom);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(RoomWidget);

        QMetaObject::connectSlotsByName(RoomWidget);
    } // setupUi

    void retranslateUi(QWidget *RoomWidget)
    {
        RoomWidget->setWindowTitle(QApplication::translate("RoomWidget", "Form", Q_NULLPTR));
        lbUserame->setText(QString());
        btnRefleshRoom->setText(QApplication::translate("RoomWidget", "\345\210\267\346\226\260\346\210\277\351\227\264", Q_NULLPTR));
        btnCreateRoom->setText(QApplication::translate("RoomWidget", "\345\210\233\345\273\272\346\210\277\351\227\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RoomWidget: public Ui_RoomWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMWIDGET_H
