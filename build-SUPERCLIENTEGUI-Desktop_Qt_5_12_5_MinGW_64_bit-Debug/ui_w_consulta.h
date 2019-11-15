/********************************************************************************
** Form generated from reading UI file 'w_consulta.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_CONSULTA_H
#define UI_W_CONSULTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_CONSULTA
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_CONSULTA)
    {
        if (W_CONSULTA->objectName().isEmpty())
            W_CONSULTA->setObjectName(QString::fromUtf8("W_CONSULTA"));
        W_CONSULTA->resize(261, 262);
        centralwidget = new QWidget(W_CONSULTA);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 221, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 70, 221, 41));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 120, 221, 41));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 170, 221, 41));
        W_CONSULTA->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_CONSULTA);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 261, 21));
        W_CONSULTA->setMenuBar(menubar);
        statusbar = new QStatusBar(W_CONSULTA);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        W_CONSULTA->setStatusBar(statusbar);

        retranslateUi(W_CONSULTA);

        QMetaObject::connectSlotsByName(W_CONSULTA);
    } // setupUi

    void retranslateUi(QMainWindow *W_CONSULTA)
    {
        W_CONSULTA->setWindowTitle(QApplication::translate("W_CONSULTA", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("W_CONSULTA", "1. Consultar un precio", nullptr));
        pushButton_2->setText(QApplication::translate("W_CONSULTA", "2. Consultar si un producto es de la canasta", nullptr));
        pushButton_3->setText(QApplication::translate("W_CONSULTA", "3. Consultar el % impuesto de un producto", nullptr));
        pushButton_4->setText(QApplication::translate("W_CONSULTA", "4. Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_CONSULTA: public Ui_W_CONSULTA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_CONSULTA_H
