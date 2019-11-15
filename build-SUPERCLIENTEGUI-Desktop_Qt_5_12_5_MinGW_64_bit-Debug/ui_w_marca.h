/********************************************************************************
** Form generated from reading UI file 'w_marca.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_MARCA_H
#define UI_W_MARCA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_MARCA
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_MARCA)
    {
        if (W_MARCA->objectName().isEmpty())
            W_MARCA->setObjectName(QString::fromUtf8("W_MARCA"));
        W_MARCA->resize(367, 463);
        centralwidget = new QWidget(W_MARCA);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 380, 341, 31));
        W_MARCA->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_MARCA);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 367, 21));
        W_MARCA->setMenuBar(menubar);
        statusbar = new QStatusBar(W_MARCA);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        W_MARCA->setStatusBar(statusbar);

        retranslateUi(W_MARCA);

        QMetaObject::connectSlotsByName(W_MARCA);
    } // setupUi

    void retranslateUi(QMainWindow *W_MARCA)
    {
        W_MARCA->setWindowTitle(QApplication::translate("W_MARCA", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_MARCA: public Ui_W_MARCA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_MARCA_H
