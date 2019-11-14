/********************************************************************************
** Form generated from reading UI file 'ventana.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_H
#define UI_VENTANA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ventana
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *ingresar;
    QPushButton *salir;
    QTextEdit *txtId;
    QLabel *label_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Ventana)
    {
        if (Ventana->objectName().isEmpty())
            Ventana->setObjectName(QString::fromUtf8("Ventana"));
        Ventana->resize(400, 300);
        centralWidget = new QWidget(Ventana);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 340, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(22);
        label->setFont(font);
        ingresar = new QPushButton(centralWidget);
        ingresar->setObjectName(QString::fromUtf8("ingresar"));
        ingresar->setGeometry(QRect(280, 230, 80, 21));
        salir = new QPushButton(centralWidget);
        salir->setObjectName(QString::fromUtf8("salir"));
        salir->setGeometry(QRect(30, 230, 80, 21));
        txtId = new QTextEdit(centralWidget);
        txtId->setObjectName(QString::fromUtf8("txtId"));
        txtId->setGeometry(QRect(180, 110, 161, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HP Simplified Light"));
        font1.setPointSize(12);
        txtId->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 120, 158, 19));
        label_2->setFont(font1);
        Ventana->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Ventana);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Ventana->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Ventana);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Ventana->setStatusBar(statusBar);

        retranslateUi(Ventana);
        QObject::connect(salir, SIGNAL(clicked()), Ventana, SLOT(close()));

        QMetaObject::connectSlotsByName(Ventana);
    } // setupUi

    void retranslateUi(QMainWindow *Ventana)
    {
        Ventana->setWindowTitle(QApplication::translate("Ventana", "Ventana", nullptr));
        label->setText(QApplication::translate("Ventana", "BIENVENIDO ADMINISTRADOR", nullptr));
        ingresar->setText(QApplication::translate("Ventana", "Ingresar", nullptr));
        salir->setText(QApplication::translate("Ventana", "Salir", nullptr));
        label_2->setText(QApplication::translate("Ventana", "Ingrese su identificaci\303\263n:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ventana: public Ui_Ventana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_H
