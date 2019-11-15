/********************************************************************************
** Form generated from reading UI file 'w_select.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_SELECT_H
#define UI_W_SELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_SELECT
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_SELECT)
    {
        if (W_SELECT->objectName().isEmpty())
            W_SELECT->setObjectName(QString::fromUtf8("W_SELECT"));
        W_SELECT->resize(321, 242);
        centralwidget = new QWidget(W_SELECT);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 0, 261, 81));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 80, 141, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 80, 141, 31));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 130, 171, 31));
        W_SELECT->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_SELECT);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 321, 21));
        W_SELECT->setMenuBar(menubar);
        statusbar = new QStatusBar(W_SELECT);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        W_SELECT->setStatusBar(statusbar);

        retranslateUi(W_SELECT);

        QMetaObject::connectSlotsByName(W_SELECT);
    } // setupUi

    void retranslateUi(QMainWindow *W_SELECT)
    {
        W_SELECT->setWindowTitle(QApplication::translate("W_SELECT", "MainWindow", nullptr));
        label->setText(QApplication::translate("W_SELECT", "LA CED NO ES CORRECTA SELECCIONE UNA OPCION ", nullptr));
        pushButton->setText(QApplication::translate("W_SELECT", "INTENTAR DE NUEVO", nullptr));
        pushButton_2->setText(QApplication::translate("W_SELECT", "REGISTRARSE", nullptr));
        pushButton_3->setText(QApplication::translate("W_SELECT", "CONSULTAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_SELECT: public Ui_W_SELECT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_SELECT_H
