/********************************************************************************
** Form generated from reading UI file 'w_menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_MENU_H
#define UI_W_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_MENU
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_MENU)
    {
        if (W_MENU->objectName().isEmpty())
            W_MENU->setObjectName(QString::fromUtf8("W_MENU"));
        W_MENU->resize(276, 360);
        centralwidget = new QWidget(W_MENU);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 231, 51));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 70, 231, 51));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 130, 231, 51));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 190, 231, 51));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 250, 231, 51));
        W_MENU->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_MENU);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 276, 21));
        W_MENU->setMenuBar(menubar);
        statusbar = new QStatusBar(W_MENU);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        W_MENU->setStatusBar(statusbar);

        retranslateUi(W_MENU);

        QMetaObject::connectSlotsByName(W_MENU);
    } // setupUi

    void retranslateUi(QMainWindow *W_MENU)
    {
        W_MENU->setWindowTitle(QApplication::translate("W_MENU", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("W_MENU", "1. Consultar un precio", nullptr));
        pushButton_2->setText(QApplication::translate("W_MENU", "2. Consultar si un producto es de la canasta", nullptr));
        pushButton_3->setText(QApplication::translate("W_MENU", "3. Consultar el % impuesto de un producto", nullptr));
        pushButton_4->setText(QApplication::translate("W_MENU", "4. Comprar", nullptr));
        pushButton_5->setText(QApplication::translate("W_MENU", "5. Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_MENU: public Ui_W_MENU {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_MENU_H
