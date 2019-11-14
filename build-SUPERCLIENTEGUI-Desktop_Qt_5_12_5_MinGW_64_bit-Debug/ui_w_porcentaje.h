/********************************************************************************
** Form generated from reading UI file 'w_porcentaje.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_PORCENTAJE_H
#define UI_W_PORCENTAJE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_PORCENTAJE
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_PORCENTAJE)
    {
        if (W_PORCENTAJE->objectName().isEmpty())
            W_PORCENTAJE->setObjectName(QString::fromUtf8("W_PORCENTAJE"));
        W_PORCENTAJE->resize(474, 373);
        centralwidget = new QWidget(W_PORCENTAJE);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        W_PORCENTAJE->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_PORCENTAJE);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 474, 21));
        W_PORCENTAJE->setMenuBar(menubar);
        statusbar = new QStatusBar(W_PORCENTAJE);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        W_PORCENTAJE->setStatusBar(statusbar);

        retranslateUi(W_PORCENTAJE);

        QMetaObject::connectSlotsByName(W_PORCENTAJE);
    } // setupUi

    void retranslateUi(QMainWindow *W_PORCENTAJE)
    {
        W_PORCENTAJE->setWindowTitle(QApplication::translate("W_PORCENTAJE", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_PORCENTAJE: public Ui_W_PORCENTAJE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_PORCENTAJE_H
