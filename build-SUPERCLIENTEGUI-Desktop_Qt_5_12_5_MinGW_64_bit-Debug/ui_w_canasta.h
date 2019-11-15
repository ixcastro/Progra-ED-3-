/********************************************************************************
** Form generated from reading UI file 'w_canasta.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_CANASTA_H
#define UI_W_CANASTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_Canasta
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_Canasta)
    {
        if (W_Canasta->objectName().isEmpty())
            W_Canasta->setObjectName(QString::fromUtf8("W_Canasta"));
        W_Canasta->resize(376, 464);
        centralwidget = new QWidget(W_Canasta);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 380, 351, 31));
        W_Canasta->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_Canasta);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 376, 21));
        W_Canasta->setMenuBar(menubar);
        statusbar = new QStatusBar(W_Canasta);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        W_Canasta->setStatusBar(statusbar);

        retranslateUi(W_Canasta);

        QMetaObject::connectSlotsByName(W_Canasta);
    } // setupUi

    void retranslateUi(QMainWindow *W_Canasta)
    {
        W_Canasta->setWindowTitle(QApplication::translate("W_Canasta", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Canasta: public Ui_W_Canasta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_CANASTA_H
