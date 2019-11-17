/********************************************************************************
** Form generated from reading UI file 'window_query.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_QUERY_H
#define UI_WINDOW_QUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_query
{
public:
    QWidget *centralwidget;
    QPushButton *insertarPas;
    QPushButton *back;
    QPushButton *insertarProd;
    QPushButton *insertarMarca;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_query)
    {
        if (window_query->objectName().isEmpty())
            window_query->setObjectName(QString::fromUtf8("window_query"));
        window_query->resize(485, 396);
        centralwidget = new QWidget(window_query);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        insertarPas = new QPushButton(centralwidget);
        insertarPas->setObjectName(QString::fromUtf8("insertarPas"));
        insertarPas->setGeometry(QRect(20, 30, 441, 71));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 300, 171, 41));
        insertarProd = new QPushButton(centralwidget);
        insertarProd->setObjectName(QString::fromUtf8("insertarProd"));
        insertarProd->setGeometry(QRect(20, 120, 441, 71));
        insertarMarca = new QPushButton(centralwidget);
        insertarMarca->setObjectName(QString::fromUtf8("insertarMarca"));
        insertarMarca->setGeometry(QRect(20, 210, 441, 71));
        window_query->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_query);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 485, 17));
        window_query->setMenuBar(menubar);
        statusbar = new QStatusBar(window_query);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_query->setStatusBar(statusbar);

        retranslateUi(window_query);

        QMetaObject::connectSlotsByName(window_query);
    } // setupUi

    void retranslateUi(QMainWindow *window_query)
    {
        window_query->setWindowTitle(QApplication::translate("window_query", "MainWindow", nullptr));
        insertarPas->setText(QApplication::translate("window_query", "Consultar precio", nullptr));
        back->setText(QApplication::translate("window_query", "Atras", nullptr));
        insertarProd->setText(QApplication::translate("window_query", "Consultar porcentaje", nullptr));
        insertarMarca->setText(QApplication::translate("window_query", "Consultar canasta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_query: public Ui_window_query {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_QUERY_H
