/********************************************************************************
** Form generated from reading UI file 'window_delete.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_DELETE_H
#define UI_WINDOW_DELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_delete
{
public:
    QWidget *centralwidget;
    QPushButton *insertarMarca;
    QPushButton *insertarCliente;
    QPushButton *back;
    QPushButton *insertarProd;
    QPushButton *insertarPas;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_delete)
    {
        if (window_delete->objectName().isEmpty())
            window_delete->setObjectName(QString::fromUtf8("window_delete"));
        window_delete->resize(483, 491);
        centralwidget = new QWidget(window_delete);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        insertarMarca = new QPushButton(centralwidget);
        insertarMarca->setObjectName(QString::fromUtf8("insertarMarca"));
        insertarMarca->setGeometry(QRect(20, 210, 441, 71));
        insertarCliente = new QPushButton(centralwidget);
        insertarCliente->setObjectName(QString::fromUtf8("insertarCliente"));
        insertarCliente->setGeometry(QRect(20, 300, 441, 71));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 390, 171, 41));
        insertarProd = new QPushButton(centralwidget);
        insertarProd->setObjectName(QString::fromUtf8("insertarProd"));
        insertarProd->setGeometry(QRect(20, 120, 441, 71));
        insertarPas = new QPushButton(centralwidget);
        insertarPas->setObjectName(QString::fromUtf8("insertarPas"));
        insertarPas->setGeometry(QRect(20, 30, 441, 71));
        window_delete->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_delete);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 483, 17));
        window_delete->setMenuBar(menubar);
        statusbar = new QStatusBar(window_delete);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_delete->setStatusBar(statusbar);

        retranslateUi(window_delete);

        QMetaObject::connectSlotsByName(window_delete);
    } // setupUi

    void retranslateUi(QMainWindow *window_delete)
    {
        window_delete->setWindowTitle(QApplication::translate("window_delete", "MainWindow", nullptr));
        insertarMarca->setText(QApplication::translate("window_delete", "Eliminar marca", nullptr));
        insertarCliente->setText(QApplication::translate("window_delete", "Eliminar cliente", nullptr));
        back->setText(QApplication::translate("window_delete", "Atr\303\241s", nullptr));
        insertarProd->setText(QApplication::translate("window_delete", "Eliminar producto", nullptr));
        insertarPas->setText(QApplication::translate("window_delete", "Eliminar pasillo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_delete: public Ui_window_delete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_DELETE_H
