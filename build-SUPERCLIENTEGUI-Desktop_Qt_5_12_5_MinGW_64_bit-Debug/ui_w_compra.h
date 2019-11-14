/********************************************************************************
** Form generated from reading UI file 'w_compra.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_COMPRA_H
#define UI_W_COMPRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_COMPRA
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_COMPRA)
    {
        if (W_COMPRA->objectName().isEmpty())
            W_COMPRA->setObjectName(QString::fromUtf8("W_COMPRA"));
        W_COMPRA->resize(341, 366);
        centralwidget = new QWidget(W_COMPRA);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        W_COMPRA->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_COMPRA);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 341, 21));
        W_COMPRA->setMenuBar(menubar);
        statusbar = new QStatusBar(W_COMPRA);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        W_COMPRA->setStatusBar(statusbar);

        retranslateUi(W_COMPRA);

        QMetaObject::connectSlotsByName(W_COMPRA);
    } // setupUi

    void retranslateUi(QMainWindow *W_COMPRA)
    {
        W_COMPRA->setWindowTitle(QApplication::translate("W_COMPRA", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_COMPRA: public Ui_W_COMPRA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_COMPRA_H
