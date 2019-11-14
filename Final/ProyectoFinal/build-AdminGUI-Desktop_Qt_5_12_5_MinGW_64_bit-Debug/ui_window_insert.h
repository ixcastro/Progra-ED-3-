/********************************************************************************
** Form generated from reading UI file 'window_insert.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_INSERT_H
#define UI_WINDOW_INSERT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_insert
{
public:
    QWidget *centralwidget;
    QPushButton *back;
    QPushButton *insertarMarca;
    QPushButton *insertarProd;
    QPushButton *insertarCliente;
    QPushButton *insertarPas;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_insert)
    {
        if (window_insert->objectName().isEmpty())
            window_insert->setObjectName(QString::fromUtf8("window_insert"));
        window_insert->resize(479, 469);
        centralwidget = new QWidget(window_insert);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 380, 171, 41));
        insertarMarca = new QPushButton(centralwidget);
        insertarMarca->setObjectName(QString::fromUtf8("insertarMarca"));
        insertarMarca->setGeometry(QRect(20, 200, 441, 71));
        insertarProd = new QPushButton(centralwidget);
        insertarProd->setObjectName(QString::fromUtf8("insertarProd"));
        insertarProd->setGeometry(QRect(20, 110, 441, 71));
        insertarCliente = new QPushButton(centralwidget);
        insertarCliente->setObjectName(QString::fromUtf8("insertarCliente"));
        insertarCliente->setGeometry(QRect(20, 290, 441, 71));
        insertarPas = new QPushButton(centralwidget);
        insertarPas->setObjectName(QString::fromUtf8("insertarPas"));
        insertarPas->setGeometry(QRect(20, 20, 441, 71));
        window_insert->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_insert);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 479, 17));
        window_insert->setMenuBar(menubar);
        statusbar = new QStatusBar(window_insert);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_insert->setStatusBar(statusbar);

        retranslateUi(window_insert);

        QMetaObject::connectSlotsByName(window_insert);
    } // setupUi

    void retranslateUi(QMainWindow *window_insert)
    {
        window_insert->setWindowTitle(QApplication::translate("window_insert", "MainWindow", nullptr));
        back->setText(QApplication::translate("window_insert", "Atr\303\241s", nullptr));
        insertarMarca->setText(QApplication::translate("window_insert", "Insertar marca", nullptr));
        insertarProd->setText(QApplication::translate("window_insert", "Insertar producto", nullptr));
        insertarCliente->setText(QApplication::translate("window_insert", "Insertar cliente", nullptr));
        insertarPas->setText(QApplication::translate("window_insert", "Insertar pasillo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_insert: public Ui_window_insert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_INSERT_H
