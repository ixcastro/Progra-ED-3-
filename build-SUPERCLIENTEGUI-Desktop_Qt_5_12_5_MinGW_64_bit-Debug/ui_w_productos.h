/********************************************************************************
** Form generated from reading UI file 'w_productos.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_PRODUCTOS_H
#define UI_W_PRODUCTOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_Productos
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_Productos)
    {
        if (W_Productos->objectName().isEmpty())
            W_Productos->setObjectName(QString::fromUtf8("W_Productos"));
        W_Productos->resize(359, 378);
        centralwidget = new QWidget(W_Productos);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        W_Productos->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_Productos);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 359, 21));
        W_Productos->setMenuBar(menubar);
        statusbar = new QStatusBar(W_Productos);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        W_Productos->setStatusBar(statusbar);

        retranslateUi(W_Productos);

        QMetaObject::connectSlotsByName(W_Productos);
    } // setupUi

    void retranslateUi(QMainWindow *W_Productos)
    {
        W_Productos->setWindowTitle(QApplication::translate("W_Productos", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Productos: public Ui_W_Productos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_PRODUCTOS_H
