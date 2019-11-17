/********************************************************************************
** Form generated from reading UI file 'window_login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_LOGIN_H
#define UI_WINDOW_LOGIN_H

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

class Ui_window_logIn
{
public:
    QWidget *centralwidget;
    QPushButton *ingresar;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_logIn)
    {
        if (window_logIn->objectName().isEmpty())
            window_logIn->setObjectName(QString::fromUtf8("window_logIn"));
        window_logIn->resize(385, 216);
        centralwidget = new QWidget(window_logIn);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ingresar = new QPushButton(centralwidget);
        ingresar->setObjectName(QString::fromUtf8("ingresar"));
        ingresar->setGeometry(QRect(140, 130, 221, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 131, 51));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 341, 31));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 70, 221, 31));
        window_logIn->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_logIn);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 385, 17));
        window_logIn->setMenuBar(menubar);
        statusbar = new QStatusBar(window_logIn);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_logIn->setStatusBar(statusbar);

        retranslateUi(window_logIn);

        QMetaObject::connectSlotsByName(window_logIn);
    } // setupUi

    void retranslateUi(QMainWindow *window_logIn)
    {
        window_logIn->setWindowTitle(QApplication::translate("window_logIn", "MainWindow", nullptr));
        ingresar->setText(QApplication::translate("window_logIn", "Ingresar", nullptr));
        label->setText(QApplication::translate("window_logIn", "Codigo", nullptr));
        label_2->setText(QApplication::translate("window_logIn", "Ingrese el codigo para acceder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_logIn: public Ui_window_logIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_LOGIN_H
