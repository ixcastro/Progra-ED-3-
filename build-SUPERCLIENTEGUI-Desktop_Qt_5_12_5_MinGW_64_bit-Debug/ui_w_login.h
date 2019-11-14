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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_LOGIN
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_LOGIN)
    {
        if (W_LOGIN->objectName().isEmpty())
            W_LOGIN->setObjectName(QString::fromUtf8("W_LOGIN"));
        W_LOGIN->resize(278, 259);
        centralwidget = new QWidget(W_LOGIN);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 131, 51));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 70, 161, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 130, 161, 51));
        W_LOGIN->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_LOGIN);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 278, 21));
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
        label->setText(QApplication::translate("W_LOGIN", "DIGITE SU NUM DE CED :", nullptr));
        pushButton->setText(QApplication::translate("W_LOGIN", "LOGING", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_LOGIN: public Ui_W_LOGIN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_LOGIN_H
