/********************************************************************************
** Form generated from reading UI file 'window_modify.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MODIFY_H
#define UI_WINDOW_MODIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_modify
{
public:
    QWidget *centralwidget;
    QPushButton *canasta;
    QPushButton *precio;
    QPushButton *back;
    QPushButton *porcentaje;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_modify)
    {
        if (window_modify->objectName().isEmpty())
            window_modify->setObjectName(QString::fromUtf8("window_modify"));
        window_modify->resize(482, 379);
        centralwidget = new QWidget(window_modify);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        canasta = new QPushButton(centralwidget);
        canasta->setObjectName(QString::fromUtf8("canasta"));
        canasta->setGeometry(QRect(20, 200, 441, 71));
        precio = new QPushButton(centralwidget);
        precio->setObjectName(QString::fromUtf8("precio"));
        precio->setGeometry(QRect(20, 20, 441, 71));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 290, 171, 41));
        porcentaje = new QPushButton(centralwidget);
        porcentaje->setObjectName(QString::fromUtf8("porcentaje"));
        porcentaje->setGeometry(QRect(20, 110, 441, 71));
        window_modify->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_modify);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 482, 17));
        window_modify->setMenuBar(menubar);
        statusbar = new QStatusBar(window_modify);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_modify->setStatusBar(statusbar);

        retranslateUi(window_modify);

        QMetaObject::connectSlotsByName(window_modify);
    } // setupUi

    void retranslateUi(QMainWindow *window_modify)
    {
        window_modify->setWindowTitle(QApplication::translate("window_modify", "MainWindow", nullptr));
        canasta->setText(QApplication::translate("window_modify", "Modificar canasta b\303\241sica", nullptr));
        precio->setText(QApplication::translate("window_modify", "Moodificar precio", nullptr));
        back->setText(QApplication::translate("window_modify", "Atr\303\241s", nullptr));
        porcentaje->setText(QApplication::translate("window_modify", "Modificar procentaje", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_modify: public Ui_window_modify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MODIFY_H