/********************************************************************************
** Form generated from reading UI file 'wlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WLOGIN_H
#define UI_WLOGIN_H

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

class Ui_WLogin
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WLogin)
    {
        if (WLogin->objectName().isEmpty())
            WLogin->setObjectName(QString::fromUtf8("WLogin"));
        WLogin->resize(279, 259);
        centralwidget = new QWidget(WLogin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 121, 41));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 70, 141, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 120, 141, 31));
        WLogin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WLogin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 279, 21));
        WLogin->setMenuBar(menubar);
        statusbar = new QStatusBar(WLogin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WLogin->setStatusBar(statusbar);

        retranslateUi(WLogin);

        QMetaObject::connectSlotsByName(WLogin);
    } // setupUi

    void retranslateUi(QMainWindow *WLogin)
    {
        WLogin->setWindowTitle(QApplication::translate("WLogin", "WLogin", nullptr));
        label->setText(QApplication::translate("WLogin", "DIGITE SU NUM DE CED", nullptr));
        pushButton->setText(QApplication::translate("WLogin", "LOGING", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WLogin: public Ui_WLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WLOGIN_H
