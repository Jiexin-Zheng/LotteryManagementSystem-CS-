/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbUsername;
    QLineEdit *leUsername;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbUserpwd;
    QLineEdit *leUserpwd;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnRegister;
    QPushButton *btnLogin;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(233, 99);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbUsername = new QLabel(Widget);
        lbUsername->setObjectName(QStringLiteral("lbUsername"));
        lbUsername->setMinimumSize(QSize(54, 12));
        lbUsername->setMaximumSize(QSize(54, 12));

        horizontalLayout->addWidget(lbUsername);

        leUsername = new QLineEdit(Widget);
        leUsername->setObjectName(QStringLiteral("leUsername"));

        horizontalLayout->addWidget(leUsername);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbUserpwd = new QLabel(Widget);
        lbUserpwd->setObjectName(QStringLiteral("lbUserpwd"));
        lbUserpwd->setMinimumSize(QSize(54, 12));
        lbUserpwd->setMaximumSize(QSize(54, 12));

        horizontalLayout_2->addWidget(lbUserpwd);

        leUserpwd = new QLineEdit(Widget);
        leUserpwd->setObjectName(QStringLiteral("leUserpwd"));

        horizontalLayout_2->addWidget(leUserpwd);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnRegister = new QPushButton(Widget);
        btnRegister->setObjectName(QStringLiteral("btnRegister"));

        horizontalLayout_3->addWidget(btnRegister);

        btnLogin = new QPushButton(Widget);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));

        horizontalLayout_3->addWidget(btnLogin);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        lbUsername->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        lbUserpwd->setText(QApplication::translate("Widget", "\345\257\206\347\240\201", Q_NULLPTR));
        btnRegister->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", Q_NULLPTR));
        btnLogin->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
