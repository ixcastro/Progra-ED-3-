/********************************************************************************
** Form generated from reading UI file 'w_pasillos.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_PASILLOS_H
#define UI_W_PASILLOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_PASILLOS
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_PASILLOS)
    {
        if (W_PASILLOS->objectName().isEmpty())
            W_PASILLOS->setObjectName(QString::fromUtf8("W_PASILLOS"));
        W_PASILLOS->resize(361, 384);
        centralwidget = new QWidget(W_PASILLOS);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        W_PASILLOS->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_PASILLOS);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 361, 21));
        W_PASILLOS->setMenuBar(menubar);
        statusbar = new QStatusBar(W_PASILLOS);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        W_PASILLOS->setStatusBar(statusbar);

        retranslateUi(W_PASILLOS);

        QMetaObject::connectSlotsByName(W_PASILLOS);
    } // setupUi

    void retranslateUi(QMainWindow *W_PASILLOS)
    {
        W_PASILLOS->setWindowTitle(QApplication::translate("W_PASILLOS", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_PASILLOS: public Ui_W_PASILLOS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_PASILLOS_H
