/********************************************************************************
** Form generated from reading UI file 'ventanamenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAMENU_H
#define UI_VENTANAMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaMenu
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaMenu)
    {
        if (VentanaMenu->objectName().isEmpty())
            VentanaMenu->setObjectName(QString::fromUtf8("VentanaMenu"));
        VentanaMenu->resize(800, 600);
        menubar = new QMenuBar(VentanaMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        VentanaMenu->setMenuBar(menubar);
        centralwidget = new QWidget(VentanaMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        VentanaMenu->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(VentanaMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        VentanaMenu->setStatusBar(statusbar);

        retranslateUi(VentanaMenu);

        QMetaObject::connectSlotsByName(VentanaMenu);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaMenu)
    {
        VentanaMenu->setWindowTitle(QApplication::translate("VentanaMenu", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaMenu: public Ui_VentanaMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAMENU_H
