/********************************************************************************
** Form generated from reading UI file 'w_login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_LOGIN_H
#define UI_W_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_Login
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_Login)
    {
        if (W_Login->objectName().isEmpty())
            W_Login->setObjectName(QString::fromUtf8("W_Login"));
        W_Login->resize(800, 600);
        centralwidget = new QWidget(W_Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        W_Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_Login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        W_Login->setMenuBar(menubar);
        statusbar = new QStatusBar(W_Login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        W_Login->setStatusBar(statusbar);

        retranslateUi(W_Login);

        QMetaObject::connectSlotsByName(W_Login);
    } // setupUi

    void retranslateUi(QMainWindow *W_Login)
    {
        W_Login->setWindowTitle(QApplication::translate("W_Login", "W_Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Login: public Ui_W_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_LOGIN_H
