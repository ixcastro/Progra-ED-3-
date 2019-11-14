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

class Ui_W_LOGIN
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_LOGIN)
    {
        if (W_LOGIN->objectName().isEmpty())
            W_LOGIN->setObjectName(QString::fromUtf8("W_LOGIN"));
        W_LOGIN->resize(800, 600);
        centralwidget = new QWidget(W_LOGIN);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        W_LOGIN->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_LOGIN);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        W_LOGIN->setMenuBar(menubar);
        statusbar = new QStatusBar(W_LOGIN);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        W_LOGIN->setStatusBar(statusbar);

        retranslateUi(W_LOGIN);

        QMetaObject::connectSlotsByName(W_LOGIN);
    } // setupUi

    void retranslateUi(QMainWindow *W_LOGIN)
    {
        W_LOGIN->setWindowTitle(QApplication::translate("W_LOGIN", "W_LOGIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_LOGIN: public Ui_W_LOGIN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_LOGIN_H
