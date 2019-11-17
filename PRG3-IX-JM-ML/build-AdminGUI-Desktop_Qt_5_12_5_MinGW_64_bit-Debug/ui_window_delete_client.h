/********************************************************************************
** Form generated from reading UI file 'window_delete_client.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_DELETE_CLIENT_H
#define UI_WINDOW_DELETE_CLIENT_H

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

class Ui_window_delete_client
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *back;
    QPushButton *delete_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_delete_client)
    {
        if (window_delete_client->objectName().isEmpty())
            window_delete_client->setObjectName(QString::fromUtf8("window_delete_client"));
        window_delete_client->resize(363, 244);
        centralwidget = new QWidget(window_delete_client);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 231, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 321, 31));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 100, 321, 41));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 160, 151, 31));
        delete_2 = new QPushButton(centralwidget);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));
        delete_2->setGeometry(QRect(190, 160, 151, 31));
        window_delete_client->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_delete_client);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 363, 17));
        window_delete_client->setMenuBar(menubar);
        statusbar = new QStatusBar(window_delete_client);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_delete_client->setStatusBar(statusbar);

        retranslateUi(window_delete_client);

        QMetaObject::connectSlotsByName(window_delete_client);
    } // setupUi

    void retranslateUi(QMainWindow *window_delete_client)
    {
        window_delete_client->setWindowTitle(QApplication::translate("window_delete_client", "MainWindow", nullptr));
        label->setText(QApplication::translate("window_delete_client", "Eliminar cliente", nullptr));
        label_2->setText(QApplication::translate("window_delete_client", "Ingrese la cedula que desea borrar", nullptr));
        back->setText(QApplication::translate("window_delete_client", "Atras", nullptr));
        delete_2->setText(QApplication::translate("window_delete_client", "Eliminar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_delete_client: public Ui_window_delete_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_DELETE_CLIENT_H
