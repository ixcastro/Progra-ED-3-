/********************************************************************************
** Form generated from reading UI file 'w_cantidad.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_CANTIDAD_H
#define UI_W_CANTIDAD_H

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

class Ui_W_CANTIDAD
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_CANTIDAD)
    {
        if (W_CANTIDAD->objectName().isEmpty())
            W_CANTIDAD->setObjectName(QString::fromUtf8("W_CANTIDAD"));
        W_CANTIDAD->resize(306, 268);
        centralwidget = new QWidget(W_CANTIDAD);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 130, 121, 41));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 80, 171, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 40, 161, 31));
        W_CANTIDAD->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_CANTIDAD);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 306, 21));
        W_CANTIDAD->setMenuBar(menubar);
        statusbar = new QStatusBar(W_CANTIDAD);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        W_CANTIDAD->setStatusBar(statusbar);

        retranslateUi(W_CANTIDAD);

        QMetaObject::connectSlotsByName(W_CANTIDAD);
    } // setupUi

    void retranslateUi(QMainWindow *W_CANTIDAD)
    {
        W_CANTIDAD->setWindowTitle(QApplication::translate("W_CANTIDAD", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("W_CANTIDAD", "COMPRAR", nullptr));
        label->setText(QApplication::translate("W_CANTIDAD", "DIGITE LA CANTIDAD DESEADA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_CANTIDAD: public Ui_W_CANTIDAD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_CANTIDAD_H
