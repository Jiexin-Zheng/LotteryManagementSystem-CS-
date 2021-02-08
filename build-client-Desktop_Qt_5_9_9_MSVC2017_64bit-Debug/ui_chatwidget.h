/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbRoomname;
    QLabel *lbUsername;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *tbShow;
    QListWidget *lwUser;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leInput;
    QPushButton *btnSend;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName(QStringLiteral("ChatWidget"));
        ChatWidget->resize(665, 386);
        verticalLayout = new QVBoxLayout(ChatWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbRoomname = new QLabel(ChatWidget);
        lbRoomname->setObjectName(QStringLiteral("lbRoomname"));

        horizontalLayout_3->addWidget(lbRoomname);

        lbUsername = new QLabel(ChatWidget);
        lbUsername->setObjectName(QStringLiteral("lbUsername"));

        horizontalLayout_3->addWidget(lbUsername);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tbShow = new QTextBrowser(ChatWidget);
        tbShow->setObjectName(QStringLiteral("tbShow"));

        horizontalLayout_2->addWidget(tbShow);

        lwUser = new QListWidget(ChatWidget);
        lwUser->setObjectName(QStringLiteral("lwUser"));
        lwUser->setMinimumSize(QSize(200, 0));
        lwUser->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(lwUser);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        leInput = new QLineEdit(ChatWidget);
        leInput->setObjectName(QStringLiteral("leInput"));

        horizontalLayout->addWidget(leInput);

        btnSend = new QPushButton(ChatWidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));

        horizontalLayout->addWidget(btnSend);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChatWidget);

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        ChatWidget->setWindowTitle(QApplication::translate("ChatWidget", "Form", Q_NULLPTR));
        lbRoomname->setText(QApplication::translate("ChatWidget", "TextLabel", Q_NULLPTR));
        lbUsername->setText(QApplication::translate("ChatWidget", "TextLabel", Q_NULLPTR));
        btnSend->setText(QApplication::translate("ChatWidget", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
