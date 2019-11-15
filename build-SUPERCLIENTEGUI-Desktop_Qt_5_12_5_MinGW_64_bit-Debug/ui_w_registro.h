/********************************************************************************
** Form generated from reading UI file 'w_registro.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_REGISTRO_H
#define UI_W_REGISTRO_H

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

class Ui_W_REGISTRO
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *W_REGISTRO)
    {
        if (W_REGISTRO->objectName().isEmpty())
            W_REGISTRO->setObjectName(QString::fromUtf8("W_REGISTRO"));
        W_REGISTRO->resize(233, 308);
        centralwidget = new QWidget(W_REGISTRO);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 0, 81, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 91, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 80, 41, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 110, 61, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 140, 51, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 170, 51, 16));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 50, 113, 20));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(80, 80, 113, 20));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(80, 110, 113, 20));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(80, 140, 113, 20));
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(80, 170, 113, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 210, 161, 41));
        W_REGISTRO->setCentralWidget(centralwidget);
        menubar = new QMenuBar(W_REGISTRO);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 233, 21));
        W_REGISTRO->setMenuBar(menubar);
        statusbar = new QStatusBar(W_REGISTRO);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        W_REGISTRO->setStatusBar(statusbar);

        retranslateUi(W_REGISTRO);

        QMetaObject::connectSlotsByName(W_REGISTRO);
    } // setupUi

    void retranslateUi(QMainWindow *W_REGISTRO)
    {
        W_REGISTRO->setWindowTitle(QApplication::translate("W_REGISTRO", "MainWindow", nullptr));
        label->setText(QApplication::translate("W_REGISTRO", "REGISTRO ", nullptr));
        label_2->setText(QApplication::translate("W_REGISTRO", "NOMBRE :", nullptr));
        label_3->setText(QApplication::translate("W_REGISTRO", "CED :", nullptr));
        label_4->setText(QApplication::translate("W_REGISTRO", "TELEFONO:", nullptr));
        label_5->setText(QApplication::translate("W_REGISTRO", "CORREO:", nullptr));
        label_6->setText(QApplication::translate("W_REGISTRO", "CIUDAD:", nullptr));
        pushButton->setText(QApplication::translate("W_REGISTRO", "REGISTRAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_REGISTRO: public Ui_W_REGISTRO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_REGISTRO_H
